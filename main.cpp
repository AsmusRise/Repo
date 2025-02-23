#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//starting main.cpp
//Starting completedTask
//adding method completetask
//writing method addTask

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

	//method to add task to todolist
	void addTask(const Task& task){
		todolist.push_back(task);
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

    //create tasks
    Task task1("buy grocceries");
    Task task2("Complete homework");
    Task task3("Call the bank");

    //Add tasks to the todolist
    todo.addTask(task1);
    todo.addTask(task2);
    todo.addTask(task3);


    //print the todo list
    todo.printTodoList();
    return 0;
}
