#pragma once
#include "Fruta.h"
class Manzana : public Fruta
{
public:
	bool isPoisoned;

	virtual Json::Value Code() override;

	virtual void Decode(Json::Value json) override;
};

