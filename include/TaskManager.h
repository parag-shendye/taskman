#pragma once
#include "Task.h"
#include <SQLiteCpp/SQLiteCpp.h>

class TaskManager
{
private:
    SQLite::Database* db;
    TaskManager(){
        try {
            db = new SQLite::Database("tasks.db");
            std::cout<<"Connection established"<<std::endl;
        } catch (std::exception& e) {
            std::cerr<<e.what()<<std::endl;
        }
    };
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;
public:
    static TaskManager& getInstance() {
        static TaskManager instance;
        return instance;
    }
    // int createTask(const Task& task);
    // Task& getTask(int taskId);
    // int getStatus(int taskId);
    // void updateTask(int taskId, const Task& updatedTask);
    // int deleteTask(int taskId);
    // std::vector<const Task&> getAlltasks(); 
    ~TaskManager();
};

