#pragma once
#include "Fruta.h"
class Banana : public Fruta
{
public:
	enum Sexo
	{
		Macho = 0,
		Hembra = 1
	};
	Sexo sex = Hembra;

	virtual Json::Value Code() override;

	virtual void Decode(Json::Value json) override;
};

