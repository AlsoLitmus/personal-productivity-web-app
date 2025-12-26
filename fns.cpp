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