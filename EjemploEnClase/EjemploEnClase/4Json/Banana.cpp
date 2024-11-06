#include "Banana.h"

Json::Value Banana::Code()
{
    Json::Value json = Fruta::Code();
    json["sex"] = sex;
    //json[GetDecodeKey()] = typeid(Banana).name();
    CodeSubClassType<Banana>(json);
    //<-----
    return json;
}

void Banana::Decode(Json::Value json)
{
    Fruta::Decode(json);
    sex = (Sexo)json["sex"].asInt();
    //<-------

}
