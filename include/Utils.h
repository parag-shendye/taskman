#pragma once
#include <chrono>

namespace Utils
{
    enum class Status {ToDo, InProgress, Completed};
    enum class Importance {Urgent, Important, FreeTime};
    typedef std::chrono::system_clock::time_point Datetime;
} 