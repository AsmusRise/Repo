#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Task {
public:
    std::string description;
    Task(std::string desc) : description(desc) {}
};

class TodoList {
public:
    std::vector<Task> tasks;
    void addTask(std::string desc) { tasks.push_back(Task(desc)); }
    void showTasks() {
        for (auto& task : tasks) std::cout << task.description << "\n";
    }
};

int main() {
    TodoList todo;
    todo.addTask("Købe ind");
    todo.showTasks();
    return 0;
}

