#include "various.h"

using namespace rapidjson;
QString printType(rapidjson::Type t) {
	switch (t) {
	case Type::kNullType:
		return "null";
		break;
	case Type::kFalseType:
		return "bool (false)";
		break;
	case Type::kTrueType:
		return "bool (true)";
		break;
	case Type::kObjectType:
		return "object";
		break;
	case Type::kArrayType:
		return "array";
		break;
	case Type::kStringType:
		return "string";
		break;
	case Type::kNumberType:
		return "number";
		break;
	}
	return QString("unsupported type");
}
