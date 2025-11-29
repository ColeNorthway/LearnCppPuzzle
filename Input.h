#ifndef INPUT_
#define INPUT_

#include <iostream>


namespace Input
{

	inline void ignoreLine()								//Ignores extra input
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	void printError(char& usrIn);


	inline void checkInput(char& usrIn)						//This will check the input against valid options
	{
		if (usrIn != 'w' &&
			usrIn != 'a' &&
			usrIn != 's' &&
			usrIn != 'd' &&
			usrIn != 'q'  )
		{
			ignoreLine();
			printError(usrIn);
		}

		if (!std::cin)
		{
			std::cin.clear();
			ignoreLine();
			printError(usrIn);								//This ensures that we didn't straight up have a failure
		}
		

		ignoreLine();
		return;
	}


	inline void printError(char& usrIn)						//This will prompt an ask for reentry then rechecks
	{
		std::cout << "That is an invalid input.  Try again: ";
		std::cin >> usrIn;
		
		checkInput(usrIn);
	}

}

#endif
