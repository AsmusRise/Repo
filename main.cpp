#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//starting main.cpp
//Starting completedTask
//adding method completetask
class Task
{
	public:
	string _description;
	Task(string description){
		_description = description;
	}
};

class TodoList
{	
	public:
	vector<Task> todolist;
	TodoList(){}
	
	//method to mark tasks as completed
	void complTask(const std::string& taskDescription);

	//method to print the todo list
	void printTodoList() const {
		for (const auto& task : todolist) {
			cout <<task._description << endl;
		}
	}
};

void TodoList::complTask(const std::string& tasdescription) {
	for (auto& task : todolist) {
		if (task._description == taskdescription) {
			task._description = "completed: " + task._description;
			return;
		}
	}
	cout << "Task not found: " << taskdescription << "endl;
}


int main() {

    TodoList todo = TodoList();


    todo.complTask("Call the bank");

    //print the todo list
    todo.printTodoList();
    return 0;
}
