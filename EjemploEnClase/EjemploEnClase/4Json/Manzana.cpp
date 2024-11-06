#include "Manzana.h"

Json::Value Manzana::Encode()
{
	Json::Value json = Fruta::Encode();

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
