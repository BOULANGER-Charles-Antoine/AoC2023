#include <iostream>
#include <map>
#include <functional>

#include "Utils.h"
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"

using namespace std;

namespace AdventOfCode
{
#ifdef NDEBUG
    string PrefixFile = "Input/";
#else
    string PrefixFile = "Input/Debug_";
#endif //NDEBUG
    using PairOfPuzzle = pair<function<int32_t(string)>, function<int32_t(string)>>;

    vector<pair<PairOfPuzzle, string>> AdventCodeDays
    {
        { make_pair(&Day1::Puzzle<Puzzle1>, &Day1::Puzzle<Puzzle2>), PrefixFile + "Day1.txt"},
        { make_pair(&Day2::Puzzle<Puzzle1>, &Day2::Puzzle<Puzzle2>), PrefixFile + "Day2.txt"},
        { make_pair(&Day3::Puzzle<Puzzle1>, &Day3::Puzzle<Puzzle2>), PrefixFile + "Day3.txt" }/*,
        {&Day4::Puzzle<Puzzle1>, &Day4::Puzzle<Puzzle2>, PrefixFile + "Day4.txt"},
        {&Day5::Puzzle<Puzzle1>, &Day5::Puzzle<Puzzle2>, PrefixFile + "Day5.txt"},
        {&Day6::Puzzle<Puzzle1>, &Day6::Puzzle<Puzzle2>, PrefixFile + "Day6.txt"},
        {&Day7::Puzzle<Puzzle1>, &Day7::Puzzle<Puzzle2>, PrefixFile + "Day7.txt"},
        {&Day8::Puzzle<Puzzle1>, &Day8::Puzzle<Puzzle2>, PrefixFile + "Day8.txt"},
        {&Day9::Puzzle<Puzzle1>, &Day9::Puzzle<Puzzle2>, PrefixFile + "Day9.txt"}*/
    };

    void DisplayPuzzle(function<int32_t(string)> Puzzle, const string& Input, int32_t Index, const int32_t NumberPuzzle)
    {
        const auto& [ResultDay, DurationDay] = Utils::MesureCallable(Puzzle, Input);
        if (ResultDay.has_value())
        {
            cout << "Function Day" << Index << "::Puzzle" << NumberPuzzle << " returns " << ResultDay.value();
        }
        else
        {
            cout << "Function Day" << Index << "::Puzzle" << NumberPuzzle << " finishs ";
        }
        cout << " in " << DurationDay << ".\n";
    }

    void DisplayAdventOfCode()
    {
        int32_t Index = 1;

        for (const auto& [Day, Input] : AdventCodeDays)
        {
            const auto& [Puzzle1, Puzzle2] = Day;

            DisplayPuzzle(Puzzle1, Input, Index, 1);
            DisplayPuzzle(Puzzle2, Input, Index, 2);

            ++Index;
            cout << '\n';
        }
    }
}

using namespace AdventOfCode;

int main(int argc, char* argv[])
{
    DisplayAdventOfCode();
}