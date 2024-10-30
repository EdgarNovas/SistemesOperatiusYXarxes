#include <iostream>
#include "1TutorialThreads/ThreadTutorial.h"
#include "2InputSystem/InputSystem.h"
#include "Utils/ConsoleControl.h"
#include "3Nodes/Vector2.h"
#include "Snake.h"
#include "3Nodes/NodeMap.h"
#include <json/json.h>
#include <string>
#include <fstream>

class Player
{
public:
	int life = 0;
	std::string name = "Test Player";
	unsigned int coins = 0;

	Player();
	~Player();
	
	//De un json leo las variables que me interesan y las asigno a esta clase
	void Decode(Json::Value json)
	{
		life = json["life"].asInt();
		name = json["name"].asString();
		coins = json["coins"].asUInt();
	}

	//A partir de esta clase creo un json rellenado con las variables de la clase
	Json::Value Encode()
	{
		Json::Value json;

		json["life"] = life;
		json["name"] = name;
		json["coins"] = coins;

		return json;
	}

	static Player* FromJSON(Json::Value json)
	{
		Player* player = new Player();
		player->Decode(json);
		return player;
	}

private:

};

Player::Player()
{
}

Player::~Player()
{
}

int main() {
	
	Player* player = new Player();

	player->coins = 5;
	player->life = 50;
	player->name = "Capitan Test";

	Json::Value newJson;

	newJson["Player"] = player->Encode();

	std::ofstream* jsonWriteFile = new std::ofstream("PlayerParseTest.json", std::ifstream::binary);
	if (!jsonWriteFile->fail())
	{
		//*jsonWriteFile << newJson;
		// Si lo haces de esta manera deberas hacer esto para poder leer el Jason
		//Player* readedPlayer = Player::FromJSON(readedJson["Player]);
		//Esto es porque estas haciendo un jason que tiene un player dentro

		*jsonWriteFile << player->Encode();
		jsonWriteFile->close();
		delete jsonWriteFile;

	}

	InputSystem* is = new InputSystem();
	InputSystem::KeyBinding* kb1 = nullptr;
	/*
	InputSystem::KeyBinding* kb1 = is->AddListener(K_1, []() {
		CC::Lock();
		std::cout << " Pressed 1" << std::endl;
		CC::Unlock();
	});
	//LO QUE HAY ENTRE [] ES LA INFORMACION QUE 
	// QUIERES PASAR DE FUERA A DENTRO
	//YA QUE ES UN ESPACIO DE MEMORIA DISTINTO
	//DENTRO DE LA LAMBDA
	//Lo que hay dentro de
	is->AddListener(K_0, [is,kb1]() {
		is->RemoveAndDeleteListenerAsync(kb1);
	});


	is->AddListener(K_2, []() {
		CC::Lock();
		std::cout << " Pressed 2" << std::endl;
		CC::Unlock();
		});

	is->StartListen();
	while (true)
	{

	}
	
	*/

	/*
	Vector2* v = new Vector2(40, 56);
	Vector2* v2 = new Vector2(4, 6);


	Snake* snake1 = new Snake(K_A, K_D, K_W, K_S,is,kb1);

	Vector2 size(10, 10);

	Vector2 offset(5, 5);
	NodeMap nodeMap(size, offset);

	nodeMap.UnSafeDraw();
	*/

	std::cout << "Finished Write";

	std::ifstream* jsonReadFile = new std::ifstream("PlayerParseTest.json", std::ifstream::binary);

	if (!jsonReadFile->fail())
	{
		Json::Value readedJson;
		*jsonReadFile >> readedJson;
		jsonReadFile->close();
		delete jsonReadFile;

		Player* readedPlayer = Player::FromJSON(readedJson);
	}

	std::cout << "Finished Read";
	while (true)
	{

	}
	
	//v = new Vector2(*v2);

	
	//Vector2 v3 = *v + *v2;



}