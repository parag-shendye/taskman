#pragma once
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>


using namespace Utils;

struct Task
{
    Status m_status;
    std::string m_description;
    Importance m_importance;
    std::vector<const Task&> m_tasks;    
    Datetime m_datetime;
};
