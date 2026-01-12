#include <iostream>
#include <fstream>
#include <string>
#include "fns.h"
#include <vector>

using namespace std;

int main()
{
	// Variables
	int choice;
	bool onLoginMenu = true;
	bool userAlreadyExists = true;
	ofstream fileOfRegisteredUsers;
	fileOfRegisteredUsers.open("registeredUsers.txt", ios::app);

	// while we are still on the login menu...  
	while (onLoginMenu) {

		displayMenu();
		choice = getInput();

		// if the user wants to register an account...
		if (choice == 1) {
			string username, password;
			cout << "Select a username: ";
			cin >> username; 

			ifstream readRegisteredUsers("registeredUsers.txt");
			string existingUser;
			userAlreadyExists = false;

			while (getline(readRegisteredUsers, existingUser)) {
				if (existingUser == username) {
					
					userAlreadyExists = true;
					break;
				}
			}
			readRegisteredUsers.close();
			
			if (userAlreadyExists) {
				cout << "Username already taken. Please choose a different username." << endl;
				continue;
			}

			cout << "Select a password: ";
			cin >> password;

			ofstream file;

			file.open(username + ".txt");
			file << username << endl << password;
			file.close();

			cout << "Registration Successful!" << endl;
			if (fileOfRegisteredUsers.is_open()) {
				fileOfRegisteredUsers << "\n" + username;
				fileOfRegisteredUsers.close();

				std::cout << "Text successfully appended to " << "registeredUsers.txt" << std::endl;
			}
			else {
				std::cerr << "Error: Unable to open the file " << "registeredUsers.txt" << std::endl;
			}

			fileOfRegisteredUsers << username << endl;
			fileOfRegisteredUsers.close();
		}
		else if (choice == 2) { // if the user want to sign into an account
			string username;
			bool status = LoggingIn(username);
			while (!status) {
				cout << "Incorrect Information, Try Again!" << endl;
				system("PAUSE");
				status = LoggingIn(username);
			}
			if (status) {
				cout << "Login Successful!" << endl;
				system("PAUSE");

				doSomething(username);

				std::vector<std::vector<string>> tasks;
				int chosenChoice = 0;
				int EXIT_OPTION = 7;

				while (chosenChoice != EXIT_OPTION) {
					displayMainMenu();
					chosenChoice = getChoice(tasks);
				}

				return 0;

			}
		}
	}
	return 0;
}


