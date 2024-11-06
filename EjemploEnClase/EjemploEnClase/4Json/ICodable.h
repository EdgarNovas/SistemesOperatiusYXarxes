#pragma once
#include <json/json.h>
#include <string>
class ICodable
{
public:

	

private:



public:
	static std::string GetDecodeKey();

	virtual Json::Value Code() = 0;
	virtual void Decode(Json::Value json) = 0;

};

