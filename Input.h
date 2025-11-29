#ifndef INPUT_
#define INPUT_

#include <iostream>


namespace Input
{

	inline void ignoreLine()								//Ignores extra input
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	inline void checkInput(char& usrIn)						//This will check the input against valid options
	{
		while (true)
		{
			if (!std::cin)
			{
				std::cin.clear();
				ignoreLine();
				std::cout << "That is an invalid input.  Try again: ";
				std::cin >> usrIn;
				continue;
			}

			if (usrIn != 'w' &&
				usrIn != 'a' &&
				usrIn != 's' &&
				usrIn != 'd' &&
				usrIn != 'q'  )
			{
				ignoreLine();
				std::cout << "That is an invalid input.  Try again: ";
				std::cin >> usrIn;
			}
			else 
			{
				ignoreLine();
				return;
			}
		}
	}
}

#endif
