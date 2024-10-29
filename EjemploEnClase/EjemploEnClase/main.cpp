#include <iostream>
#include "1TutorialThreads/ThreadTutorial.h"
#include "2InputSystem/InputSystem.h"
#include "Utils/ConsoleControl.h"
#include "3Nodes/Vector2.h"
#include "Snake.h"
#include "3Nodes/NodeMap.h"
int main() {
	
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

	Vector2* v = new Vector2(40, 56);
	Vector2* v2 = new Vector2(4, 6);


	Snake* snake1 = new Snake(K_A, K_D, K_W, K_S,is,kb1);

	Vector2 size(10, 10);

	Vector2 offset(5, 5);
	NodeMap nodeMap(size, offset);

	nodeMap.UnSafeDraw();

	while (true)
	{

	}
	//v = new Vector2(*v2);

	
	//Vector2 v3 = *v + *v2;



}