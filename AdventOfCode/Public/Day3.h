#pragma once

#include <cstdint>
#include <string>

#include "Utils.h"

namespace Day3
{
	template<class T>
	int32_t Puzzle(std::string InputName) { return 0; }

	template<>
	int32_t Puzzle<Puzzle1>(std::string InputName);
	template<>
	int32_t Puzzle<Puzzle2>(std::string InputName);

	int32_t AddPartNumberInLine(std::string PreviousLine, std::string CurrentLine, std::string NextLine);
	bool IsPartNumber(std::string PreviousLine, std::string CurrentLine, std::string NextLine, int32_t Number, int32_t Index);
	bool IsAdjacentToSymbol(std::string PreviousLine, std::string CurrentLine, std::string NextLine, int32_t Position, int32_t LengthNumber);

	int32_t AddGearRatioInLine(std::string PreviousLine2, std::string PreviousLine, std::string CurrentLine, std::string NextLine, std::string NextLine2);
	void GetAdjacentPartNumberTo(const int32_t& IndexGear, std::string PreviousLine, std::string CurrentLine, std::string NextLine, std::vector<int32_t>& AdjacentNumbers);
};