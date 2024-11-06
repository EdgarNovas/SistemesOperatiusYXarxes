#pragma once
#include "2InputSystem/InputSystem.h"
#include "Utils/ConsoleControl.h"
class Snake
{
public:
	
	Snake(int left, int right, int up, int down, InputSystem* is, InputSystem::KeyBinding* kb1) {
			

		is->AddListener(left, []() {
			CC::Lock();
			std::cout << " Pressed left" << std::endl;
			CC::Unlock();
			});

		is->AddListener(right, [is,kb1]() {
			CC::Lock();
			std::cout << " Pressed right" << std::endl;
			CC::Unlock();
			});

		is->AddListener(up, [is, kb1]() {
			CC::Lock();
			std::cout << " Pressed up" << std::endl;
			CC::Unlock();
			});

		is->AddListener(down, [is, kb1]() {
			CC::Lock();
			std::cout << " Pressed down" << std::endl;
			CC::Unlock();
			});

		is->StartListen();
	}

};

