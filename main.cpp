#include <ios>
#include <iostream>
#include "Board.h"
#include "Input.h"


int main()
{
	char usrIn  {};											//The userinput char
	Board board {};											//Main board obj

	std::cout << "Welcome to my puzzle! (wasd to move and q to quit)\n\n\n";

	while ((usrIn != 'q') && (board.status() != 'W'))		//The main loop stop on q or success
	{
		std::cout << "> ";
		std::cin  >> usrIn;
		Input::checkInput(usrIn);							//Checking the userinput and validating

		board.round(usrIn);									//Doing a round
	}

	if (usrIn == 'q')
		std::cout << "Congrats!!!!!";
}
