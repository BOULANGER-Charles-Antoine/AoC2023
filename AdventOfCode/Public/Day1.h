#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "Utils.h"

namespace Day1
{
	static const std::vector<std::string> Number = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	static const std::vector<std::string> StringNumber = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	template<class T>
	int32_t Puzzle(std::string InputName) { return 0; }

	template<>
	int32_t Puzzle<Puzzle1>(std::string InputName);
	template<>
	int32_t Puzzle<Puzzle2>(std::string InputName);

	template<class T>
	int16_t FindCalibrationValue(std::string Line) { return 0; }

	template<>
	int16_t FindCalibrationValue<Puzzle1>(std::string Line);
	template<>
	int16_t FindCalibrationValue<Puzzle2>(std::string Line);

	size_t FindFirstOccurence(std::string Line);
	std::pair<size_t, int32_t> FindFirstOccurence(std::string Line, std::vector<std::string> Substr);

	size_t FindLastOccurence(std::string Line);
	std::pair<size_t, int32_t> FindLastOccurence(std::string Line, std::vector<std::string> Substr);
};