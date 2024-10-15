#include "2InputSystem/InputSystem.h"

#include "Questions.h"
#include "QuestionManager.h"
int main()
{
	std::vector<int> addAnswers;
	Question question;
	addAnswers.push_back(100);
	addAnswers.push_back(50);
	addAnswers.push_back(10);


	question.AddQuestion("Cuantos dedos hay en una mano?",5,addAnswers);

	question.ShowAnswers();
	
	
	return 0;
}