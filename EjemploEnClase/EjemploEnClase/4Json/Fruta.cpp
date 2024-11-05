#include "Fruta.h"

Json::Value Fruta::Code()
{
	Json::Value json = Json::Value();

	json["semillas"] = semillas;
	json["hexColor"] = hexColor;

	return json;
}

void Fruta::Decode(Json::Value json)
{
	semillas = json["semillas"].asUInt();
	hexColor = json["hexColor"].asString();

}
