#pragma once

#include "rapidjson/includeMe.h"

class rapidfunkz {
public:
	//if not found, return a defaul value
	static const rapidjson::GenericValue<rapidjson::UTF8<>>& safeGet(const rapidjson::GenericValue<rapidjson::UTF8<>>& line, const char* name, const rapidjson::GenericValue<rapidjson::UTF8<>>& defaultVal);
	static const rapidjson::GenericValue<rapidjson::UTF8<>> ZeroString;
	static const rapidjson::GenericValue<rapidjson::UTF8<>> EmptyString;
	static const rapidjson::GenericValue<rapidjson::UTF8<>> Zero;
};
