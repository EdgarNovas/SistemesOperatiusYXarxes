#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
class Answers {
	std::vector<int> answers;
	std::unordered_map<int, bool> answersAdded;
	std::unordered_map<int, bool>::iterator it;
	bool isCorrect;
	int respuesta;
	
public:

	void AddAnswers(int answer, bool isCorrect = false)
	{
		answersAdded.emplace(answer, isCorrect);
	}

	std::vector<int> GetAllPossibleAnswers() {
		
		for (std::unordered_map <int, bool>::iterator it = answersAdded.begin(); it != answersAdded.end(); ++it) {
			answers.push_back(it->first);
			
			//std::cout << "Key: " << it->first << std::endl;
		}

		return answers;
	}

	bool IsCorrectAnswer(int answerChosen)
	{
		it = answersAdded.find(answerChosen);
		
		if (it == answersAdded.end())
		{
			std::cout << "Key-value pair not present in map"; 
			return false;
		}
		else
			std::cout << "Key-value pair present : "
			 << it->second;

		return it->second;
	}


};