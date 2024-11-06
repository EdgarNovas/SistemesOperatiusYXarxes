#pragma once
#include <iostream>
#include<chrono>
#include <thread>
#include <mutex>
#include <string>
#include <list>

#pragma region Functions Declarations Header
void PrintElapsedTime(std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName);



void Count(unsigned long long maxCounter, std::string threadName);

void Example01();
void Example02();
void Example03();
void Example04();

void Example05();
void Example06();
/*
void Example07();
*/

#pragma endregion


#pragma region Global Variables

std::chrono::system_clock::time_point startDate;

std::mutex consoleMutex;
#pragma endregion

void ThreadTutorialTest()
{
	startDate = std::chrono::system_clock::now();

	int exampleUsed = 6;

	switch (exampleUsed)
	{
	case 1:
		Example01();
		break;
		
	case 2:
		Example02();
		break;
		
	case 3:
		Example03();
		break;
		
	case 4:
		Example04();
		break;
		
	case 5:
		Example05();
		break;
		
	case 6:
		Example06();
		break;
		/*
	case 7:
		Example07();
		break;
		*/
	default:
		break;
	}

	std::cout << "Example 0" << exampleUsed << " finished " << std::endl;

	std::string text = "";
	std::getline(std::cin, text);
}

/// <summary>
/// Print Elapsed Time
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
/// <param name="threadName"></param>
void PrintElapsedTime(std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName)
{
	std::chrono::duration<double> elapsedTime = end - start;
	//TODO nada por ahora
	consoleMutex.lock();
	std::cout << "Thread " << threadName << " - Elapsed Time: " << elapsedTime.count() << " seconds" << std::endl;
	consoleMutex.unlock();
	//TODO NADA POR AHORA
}



void Count(unsigned long long maxCounter, std::string threadName)
{
	
	for (unsigned long long i = 0; i < maxCounter; i++)
	{

	}

	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintElapsedTime(startDate, endDate, threadName);
	
}

void Example01()
{
	unsigned long long totalCount = 1000000000ull;

	//Sempre amb punter
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	//SOLO SE DETIENE EL CODIGO SI TODOS LOS THREADS SE ESTAN EJECUTANDO 
	//Y ALMENOS DE ELLOS 1 ES UN DETACH O UN JOIN Y LOS OTROS EL OTRO
	Counter1->join();
	Counter2->join();
	Counter3->join();


	Count(totalCount, "0");
}


void Example02() {

	unsigned long long totalCount = 1000000000ull;

	//Sempre amb punter
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");
	Counter1->join();

	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	//SOLO SE DETIENE EL CODIGO SI TODOS LOS THREADS SE ESTAN EJECUTANDO 
	//Y ALMENOS DE ELLOS 1 ES UN DETACH O UN JOIN Y LOS OTROS EL OTRO

	
	Counter2->join();
	Counter3->join();


	Count(totalCount, "0");

}


void Example03()
{
	unsigned long long totalCount = 1000000000ull;

	//Sempre amb punter
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	//SOLO SE DETIENE EL CODIGO SI TODOS LOS THREADS SE ESTAN EJECUTANDO 
	//Y ALMENOS DE ELLOS 1 ES UN DETACH O UN JOIN Y LOS OTROS EL OTRO
	Counter1->detach();
	Counter2->detach();
	Counter3->detach();


	Count(totalCount, "0");
}

void Example04()
{
	std::list<std::thread*>* threads = new std::list<std::thread*>();
	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i <3; i++)
	{
		std::thread* counterThread = new std::thread(Count,totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
		counterThread->join();
	}

	Count(totalCount, "0");
}

void Example05() {

	std::list<std::thread*>* threads = new std::list<std::thread*>();
	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i < 3; i++)
	{
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
		counterThread->detach();
	}

	Count(totalCount, "0");


	//IF (TODOS EJECUTADOS && ALGUN ES JOIN)
	//{
	// ME PARO!!
	//}
}


void Example06()
{
	unsigned int maxThreads = std::thread::hardware_concurrency();
	std::cout << maxThreads << " concurrent threads are supported." << std::endl;


	
	int extraThreads = +12;
	std::list<std::thread*>* threads = new std::list<std::thread*>();
	unsigned long long totalCount = 1000000000ull;

	int sum = maxThreads + extraThreads;

	for (int i = 0; i < sum; i++)
	{
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
	}

	for (std::thread* t : *threads) {

		t->join();

	}

	Count(totalCount, "0");

}

void Example07()
{

}