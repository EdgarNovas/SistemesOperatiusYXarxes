#include "Manzana.h"

Json::Value Manzana::Code()
{
	Json::Value json = Fruta::Code();
	json["isPoisoned"] = isPoisoned;
	//json[GetDecodeKey()] = typeid(Manzana).name();
	CodeSubClassType<Manzana>(json);
	return json;
}

void Manzana::Decode(Json::Value json)
{
	Fruta::Decode(json);
	isPoisoned = json["isPoisoned"].asBool();
}
