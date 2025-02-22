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
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << "\n";
        }
    }

    void editTask(int index, std::string newDesc) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].description = newDesc;
        } else {
            std::cout << "Ugyldigt index!\n";
        }
    }
};

int main() {
    TodoList todo;

    // Tilføj opgaver
    todo.addTask("Købe ind");
    todo.addTask("Læse til eksamen");
    todo.addTask("Lave mad");

    // Vis alle opgaver
    std::cout << "Opgaver før redigering:\n";
    todo.showTasks();

    // Rediger en opgave
    todo.editTask(1, "Købe ind og ryde op");

    // Vis opgaver efter redigering
    std::cout << "\nOpgaver efter redigering:\n";
    todo.showTasks();

    return 0;
}
