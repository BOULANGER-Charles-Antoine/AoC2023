#include "Day3.h"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template<>
int32_t Day3::Puzzle<Puzzle1>(std::string InputName)
{
    int32_t Sum{};

    ifstream InputFile{ InputName, ios::in };
    if (InputFile.is_open())
    {
        string PreviousLine;
        string CurrentLine;
        string NextLine;

        getline(InputFile, CurrentLine);
        getline(InputFile, NextLine);
        Sum += AddPartNumberInLine(PreviousLine, CurrentLine, NextLine);

        while (!InputFile.eof())
        {
            PreviousLine = CurrentLine;
            CurrentLine = NextLine;
            if (!InputFile.eof())
            {
                getline(InputFile, NextLine);
            }

            Sum += AddPartNumberInLine(PreviousLine, CurrentLine, NextLine);
        }
        PreviousLine = CurrentLine;
        CurrentLine = NextLine;
        NextLine = "";

        Sum += AddPartNumberInLine(PreviousLine, CurrentLine, NextLine);
    }
    else
    {
        cout << "Error, file not opened !";
    }

    return Sum;
}

template<>
int32_t Day3::Puzzle<Puzzle2>(std::string InputName)
{
    int32_t Sum{};

    ifstream InputFile{ InputName, ios::in };
    if (InputFile.is_open())
    {
        string PreviousLine2;
        string PreviousLine;
        string CurrentLine;
        string NextLine;
        string NextLine2;

        getline(InputFile, CurrentLine);
        getline(InputFile, NextLine);
        getline(InputFile, NextLine2);
        Sum += AddGearRatioInLine(PreviousLine2, PreviousLine, CurrentLine, NextLine, NextLine2);

        while (!InputFile.eof())
        {
            PreviousLine2 = PreviousLine;
            PreviousLine = CurrentLine;
            CurrentLine = NextLine;
            NextLine = NextLine2;
            if (!InputFile.eof())
            {
                getline(InputFile, NextLine2);
            }

            Sum += AddGearRatioInLine(PreviousLine2, PreviousLine, CurrentLine, NextLine, NextLine2);
        }

        PreviousLine2 = PreviousLine;
        PreviousLine = CurrentLine;
        CurrentLine = NextLine;
        NextLine = NextLine2;
        NextLine2 = "";
        Sum += AddGearRatioInLine(PreviousLine2, PreviousLine, CurrentLine, NextLine, NextLine2);

        PreviousLine2 = PreviousLine;
        PreviousLine = CurrentLine;
        CurrentLine = NextLine;
        NextLine = "";
        Sum += AddGearRatioInLine(PreviousLine2, PreviousLine, CurrentLine, NextLine, NextLine2);
    }
    else
    {
        cout << "Error, file not opened !";
    }

    return Sum;
}

int32_t Day3::AddPartNumberInLine(std::string PreviousLine, std::string CurrentLine, std::string NextLine)
{
    int32_t SumNumberPart = 0;

    istringstream CurrentLineStream{ CurrentLine };

    for (int i = 0; i < CurrentLine.size(); ++i)
    {
        if (isdigit(CurrentLine[i]))
        {
            int32_t Number;
            CurrentLineStream.seekg(i);
            CurrentLineStream >> Number;

            if (IsPartNumber(PreviousLine, CurrentLine, NextLine, Number, i))
            {
                SumNumberPart += Number;
            }
            i += log10(Number) + 1;
        }
    }

    return SumNumberPart;
}

bool Day3::IsPartNumber(std::string PreviousLine, std::string CurrentLine, std::string NextLine, int32_t Number, int32_t Index)
{
    int LengthNumber = log10(Number) + 1; // Number of digits

    return IsAdjacentToSymbol(PreviousLine, CurrentLine, NextLine, Index, LengthNumber);
}

bool Day3::IsAdjacentToSymbol(std::string PreviousLine, std::string CurrentLine, std::string NextLine, int32_t Position, int32_t LengthNumber)
{
    for (int i = -1; i != LengthNumber + 1; ++i)
    {
        if (Position + i >= 0)
        {
            if (Position + i < PreviousLine.size() && !isdigit(PreviousLine[Position + i]) && PreviousLine[Position + i] != '.')
            {
                return true;
            }

            if (Position + i < CurrentLine.size() && !isdigit(CurrentLine[Position + i]) && CurrentLine[Position + i] != '.')
            {
                return true;
            }

            if (Position + i < NextLine.size() && !isdigit(NextLine[Position + i]) && NextLine[Position + i] != '.')
            {
                return true;
            }
        }
    }

    return false;
}

int32_t Day3::AddGearRatioInLine(std::string PreviousLine2, std::string PreviousLine, std::string CurrentLine, std::string NextLine, std::string NextLine2)
{
    int32_t SumGearRatio = 0;

    for (int i = 0; i < CurrentLine.size(); ++i)
    {
        if (CurrentLine[i] == '*')
        {
            vector<int32_t> AdjacentNumbers;

            GetAdjacentPartNumberTo(i, PreviousLine2, PreviousLine, CurrentLine, AdjacentNumbers);
            GetAdjacentPartNumberTo(i, PreviousLine, CurrentLine, NextLine, AdjacentNumbers);
            GetAdjacentPartNumberTo(i, CurrentLine, NextLine, NextLine2, AdjacentNumbers);

            bool FoundTwoAdjacentNumbers = AdjacentNumbers.size() == 2;

            if (FoundTwoAdjacentNumbers)
            {
                SumGearRatio += accumulate(AdjacentNumbers.begin(), AdjacentNumbers.end(), 1, multiplies<int32_t>());
            }
            else
            {
                break;
            }
        }
    }

    return SumGearRatio;
}

void Day3::GetAdjacentPartNumberTo(const int32_t& IndexGear, std::string PreviousLine, std::string CurrentLine, std::string NextLine, std::vector<int32_t>& AdjacentNumbers)
{
    istringstream LineStream{ CurrentLine };

    for (int i = 0; i < CurrentLine.size(); ++i)
    {
        if (isdigit(CurrentLine[i]))
        {
            int32_t Number;
            LineStream.seekg(i);
            LineStream >> Number;

            int32_t IndexMin = i - 1;
            int32_t IndexMax = i + log10(Number) + 1;
            if (IndexMin <= IndexGear && IndexGear <= IndexMax && IsPartNumber(PreviousLine, CurrentLine, NextLine, Number, i))
            {
                AdjacentNumbers.push_back(Number);
            }
            i += log10(Number) + 1;
        }
    }
}
