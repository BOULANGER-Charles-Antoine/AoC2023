#pragma once

#include <cstdint>
#include <string>

#include "Utils.h"

namespace Day2
{
	enum class Color : int32_t
	{
		Blue,
		Red,
		Green
	};

	std::string ColorToString(Color TheColor);
	Color StringToColor(std::string ColorString);
	template<typename Enum>
	constexpr auto ColorToInteger(Enum Element) -> std::underlying_type<Enum>::type
	{
		return static_cast<std::underlying_type<Enum>::type>(Element);
	}

	template<class T>
	int32_t Puzzle(std::string InputName) { return 0; }

	template<>
	int32_t Puzzle<Puzzle1>(std::string InputName);
	template<>
	int32_t Puzzle<Puzzle2>(std::string InputName);

	class Game
	{
	public:
		static constexpr int32_t NB_COLOR = 3;
		static constexpr int32_t MAX_CUBE[NB_COLOR]{14, 12, 13};

		Game(std::string LineInput);

		int32_t GetId() const noexcept;
		bool IsGamePossible() const noexcept;
		int32_t GetPowerOfCubes() const noexcept;
	private:
		int32_t Id{};
		int32_t NbMaxCube[NB_COLOR]{};
		bool IsPossible = true;
		int32_t PowerOfCubes{};
	};
};

