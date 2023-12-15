#include "Day2.h"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

std::string Day2::ColorToString(Color TheColor)
{
    switch (TheColor)
    {
        case Color::Blue:
            return "blue";
        case Color::Red:
            return "red";
        case Color::Green:
            return "green";
        default:
            return std::string();
    }
}

Day2::Color Day2::StringToColor(std::string ColorString)
{
    if (ColorString == "blue")
    {
        return Color::Blue;
    }
    else if(ColorString == "red")
    {
        return Color::Red;
    }
    else if (ColorString == "green")
    {
        return Color::Green;
    }
    else
    {
        return Color();
    }
}

template<>
int32_t Day2::Puzzle<Puzzle1>(std::string InputName)
{
    int32_t Sum{};

    ifstream InputFile{ InputName, ios::in };
    if (InputFile.is_open())
    {
        string Line;

        while (!InputFile.eof())
        {
            getline(InputFile, Line);
            Game AGame(Line);
            Sum += AGame.IsGamePossible() ? AGame.GetId() : 0;
        }
    }
    else
    {
        cout << "Error, file not opened !";
    }

    return Sum;
}

template<>
int32_t Day2::Puzzle<Puzzle2>(std::string InputName)
{
    int32_t Sum{};

    ifstream InputFile{ InputName, ios::in };
    if (InputFile.is_open())
    {
        string Line;

        while (!InputFile.eof())
        {
            getline(InputFile, Line);
            Game AGame(Line);
            Sum += AGame.GetPowerOfCubes();
        }
    }
    else
    {
        cout << "Error, file not opened !";
    }

    return Sum;
}

Day2::Game::Game(std::string LineInput)
{
    if(!LineInput.empty())
    {
        istringstream StringStream{ LineInput };
        StringStream.seekg(4);
        StringStream >> Id;

        char TrashCharacter;
        StringStream >> TrashCharacter;
        int32_t TempNbCube{};
        string ColorString;
        while (!StringStream.eof())
        {
            StringStream >> TempNbCube >> ColorString;

            if (ColorString[ColorString.size() - 1] == ',' || ColorString[ColorString.size() - 1] == ';')
            {
                ColorString.pop_back();
            }

            int32_t Index = ColorToInteger(StringToColor(ColorString));
            NbMaxCube[Index] = std::max(TempNbCube, NbMaxCube[Index]);

            if (NbMaxCube[Index] > MAX_CUBE[Index])
            {
                IsPossible = false;
            }
        }
    }

    PowerOfCubes = accumulate(NbMaxCube, NbMaxCube + NB_COLOR, 1, std::multiplies<int32_t>());
}

int32_t Day2::Game::GetId() const noexcept
{
    return Id;
}

bool Day2::Game::IsGamePossible() const noexcept
{
    return IsPossible;
}

int32_t Day2::Game::GetPowerOfCubes() const noexcept
{
    return PowerOfCubes;
}
