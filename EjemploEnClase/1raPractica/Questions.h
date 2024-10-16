#pragma once
#include <vector>
#include <string>
#include "Answers.h"
class Question {
	std::string question;
	Answers answers;
	int currentIndex;
public:

	//NEW P(STD,OK,[]RESPOTES NO OK)

	Question(std::string questions, int realAnswer, std::vector<int> falseAnswers)
	{
		AddQuestion(questions,realAnswer,falseAnswers);
	}

	Question() {

	}


	void AddQuestion(std::string questions,int realAnswer ,std::vector<int> falseAnswers)
	{
		question = questions;
		answers.AddAnswers(realAnswer, true);
		for (int falseAnswer : falseAnswers)
		{
			answers.AddAnswers(falseAnswer);
		}
	}
private:
	void AddAnswers(std::unordered_map<int,bool> map)
	{
		//
		std::unordered_map<int, int> m;
		std::vector<int> key, value;
		for (std::unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			
			answers.AddAnswers(it->first, it->second);
			//std::cout << "Key: " << it->first << std::endl;
			
		}
		//
	}
public:
	void SelectQuestion(int number)
	{
		if (answers.IsCorrectAnswer(number))
		{
			std::cout << "Bieeen acertaste" << std::endl;
		}
		else
		{
			std::cout << "Fallaste Pajaso de inutil" << std::endl;
		}
	}

	void ShowAnswers()
	{
		ShowQuestion();
		int contador = 1;
		for (int answers : answers.GetAllPossibleAnswers())
		{
			std::cout  <<" R" << contador << " -> " << answers << std::endl;
			contador++;
		}
	}

	void ShowQuestion()
	{
		std::cout << question << std::endl;
	}
};