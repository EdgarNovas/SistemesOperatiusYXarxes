#pragma once
#include "Fruta.h"
class Manzana :	public Fruta
{
public:
	bool isPoisoned;

	virtual Json::Value Encode() override;
	virtual void Decode(Json::Value json) override;
};

