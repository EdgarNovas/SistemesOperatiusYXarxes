#pragma once
#include <json/json.h>
#include <string>

#include <functional>
#include<map>
class ICodable
{
public:

	typedef std::function<ICodable* ()>SubClassDecode;
	typedef std::map< std::string, SubClassDecode> DecodeMap;

private:

	static DecodeMap* GetDecodeMap();
	static void SaveDecodeProcess(std::string className, SubClassDecode decodeProcess);
public:
	static std::string GetDecodeKey();

	
	//Enable if :: nomes me la activas
	//Base of nomes si es de aquesta classe
	template<typename T, typename = typename std::enable_if<std::is_base_of<ICodable, T>::value>::type>
	static void SaveDecodeProcess()
	{
		ICodable::SaveDecodeProcess(typeid(T).name(), []() {return new T(); });
	}

	template<typename T, typename = typename std::enable_if<std::is_base_of<ICodable, T>::value>::type>
	void CodeSubClassType(Json::Value& json)
	{
		json[GetDecodeKey()] = typeid(T).name();
	}

	virtual Json::Value Code() = 0;
	virtual void Decode(Json::Value json) = 0;

	template<typename T, typename = typename std::enable_if<std::is_base_of<ICodable, T>::value>::type>
	static T* FromJson(Json::Value json)
	{
		std::string className = json[GetDecodeKey()].asString();

		ICodable* codable = (*GetDecodeMap())[className]();

		T* codableCasted = dynamic_cast<T*>(codable);

		codable->Decode(json);

		return codableCasted;
	}

};

