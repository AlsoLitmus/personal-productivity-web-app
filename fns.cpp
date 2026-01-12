#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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
	std::cout << "5. Mark a task as complete." << std::endl;
	std::cout << "6. Search for a task." << std::endl;
	std::cout << "7. Exit" << std::endl;
}

int getChoice(std::vector<std::vector<std::string>>& tasks) {
	int choice;
	std::cout << "Enter your choice (1-7): ";
	std::cin >> choice;

	while (!std::cin >> choice || choice < 1 || choice > 7) {
		std::cout << "Invalid input. Please enter a number between 1 and 7: ";
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
		std::cout << "Marking a task as complete..." << std::endl;
		// Functionality to mark a task as complete would go here.
		markComplete(tasks);
		break;
	case 6:
		std::cout << "Searching for a task..." << std::endl;
		searchForTasks(tasks);
		break;
	case 7:
		std::cout << "Exiting the program." << std::endl;
		exitProgram();
		break;
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
		getChoice(tasks);
		break;
	}
	return choice;
}

int exitProgram() {
	std::exit(0);
	return 0;
}

bool checkDateFormatting(const std::string& date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
	return true;
}

void createTask(std::vector<std::vector<std::string>> &tasks) {
  std::string task;  
  std::string dueDate;  
  std::string priorityLevel;
  std::string status = "Incomplete";

  std::cout << "Enter a task: ";  
  std::cin.ignore();  
  std::getline(std::cin, task);  

  std::cout << "Enter due date (YYYY-MM-DD): ";  
  std::getline(std::cin, dueDate);  

  // Ensure that the user is typing the date in the proper format.
  bool dateIsFormattedCorrectly = checkDateFormatting(dueDate);

  if (dateIsFormattedCorrectly) {
	  std::cout << "Date formatted correctly." << std::endl;
  }
  else {
	  std::cout << "Date not formatted correctly. Please use the format YYYY-MM-DD." << std::endl;
	  while (dateIsFormattedCorrectly == false) {
		  std::cout << "Enter due date (YYYY-MM-DD): ";
		  std::getline(std::cin, dueDate);
		  dateIsFormattedCorrectly = checkDateFormatting(dueDate);
	  }
  }

  std::cout << "Enter priority level (Low, Medium, High): ";
  std::getline(std::cin, priorityLevel);

  // Now check if user has entered a valid priority level.
  while (priorityLevel != "Low" && priorityLevel != "Medium" && priorityLevel != "High") {
	  std::cout << "Invalid priority level. Please enter Low, Medium, or High: ";
	  std::getline(std::cin, priorityLevel);
  }

  std::cout << "Task '" << task << "' created successfully!" << std::endl;  
  tasks.push_back(std::vector<std::string>{task, dueDate, priorityLevel, status}); // Use double braces to fix the initializer issue
}

void editTask(std::vector<std::vector<std::string>>& tasks)
{
	viewTasks(tasks);
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

	std::cout << "Enter the new due date (YYYY-MM-DD): ";
	std::string newDueDate;
	std::getline(std::cin, newDueDate);

	// Ensure that the user is typing the date in the proper format.
	bool dateIsFormattedCorrectly = checkDateFormatting(newDueDate);

	if (dateIsFormattedCorrectly) {
		std::cout << "Date formatted correctly." << std::endl;
	}
	else {
		std::cout << "Date not formatted correctly. Please use the format YYYY-MM-DD." << std::endl;
		while (dateIsFormattedCorrectly == false) {
			std::cout << "Enter due date (YYYY-MM-DD): ";
			std::getline(std::cin, newDueDate);
			dateIsFormattedCorrectly = checkDateFormatting(newDueDate);
		}
	}

	std::cout << "Enter priority level (Low, Medium, High): ";
	std::string newPriorityLevel;
	std::getline(std::cin, newPriorityLevel);

	// Now check if user has entered a valid priority level.
	while (newPriorityLevel != "Low" && newPriorityLevel != "Medium" && newPriorityLevel != "High") {
		std::cout << "Invalid priority level. Please enter Low, Medium, or High: ";
		std::getline(std::cin, newPriorityLevel);
	}

	std::string status = "Incomplete";
	std::vector<std::string> newTaskArray = { newTask, newDueDate, newPriorityLevel, status };

	tasks[taskNumber - 1] = newTaskArray;
	std::cout << "Task updated successfully!" << std::endl;
}

void deleteTask(std::vector<std::vector<std::string>>& tasks) {
	viewTasks(tasks);

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

void markComplete(std::vector<std::vector<std::string>>& tasks) {
	viewTasks(tasks);
	int taskNumber;

	// check if we have any available tasks before allowing user to mark one as complete
	if (tasks.empty()) {
		std::cout << "No tasks available to mark as complete." << std::endl;
		return;
	}

	std::cout << "Enter the number of the task you want to mark as complete: ";
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
	tasks[taskNumber - 1][3] = "Complete";
	std::cout << "Task marked as complete successfully!" << std::endl;
}

void viewTasks(std::vector<std::vector<std::string>>& tasks) {

	if (tasks.empty()) {
		std::cout << "No tasks available." << std::endl;
		return;
	}
	std::cout << "\nHere are your current tasks:" << std::endl;
	std::cout << std::setw(10) << std::left << "Task #" << std::left << std::setw(30) << "Tasks" << std::left << std::setw(20) << std::left << "Date Due" 
		<< std::left << std::setw(20) << "Priority Level" << std::right << std::setw(10) << "Completion" << std::endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << std::setw(10) << std::left << i + 1 << std::left << std::setw(30) << tasks[i][0] << std::left << std::setw(20) << std::left << tasks[i][1] 
			<< std::left << std::setw(20) << tasks[i][2] << std::right << std::setw(10) << tasks[i][3] << std::endl;
	}
}

void searchForTasks(std::vector<std::vector<std::string>>& tasks) {
	std::string word;
	int numInstancesFound = 0;
	std::cout << "\nEnter a word to search for in your list of tasks: ";
	std::cin.ignore();
	std::getline(std::cin, word);
	std::cout << "Search Results: \n";

	if (word == "" || word == " ") {
		std::cout << "No search results available." << std::endl;
		return;
	}

	// Loop through out list of tasks.
	for (std::vector<std::string> task : tasks) {
		std::string taskName = task[0];
		std::size_t foundPos = taskName.find(word);

		// Check if the return value is NOT std::string::npos
		if (foundPos != std::string::npos) {
			//std::cout << "The word was found at position: " << foundPos << std::endl;
			std::cout << taskName << std::endl;
			numInstancesFound++;
		}
	}

	if (!numInstancesFound) {
		std::cout << "No search results available." << std::endl;
	}
}

