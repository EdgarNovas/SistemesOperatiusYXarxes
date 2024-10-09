#pragma once
#include "InputsConsts.h"
#include <functional>
#include <thread>
#include <mutex>
#include <map>
#include <list>

class InputSystem
{
public:

	//Es una clase que utilitza InputSystem pero ens interesa poder accedir despres a ella des de fora
	class KeyBinding {
		//friend class -> podra accedir a les funcions del KeyBinding encara que sigui privat
		friend class InputSystem;
	public:
		//typedef -> definir un nou nom a un tipus de variables
		//Funcio Lambda -> Es una funcio que declarem a la mitat del codi
		// //Ex: If AddListener(Space, jump ||)
		//Fa que despres no s'hagi descriure std::function<void()> OnKeyPress una altre vegada al utilitzar OnKeyPress
		typedef std::function<void()> OnKeyPress;
	private:
		int _key;
		//Gracies al typedef no s'ha d'escriure std::function<void()>
		OnKeyPress _onKeyPress;
		
		KeyBinding(int key, OnKeyPress onKeyPress);
		~KeyBinding();
	};

	typedef std::list<KeyBinding*> KeyBindingList;
	typedef std::map<int, KeyBindingList> KeyBindingMap;

public:
	InputSystem();
	~InputSystem();

	KeyBinding* AddListener(int key, KeyBinding::OnKeyPress onKeyPress);

	void RemoveAndDeleteListener(KeyBinding* keyBinding);


	void AddListenerAsync(int key, KeyBinding::OnKeyPress onKeyPress);

	void RemoveAndDeleteListenerAsync(KeyBinding* keyBinding);



	void StartListen();
	void StopListen();

private:

	std::mutex _classMutex;
	KeyBindingMap _keyBindingsMap;

	enum State
	{
		Starting = 0,
		Listening = 1,
		Stopping = 2,
		Stopped = 3
	};

	State _state = Stopped;

	void ListenLoop();
};

