#ifndef RANDOM_
#define RANDOM_

#include <array>
#include <cstddef>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>


namespace Random
{
	inline std::mt19937_64 getSeed()
	{
		std::random_device rd{};

		std::seed_seq ss
		{
			static_cast<std::seed_seq::result_type>(
				std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd()
		};

		return std::mt19937_64{ ss };
	}


	inline std::mt19937_64& mt()
	{
		static std::mt19937_64 generator { getSeed() };

		return generator;
	}


	inline size_t get()
	{
		return std::uniform_int_distribution<size_t> { 1, 15 }( mt() );
	}


	inline void fillArray(std::array<int, 16>& arr)
	{
		arr[0] = 0;														//Ensure that the first index is the empty one
		
		std::vector<int> 	   numVals     { 1,  2,  3,  4,  5,			// The array that tracks the values to assign to arr
						                     6,  7,  8,  9,  10,
						                     11, 12, 13, 14, 15 };

		std::array<size_t, 15> assndIndexs { 0, 0, 0, 0, 0,				// The array that tracks the indexes that have been assigned val
											 0, 0, 0, 0, 0,
											 0, 0, 0, 0, 0 };

		while (!numVals.empty())
		{
			size_t index { get() };										//Getting random index
			auto result { std::find(assndIndexs.begin(), assndIndexs.end(), index) };
			while (result != assndIndexs.end())							//If index isn't == end which means its found, get another thats not alr assn
			{
				index = get();
				result = std::find(assndIndexs.begin(), assndIndexs.end(), index);
			}
			
			assndIndexs[index-1] = index;									//Assigning that index to the list of alr assn
			
			arr[index] = numVals.back();								//Assigning a number to arr
			numVals.pop_back();											//Removing number from numVals

		}
	}
}

/*
	namespace Random : Will generate the random numbers ----------------------
		> Will have a special function to populate the 2d array passed as a ref
		> This function will have a loop and two arrays
		> The first array will be a sorted std::vector of 1-15
			> This is for the numbers to populate
			> Called numVals
		> The second array will be an array of indexes that have been assigned values
			> Called assndIndexs
			> Predetermined len array of len 15
			> Loaded with value 0
		> The function will pick a random index on the flattened array from 1-15 (ignoring 0 as that is empty)
			> It will use a find algorithm to see if the index is in assndIndexes
				> Use a lambda to pass to the alg if needed
			> If the index isn't in there it will reget another index
				> If the index isn't already in assndIndexes it will break the loop
			> Then it will place the back number of numVals into that index
			> Then it will pop that back of numVals
			> Then it will place that index into assndIndexes

*/

#endif
