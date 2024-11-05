#pragma once
#include "ICodable.h"

#include <string>
class Fruta : public ICodable
{
public: 
	unsigned int semillas = 0;
	std::string hexColor = "";


	// Inherited via ICodable
	virtual Json::Value Code() override;

	virtual void Decode(Json::Value json) override;

};

