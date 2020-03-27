#include "getter.h"
#include <QByteArray>
/**
 * @brief RJG::asDouble should test if is string or whatever, and can be decently converted to double
 * for now we just convert from string and gg all
 * @param value
 * @return
 */
double RJG::asDouble(const rapidjson::GenericValue<rapidjson::UTF8<>>& value) {
	//value.GetType()
	return QByteArray::fromRawData(value.GetString(), value.GetStringLength()).toDouble();
}
