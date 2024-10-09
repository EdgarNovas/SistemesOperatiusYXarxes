#include "InputSystem.h"
#include"../Utils/ConsoleControl.h"

InputSystem::KeyBinding::KeyBinding(int key, OnKeyPress onKeyPress)
{
	_key = key;
	_onKeyPress = onKeyPress;
}

InputSystem::KeyBinding::~KeyBinding()
{
}

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
	for (std::pair<int, KeyBindingList> pair : _keyBindingsMap)
	{
		KeyBindingList bindingList = pair.second;

		for (KeyBinding* binding : bindingList)
		{
			delete binding;
		}
	}
	_keyBindingsMap.clear();
}

InputSystem::KeyBinding* InputSystem::AddListener(int key, KeyBinding::OnKeyPress onKeyPress)
{
	_classMutex.lock();
	if (_keyBindingsMap.find(key) == _keyBindingsMap.end()) {//Si arriba aqui es que no ho ha trobat
		//Fan el mateix
		//_keyBindings[key] = std::list<KeyBinding*>();
		_keyBindingsMap[key] = KeyBindingList();
	}

	KeyBinding* keyBinding = new KeyBinding(key, onKeyPress);
	_keyBindingsMap[key].push_back(keyBinding);

	_classMutex.unlock();

	return keyBinding;
}

void InputSystem::RemoveAndDeleteListener(KeyBinding* keyBinding)
{
	int key = keyBinding->_key;
	_classMutex.lock();

	if (_keyBindingsMap.find(key) != _keyBindingsMap.end())
	{
		//Estic fent la busqueda 2 vegades no es optim
		//En el if y dins del if
		KeyBindingList list = _keyBindingsMap[key];
		list.remove(keyBinding);
		delete keyBinding;

		if (list.size() <= 0)
		{
			_keyBindingsMap.erase(key);
		}

	}
	


	_classMutex.unlock();

}

void InputSystem::AddListenerAsync(int key, KeyBinding::OnKeyPress onKeyPress)
{
	std::thread* addListenerThread = new std::thread(&InputSystem::AddListener,this,key,onKeyPress);
	addListenerThread->detach();
}

void InputSystem::RemoveAndDeleteListenerAsync(KeyBinding* keyBinding)
{
	std::thread* removeListenerThread = new std::thread(&InputSystem::RemoveAndDeleteListener, this,keyBinding);
	removeListenerThread->detach();
}

void InputSystem::StartListen()
{
	_classMutex.lock();

	if (_state != Stopped)
	{
		_classMutex.unlock();
		return;
	}

	_state = Starting;

	std::thread* listenLoopThread = new std::thread(&InputSystem::ListenLoop, this);
	listenLoopThread->detach();

	_classMutex.unlock();
}

void InputSystem::StopListen()
{
	_classMutex.lock();

	if (_state != Listening)
	{
		_classMutex.unlock();
		return;
	}

	_state = Stopping;

	


	_classMutex.unlock();

}

void InputSystem::ListenLoop()
{
	_classMutex.lock();
	_state = Listening;

	State currentState = _state;
	CC::Lock();
	CC::ClearKeyBuffer();
	CC::Unlock();
	_classMutex.unlock();

	while (currentState == Listening)
	{
		int key = CC::ReadNextKey();

		if (key != 0)
		{
			_classMutex.lock();
			KeyBindingMap::iterator it = _keyBindingsMap.find(key);
			if (it != _keyBindingsMap.end())
			{
				KeyBindingList list = it->second;

				for (KeyBinding* binding : list)
				{
					//Si esto te tuvieras que ir a hacer las cosas 
					//Como el mutex esta bloqueado y luego bloqueamos otra vez
					//habria un dead lock(muerte por lock)
					//binding->_onKeyPress();
					//Con un thread esto no pasara porque el detach
					// se ejecuta en otro sitio y espera a que acabe
					std::thread* onkeyPressThread = new std::thread(binding->_onKeyPress);
					onkeyPressThread->detach();
				}
			}

			_classMutex.unlock();
		}
		_classMutex.lock();
		currentState = _state;
		_classMutex.unlock();

	}

	_classMutex.lock();
	if (_state == Stopping)
	{
		_state = Stopped;
	}

	_classMutex.unlock();
}
