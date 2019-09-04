#include "safeGet.h"

rapidjson::GenericValue<rapidjson::UTF8<>> zeroStringInit() {
	rapidjson::GenericValue<rapidjson::UTF8<>> v;
	v.SetString("0");
	return v;
}

rapidjson::GenericValue<rapidjson::UTF8<>> emptyStringInit() {
	rapidjson::GenericValue<rapidjson::UTF8<>> v;
	v.SetString("");
	return v;
}

rapidjson::GenericValue<rapidjson::UTF8<>> zeroInit() {
	rapidjson::GenericValue<rapidjson::UTF8<>> v;
	v.SetDouble(0);
	return v;
}

const rapidjson::GenericValue<rapidjson::UTF8<>> rapidfunkz::ZeroString  = zeroStringInit();
const rapidjson::GenericValue<rapidjson::UTF8<>> rapidfunkz::EmptyString = emptyStringInit();
const rapidjson::GenericValue<rapidjson::UTF8<>> rapidfunkz::Zero        = zeroInit();

const rapidjson::GenericValue<rapidjson::UTF8<>>& rapidfunkz::safeGet(const rapidjson::GenericValue<rapidjson::UTF8<>>& line, const char* name, const rapidjson::GenericValue<rapidjson::UTF8<>>& defaultVal) {
	auto iter = line.FindMember(name);
	if (iter == line.MemberEnd()) {
		return defaultVal;
	}
	return iter->value;
}
