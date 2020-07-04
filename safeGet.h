#pragma once

#include "rapidjson/includeMe.h"
#include "various.h"
#include <QByteArray>
#include <QString>

class rapidfunkz {
      public:
	//if not found, return a defaul value
	static const rapidjson::GenericValue<rapidjson::UTF8<>>& safeGet(const rapidjson::GenericValue<rapidjson::UTF8<>>& line, const char* name, const rapidjson::GenericValue<rapidjson::UTF8<>>& defaultVal);
	static const rapidjson::GenericValue<rapidjson::UTF8<>>  ZeroString;
	static const rapidjson::GenericValue<rapidjson::UTF8<>>  EmptyString;
	static const rapidjson::GenericValue<rapidjson::UTF8<>>  ZeroDouble;
	static const rapidjson::GenericValue<rapidjson::UTF8<>>  ZeroInt;
	//IS ARRAY IS complex and annoyng
};

typedef rapidjson::GenericValue<rapidjson::UTF8<>> jsonValue;
class JSafe : public jsonValue {
      public:
	template <typename V>
	V sfGet(const char* key) const {
		static_assert(std::is_arithmetic<V>::value, "This function can be used only for aritmetic types");
		auto iter = this->FindMember(key);
		if (iter != this->MemberEnd()) {
			const auto& value = iter->value;
			auto        type  = value.GetType();
			switch (type) {
			case rapidjson::Type::kNumberType:
				return value.Get<V>();
			case rapidjson::Type::kStringType: {
				bool   ok;
				double res;
				auto   qb = QByteArray::fromRawData(value.GetString(), value.GetStringLength());
				if constexpr (std::is_floating_point<V>::value) {
					res = qb.toDouble(&ok);
				}else if constexpr (std::is_signed<V>::value) {
					res = qb.toLongLong(&ok);
				} else {
					res = qb.toULongLong(&ok);
				}

				if (!ok) {
					throw QString("%1 is not an int, or directly convertible in an aritmetic type, it is a string %2").arg(key).arg(QString(qb));
				}
				return res;
			}
			default:
				throw QString("%1 is not an int, or directly convertible in an aritmetic type,, it is a %2").arg(key).arg(printType(type));
			}
		} else {
			return 0;
		}
	}
};

//standalone
template <typename K>
K jsonGet(const jsonValue& line, const char* key) {
	const JSafe& j2 = static_cast<const JSafe&>(line);
	return j2.sfGet<K>(key);
}
