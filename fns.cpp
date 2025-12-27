#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fns.h"

bool LoggingIn(std::string &username) {
	std::string password, user, pass;
	std::cout << "Enter Username: ";
	std::cin >> username;

	std::cout << "Enter Password: ";
	std::cin >> password;

	std::ifstream read(username + ".txt");
	std::getline(read, user);
	std::getline(read, pass);

	if (user == username && pass == password) {
		return true;
	}
	else {
		return false;
	}
}

void displayMenu() {
	std::cout << "Select a choice!\n1: Register\n2: Login\n Your choice: ";
}

int getInput() {
	int choice;
	std::cin >> choice;


	while (!std::cin >> choice || choice < 1 || choice > 2) {
		std::cout << "Invalid input. Please enter a number between 1 and 2: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}

	return choice;
}

void doSomething(std::string &username) {
	std::cout << "Hello, " << username << "! You have successfully logged in." << std::endl;
}

void displayMainMenu() {
	std::cout << "\nTask Manager Menu:" << std::endl;
	std::cout << "1. Create Task" << std::endl;
	std::cout << "2. Edit Task" << std::endl;
	std::cout << "3. Delete Task" << std::endl;
	std::cout << "4. View tasks" << std::endl;
	std::cout << "5. Exit" << std::endl;
}


int getChoice(std::vector<std::string>& tasks) {
	int choice;
	std::cout << "Enter your choice (1-5): ";
	std::cin >> choice;

	while (!std::cin >> choice || choice < 1 || choice > 5) {
		std::cout << "Invalid input. Please enter a number between 1 and 5: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choice;
	}

	switch (choice) {
	case 1:
		std::cout << "Creating a new task..." << std::endl;
		createTask(tasks);
		break;
	case 2:
		std::cout << "Editing an existing task..." << std::endl;
		editTask(tasks);
		break;
	case 3:
		std::cout << "Deleting a task..." << std::endl;
		deleteTask(tasks);
		break;
	case 4:
		std::cout << "Here are all your tasks..." << std::endl;
		viewTasks(tasks);
		break;
	case 5:
		std::cout << "Exiting the program." << std::endl;
		break;
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
		getChoice(tasks);
		break;
	}
	return choice;
}

void createTask(std::vector<std::string>& tasks) {

	std::string task;
	std::cout << "Enter a task: ";
	std::cin.ignore();
	std::getline(std::cin, task);
	std::cout << "Task '" << task << "' created successfully!" << std::endl;
	tasks.push_back(task);

}

void editTask(std::vector<std::string>& tasks)
{
	if (tasks.empty()) {
		std::cout << "No tasks available to edit." << std::endl;
		return;
	}
	std::cout << "\nHere are your current tasks:" << std::endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}
	int taskNumber;
	std::cout << "Enter the number of the task you want to edit: ";
	std::cin >> taskNumber;

	while (!std::cin >> taskNumber || taskNumber < 1 || taskNumber > tasks.size()) {
		if (tasks.size() > 1) {
			std::cout << "Invalid input. Please enter a number between 1 and " << tasks.size() << ": ";
		}
		else {
			std::cout << "Invalid input. Please enter 1: ";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> taskNumber;
	}

	std::cin.ignore();
	std::string newTask;
	std::cout << "Enter the new description for the task: ";
	std::getline(std::cin, newTask);
	tasks[taskNumber - 1] = newTask;
	std::cout << "Task updated successfully!" << std::endl;
}

void deleteTask(std::vector<std::string>& tasks) {
	if (tasks.empty()) {
		std::cout << "No tasks available to edit." << std::endl;
		return;
	}

	std::cout << "\nHere are your current tasks:" << std::endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}

	int taskNumber;
	std::cout << "Enter the number of the task you want to delete: ";
	std::cin >> taskNumber;

	while (!std::cin >> taskNumber || taskNumber < 1 || taskNumber > tasks.size()) {
		if (tasks.size() > 1) {
			std::cout << "Invalid input. Please enter a number between 1 and " << tasks.size() << ": ";
		}
		else {
			std::cout << "Invalid input. Please enter 1: ";
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> taskNumber;
	}

	std::cin.ignore();
	tasks.erase(tasks.begin() + taskNumber - 1);
	std::cout << "Task deleted successfully!" << std::endl;

}

void viewTasks(std::vector<std::string>& tasks) {
	if (tasks.empty()) {
		std::cout << "No tasks available." << std::endl;
		return;
	}
	std::cout << "\nHere are your current tasks:" << std::endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << i + 1 << ". " << tasks[i] << std::endl;
	}
}
