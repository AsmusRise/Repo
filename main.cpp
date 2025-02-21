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
};

int main() {

    TodoList todo = TodoList();

    return 0;
}
