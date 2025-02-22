#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//starting main.cpp
//Starting completedTask

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

	//method to print the todo list
	void printTodoList() const {
		for (const auto& task : todolist) {
			cout <<task._description << endl;
		}
	}
};

int main() {

    TodoList todo = TodoList();

    //print the todo list
    todo.printTodoList();
    return 0;
}
