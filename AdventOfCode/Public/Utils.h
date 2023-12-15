#pragma once

#include <chrono>
#include <iostream>
#include <utility>

class Puzzle1;
class Puzzle2;

class Utils 
{
public:
    template <class Call, class ...Args>
    static constexpr auto MesureCallable(Call Callable, Args&& ...Arguments);

    static constexpr size_t CharacterToInt(char Character);

private:
    template <class ResultType, class Call, class ...Args>
    static constexpr auto ComputeMesureCallable(ResultType& Result, Call Callable, Args&& ...Arguments);
};

template <class Call, class ...Args>
constexpr auto Utils::MesureCallable(Call Callable, Args&& ...Arguments)
{
    using TimePoint = std::chrono::steady_clock::time_point;
    using ReturnType = std::conditional_t<std::is_void_v<std::invoke_result_t<Call, Args...>>, 
                                          int8_t, 
                                          std::invoke_result_t<Call, Args...>>;
    std::optional<ReturnType> Result{};
    
    const TimePoint BeginTime = std::chrono::high_resolution_clock::now();
    ComputeMesureCallable(Result, Callable, std::forward<Args>(Arguments)...);
    const TimePoint EndTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> Duration = EndTime - BeginTime;

    return std::pair{ Result, Duration };
}

template <class ResultType, class Call, class ...Args>
constexpr auto Utils::ComputeMesureCallable(ResultType& Result, Call Callable, Args&& ...Arguments) 
{
    if constexpr (std::is_void_v<std::invoke_result_t<Call, Args...>>)
    {
        Callable(std::forward<Args>(Arguments)...);
    }
    else 
    {
        Result = Callable(std::forward<Args>(Arguments)...);
    }
}

constexpr size_t Utils::CharacterToInt(char Character) 
{
    return Character - 48;
}