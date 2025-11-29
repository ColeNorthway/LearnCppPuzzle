#ifndef BOARD_
#define BOARD_

#include <ios>
#include <iostream>
#include <utility>
#include "Random.h"
#include "FlatArray.h"

class Board
{
public:
	Board()														//Constructor
	{
		Random::fillArray(m_arr);
	}

	char status() const											//Getter
	{
		return m_status;
	}


	void round(char usrIn)										//Movement logic
	{
		int row = m_coord.first;
		int col = m_coord.second;
		int temp { m_arrV(row, col) };							//Temp var for swap

		switch (usrIn)
		{
		case 'w':
			if (row == 0)
				break;

			m_arrV(row, col) = m_arrV(row - 1, col);			//Setting the old 0 to other val
			m_coord.first -= 1;									//Setting the 0 coord to new
			m_arrV(row - 1, col) = temp;						//Setting old val to 0
			break;
		case 'a':
			if (col == 0)
				break;

			m_arrV(row, col) = m_arrV(row, col - 1);			//Setting the old 0 to other val
			m_coord.second -= 1;								//Setting the 0 coord to new
			m_arrV(row, col - 1) = temp;						//Setting old val to 0
			break;
		case 's':
			if (row == 3)
				break;

			m_arrV(row, col) = m_arrV(row + 1, col);			//Setting the old 0 to other val
			m_coord.first += 1;									//Setting the 0 coord to new
			m_arrV(row + 1, col) = temp;						//Setting old val to 0
			break;
		case 'd':
			if (col == 3)
				break;

			m_arrV(row, col) = m_arrV(row, col + 1);			//Setting the old 0 to other val
			m_coord.second += 1;								//Setting the 0 coord to new
			m_arrV(row, col + 1) = temp;						//Setting old val to 0
			break;
		default :
			break;
		}

		if (checkStatus())
			m_status = 'W';
		print();												//Displaying results
	}


	void print()
	{
		std::cout << "\n\n\n" << std::left;						//Setting the alignment to left

		for (int row { 0 }; row < m_arrV.rows(); ++row)
		{
			for (int col { 0 }; col < m_arrV.cols(); ++col)
			{
				if (m_arrV(row, col) == 0)
					std::cout << std::setw(4) << '_';			//Setw to set the col width for alignment
				else
					std::cout << std::setw(4) << m_arrV(row, col);	
			}
			std::cout << "\n\n";
		}

		std::cout << std::right;								//Resetting alignment to right
	}


	bool checkStatus()											//Checks to see if the array is finished
	{
		for (size_t index { 0 }; index < m_arr.size(); ++index)
		{
			size_t expectedVal { static_cast<size_t>(m_arr[index]) - 1};

			if ((index != expectedVal) && (index != 15))		//Checking values before last
				return false;
			else if ((index == 15) && (m_arr[15] != 0))			//Last val == 0
				return false;
		}
		return true;
	}
	
private:
	ArrayFlat2d<int, 4, 4> m_arr    {};
	ArrayView2d<int, 4, 4> m_arrV   { m_arr };
	char                   m_status { 'L' };
	std::pair<int, int>    m_coord  { 0, 0 };
};

#endif
