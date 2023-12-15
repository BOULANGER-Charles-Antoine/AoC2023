#include "Day9.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

#include "Utils.h"

using namespace std;

int32_t Day9::Puzzle(std::string InputName)
{
	ifstream InputFile{ InputName, ios::in }; 
	if (InputFile.is_open())
	{
		int32_t Sum{};
		string Line;

		while (!InputFile.eof())
		{
			getline(InputFile, Line);
			Sum += FindPreviousValue(Line);
		}

		return Sum;
	}
	else
	{
		cout << "Error, file not opened !";
	}

	return 0;
}

int32_t Day9::FindNextValue(std::string LineInput)
{
	if (!LineInput.empty())
	{
		std::vector<int32_t> Numbers;

		istringstream StringStream{ LineInput };
		while (!StringStream.eof())
		{
			int32_t Number = 0;
			StringStream >> Number;
			Numbers.push_back(Number);
		}

		return CalculateNextValue(Numbers);
	}

	return 0;
}

int32_t Day9::FindPreviousValue(std::string LineInput)
{
	if (!LineInput.empty())
	{
		std::vector<int32_t> Numbers;

		istringstream StringStream{ LineInput };
		while (!StringStream.eof())
		{
			int32_t Number = 0;
			StringStream >> Number;
			Numbers.push_back(Number);
		}

		return CalculatePreviousValue(Numbers);
	}

	return 0;
}

int32_t Day9::CalculateNextValue(std::vector<int32_t> Numbers)
{
	int NB_Number = Numbers.size() - 1;
	int32_t Sum = 0;

	for (int i = 1; i != NB_Number; ++i)
	{
		Sum += COEFFICIENTS[NB_Number][i-1] * Numbers[i];
	}

	return  NB_Number * Numbers.back() + Sum;
}

int32_t Day9::CalculatePreviousValue(std::vector<int32_t> Numbers)
{
	int NB_Number = Numbers.size() - 1;
	int32_t Sum = 0;

	for (int i = 1; i != NB_Number; ++i)
	{
		Sum += COEFFICIENTS[NB_Number][i - 1] * Numbers[NB_Number - i];
	}

	return  NB_Number * Numbers.front() + Sum;
}
