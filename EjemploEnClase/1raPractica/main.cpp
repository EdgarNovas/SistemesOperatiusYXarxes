#include "2InputSystem/InputSystem.h"

#include "Questions.h"
#include "QuestionManager.h"
#include "Utils/ConsoleControl.h"
#include "Timer.h"
int main()
{
	std::vector<int> addAnswers;
	Question question;
	addAnswers.push_back(150);
	addAnswers.push_back(50);
	addAnswers.push_back(10);
	Timer timer;
	Question questionNew("Cuantos dedos hay en un pie ? ", 5, addAnswers);
	Question question2("Cuantos ojos hay en una cara humana ? ", 2, addAnswers);

	QuestionManager manager;
	question2.ShowAnswers();
	int tecla = 50;
	do
	{
		CC::Lock();
		CC::SetColor(CC::BLUE);
		std::cout << "Escoje una respuesta, 1,2,etc... " << std::endl;
		CC::SetColor(CC::WHITE);
		
		CC::Unlock();
		std::cin >> tecla;
		question2.SelectQuestion(tecla > 0 ? --tecla : tecla );
		
		//questionNew.SelectQuestion(tecla > 0 ? --tecla : tecla );
	} while (tecla == 50);
	
	return 0;
}