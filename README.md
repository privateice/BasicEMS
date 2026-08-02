# BasicEMS

Final Project  
The PDF file in the repo describes the assignment.  
All code and this readme &copy; Mary E Tyler 2026.  

### Built with:
- C++17
- Apple Clang
- VS Code
- git

## Employee Management System (BasicEMS)

### Description
-----------
BasicEMS is a console-based Employee Management System written in C++.
The program demonstrates object-oriented programming concepts including
encapsulation, operator overloading, static members, and separation of functionality into multiple classes.

### Features
--------
- User authentication
- Permission-based access control
- Search employees by username, ID, or partial name
- Add new employees
- Modify employee information
- Remove employees with confirmation
- Automatically assign unique employee IDs
- Automatically generate passwords
- Logout without exiting the program

### Design Decisions
----------------
- Employee IDs are automatically assigned to prevent duplicate IDs.
- Usernames must be unique.
- Users cannot modify their own permissions.
- Permission presets simplify creation of HR, Manager, and Employee accounts.

### Notes
-----
Employee records are stored in memory only.  
Data is not persisted between program executions.  

### Sample Users to Facilitate Testing
----------------------------------
#### Username    Password  
renee       passwordHR  
manny       passwordM  
emmy        passwordE  
emmy2       passwordE  

### Project Structure
-----------------
- main.cpp - Program entry point.
- Employee.h / Employee.cpp - Employee class and related functions.
- Permissions.h / Permissions.cpp - Defines employee permissions and preset permission roles.
- EmployeesList.h / EmployeesList.cpp - Stores and manages the employee database.
- Login.h / Login.cpp - Handles user authentication.
- Menu.h / Menu.cpp - Displays menus and executes user commands.
- Utilities.h / Utilities.cpp - Helper functions.

### Compilation
-----------
Compile using a C++17 compiler.

Example:

clang++ -std=c++17 main.cpp Employee.cpp Permissions.cpp \
Permissions.cpp EmployeesList.cpp Login.cpp Menu.cpp Utilities.cpp \
-o BasicEMS


