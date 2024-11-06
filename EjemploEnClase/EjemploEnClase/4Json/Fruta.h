#pragma once
#include "ICodable.h"
#include <string>
class Fruta :	public ICodable
{
public:
	unsigned int semillas; 
	std::string hexColor = "";

	virtual Json::Value Encode() override;
	virtual void Decode(Json::Value json) override;
};

