#include <iostream>
#include "1TutorialThreads/ThreadTutorial.h"
#include "2InputSystem/InputSystem.h"
#include "Utils/ConsoleControl.h"
#include "3Nodes/Vector2.h"
int main() {
	/*
	InputSystem* is = new InputSystem();

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

	//v = new Vector2(*v2);

	
	//Vector2 v3 = *v + *v2;



}