#ifndef FNS_H  
#define FNS_H  

#include <string>  
#include <vector>  

bool LoggingIn(std::string &username);  
void displayMenu();  
int getInput();  
void doSomething(std::string &username);  
void displayMainMenu();  
int getChoice(std::vector<std::string>& t);  
void createTask(std::vector<std::string>& t);  
void editTask(std::vector<std::string>& t);  
void deleteTask(std::vector<std::string>& t);  
void viewTasks(std::vector<std::string>& t);  

#endif
