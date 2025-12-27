#ifndef FNS_H  
#define FNS_H  

#include <string>  
#include <vector>  

bool LoggingIn(std::string &username);  
void displayMenu();  
int getInput();  
void doSomething(std::string &username);  
void displayMainMenu();  
int getChoice(std::vector<std::vector<std::string>> &tasks);
void createTask(std::vector<std::vector<std::string>> &tasks);
void editTask(std::vector<std::vector<std::string>> &tasks);
void deleteTask(std::vector<std::vector<std::string>> &tasks);
void viewTasks(std::vector<std::vector<std::string>> &tasks);

#endif


