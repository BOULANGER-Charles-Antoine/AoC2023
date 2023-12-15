#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Day9
{
	static constexpr int32_t NB_MAX_NUMBER = 10'000;

	template<int Nb>
	static constexpr std::vector<std::vector<int32_t>> BuildCoefficient()
	{
		std::vector<std::vector<int32_t>> Coefficient;

		Coefficient.push_back(std::vector<int32_t>{ 1 });
		Coefficient.push_back(std::vector<int32_t>{ 1, 1 });

		bool StartIsNegativeSwitch = true;
		for (int i = 2; i != Nb; ++i)
		{
			bool IsNegativeSwitch = StartIsNegativeSwitch;
			Coefficient.push_back(std::vector<int32_t>());
			Coefficient[i].push_back(IsNegativeSwitch ? -1 : 1);
			IsNegativeSwitch = !IsNegativeSwitch;
			for (int j = 1; j != i; ++j)
			{
				int32_t NewCoefficient = std::abs(Coefficient[i - 1][j - 1]) + std::abs(Coefficient[i - 1][j]);
				NewCoefficient *= IsNegativeSwitch ? -1 : 1;

				Coefficient[i].push_back(NewCoefficient);
				IsNegativeSwitch = !IsNegativeSwitch;
			}
			Coefficient[i].push_back(1);

			StartIsNegativeSwitch = !StartIsNegativeSwitch;
		}

		return Coefficient;
	}
	const std::vector<std::vector<int32_t>> COEFFICIENTS = BuildCoefficient<NB_MAX_NUMBER>();
	

	int32_t Puzzle(std::string InputName);
	int32_t FindNextValue(std::string LineInput);
	int32_t CalculateNextValue(std::vector<int32_t> Numbers);

	int32_t FindPreviousValue(std::string LineInput);
	int32_t CalculatePreviousValue(std::vector<int32_t> Numbers);
} // Day9

