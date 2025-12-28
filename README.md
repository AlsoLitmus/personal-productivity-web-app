# PERSONAL PRODUCTIVITY WEB APP
This web app will include user accounts, give users the ability to create, edit, and delete tasks, allow users to assign due dates and priority levels to particular tasks, and mark tasks as complete.

## WHAT THE PROGRAM DOES
The program first requires new users to register an account. New users must register an untaken username and enter a new password. If a username is already taken, the user is prompted to re-enter an entirely different username for their new account. Once a user has registered an account, the use can login using the second option on th login menu. User enters their username and password. After that, the user is prompted with a new menu. This menu will include 6 different options.

1. Create a task.
2. Edit a task.
3. Delete a task.
4. View tasks.
5. Mark a task as complete.
6. Exit the program.

All menu options have a different functionality. When the user enters 1 as their choice, they are prompted to enter a task, a due date for that task, and a priority level. The task is automatically marked as incomplete once the task has been created. If a user were to choose option 2 as their choice, they are required to choose a task to edit from their list of already created tasks. If the user has no tasks, the program lets the user know that there are no avalable tasks to edit. Whenever a user decides to edit a task, they will be asked for the task number to edit, the new task, the new due date, and the new priority level. The user is not asked if the task is already completed or not. The program automatically sets the completion status as incomplete. 

If the user were to choose option 3 from the menu, the user is given a table of tasks that they have already created. The user is prompted to enter the task number they would like to delete. If the user has not entered any tasks or has already deleted all previous tasks, the program lets the user know that there are no available tasks to delete. With option 4, the user is given a table of all the tasks that they have created but have no removed, the due dates of each of the tasks, the priority levels, and the completion status. Option 5 gives user to mark incomplete tasks as complete. All the user has to do to mark a task as complete it to choose this option and enter the task number they would like to mark as complete once prompted.

Option 6 allows the user to exit the program.

<img width="758" height="452" alt="Example of Task Management Program Image" src="https://github.com/user-attachments/assets/20d0a54d-d6ef-4c81-b3ce-7cf4a4ee00f5" />

## WHAT TECH WAS USED

I used VSCommunity and C++ for this project. I also used 3 separate files. One file for main, one for my function definitions, and one for function prototypes. This keeps the program organized and not as cluttered. Throughout my program, I've used functions to separate out differet tasks, input validation to prevent users from entering in something they shouldn't, and I also used iomanip to input data into a neat-looking table. Using vectors was very useful because it allowed me to store things like the name of a task, it's due date, priority level, and completion status.

## WHAT I LEARNED

Even though this project was pretty simple, I got to learn alot from it. Often times, it can be hard to find good use in creating multiple files as a beginner programmer, but this project helped me see the use in doing so. Ensuring all code is indented appropriately is also pretty useful. It makes the code easier to look at and understand. Proper naming of functions and variable is also very important. Otherwise you wouldn't know which function does what unless you paid close attention to what their definitions includes. One roadblock I stumbled on as I was working on this project was how I was going to store the individual pieces of data for each task. Initially I was going to use a vector of arrays but I came across an error I couldn't understand so I stuck with a vector of vectors. In the end, it was a pretty easy solution to a problem I didn't understand. 
