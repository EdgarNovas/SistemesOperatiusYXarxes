#pragma once
#include "Answers.h"
#include "Questions.h"
class QuestionManager
{
	std::vector<Question> questions;
public:

	void ShowAnswers(int i)
	{
		questions[i].ShowAnswers();
	}

	void SelectAnswer(int i, int answer)
	{
		questions[i].SelectQuestion(answer);
	}


	void AddQuestionToList(Question question)
	{
		questions.push_back(question);
	}
	

};
