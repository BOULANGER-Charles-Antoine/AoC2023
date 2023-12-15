#include "Day1.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

template<>
int32_t Day1::Puzzle<Puzzle1>(std::string InputName)
{
	ifstream InputFile{ InputName, ios::in };
	if (InputFile.is_open())
	{
		int32_t Sum{};
		string Line;

		while (!InputFile.eof())
		{
			getline(InputFile, Line);
			Sum += FindCalibrationValue<Puzzle1>(Line);
		}

		return Sum;
	}
	else
	{
		cout << "Error, file not opened !";
	}

	return 0;
}

template<>
int32_t Day1::Puzzle<Puzzle2>(std::string InputName)
{
	ifstream InputFile{ InputName, ios::in };
	if (InputFile.is_open())
	{
		int32_t Sum{};
		string Line;

		while (!InputFile.eof())
		{
			getline(InputFile, Line);
			Sum += FindCalibrationValue<Puzzle2>(Line);
		}

		return Sum;
	}
	else
	{
		cout << "Error, file not opened !";
	}

	return 0;
}

template<>
int16_t Day1::FindCalibrationValue<Puzzle1>(std::string Line)
{
	int32_t Unit = FindLastOccurence(Line, Day1::Number).second;
	int32_t Decimal = FindFirstOccurence(Line, Day1::Number).second;

	return Decimal * 10 + Unit;
}

template<>
int16_t Day1::FindCalibrationValue<Puzzle2>(std::string Line)
{
	int32_t Unit = FindLastOccurence(Line);
	int32_t Decimal = FindFirstOccurence(Line);

	return Decimal * 10 + Unit;
}

size_t Day1::FindFirstOccurence(string Line)
{
	auto [NumberPosition, Number] = FindFirstOccurence(Line, Day1::Number);
	auto [StringNumberPosition, StringNumber] = FindFirstOccurence(Line, Day1::StringNumber);

	if (Number == 0 && StringNumber == 0)
	{
		return 0;
	}

	if (Number == 0)
	{
		return StringNumber;
	}

	if (StringNumber == 0)
	{
		return Number;
	}

	return NumberPosition < StringNumberPosition ? Number : StringNumber;
}

std::pair<size_t, int32_t> Day1::FindFirstOccurence(string Line, std::vector<std::string> Substr)
{
	size_t BestPosition = std::numeric_limits<size_t>::max();
	int32_t Number{};

	for (int i = 0; i != Substr.size(); ++i) 
	{
		if(size_t Position = Line.find(Substr[i]); Position != string::npos && Position <= BestPosition)
		{
			BestPosition = Position;
			Number = i + 1;
		}
	}

	return { BestPosition, Number };
}

size_t Day1::FindLastOccurence(string Line)
{
	auto [NumberPosition, Number] = FindLastOccurence(Line, Day1::Number);
	auto [StringNumberPosition, StringNumber] = FindLastOccurence(Line, Day1::StringNumber);

	if (Number == 0 && StringNumber == 0)
	{
		return 0;
	}

	if (Number == 0) 
	{
		return StringNumber;
	}

	if (StringNumber == 0)
	{
		return Number;
	}

	return NumberPosition > StringNumberPosition ? Number : StringNumber;
}

std::pair<size_t, int32_t> Day1::FindLastOccurence(string Line, std::vector<std::string> Substr)
{
	size_t BestPosition = std::numeric_limits<size_t>::min();
	int32_t Number{};

	for (int i = 0; i != Substr.size(); ++i)
	{
		if (size_t Position = Line.rfind(Substr[i]); Position != string::npos && Position >= BestPosition)
		{
			BestPosition = Position;
			Number = i + 1;
		}
	}

	return { BestPosition, Number };
}