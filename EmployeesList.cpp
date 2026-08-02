#include "EmployeesList.h"
#include "Login.h"

EmployeesList::EmployeesList() 
{   // Creates an EmployeesList with some employees suitable for testing
    MakeSomeEmployees();
};

int EmployeesList::FindUserbyUsername(std::string username) const
{   //Looks for the employee, returns the index or -1 if not found
    for (size_t i = 0; i < employees.size(); i++)
        {if (employees[i].GetUsername() == username) {return (i);};};
    return(-1); //return -1 if not found
};

int EmployeesList::FindUserbyID(int id) const
{   //Looks for the employee, returns the index or -1 if not found

    for (size_t i = 0; i < employees.size(); i++)
        {if (employees[i].GetID() == id) {return (i);};};
    return(-1); //return -1 if not found
};

int EmployeesList::FindbyUsernameorID(std::string searchterm)const
{   // If the user enters a non-numeric string, the try fails and 
    // the catch searches by username. If the user enters a number
    // the try succeeds and the try searches by ID
    // returns the index of the user when found or -1 for failure
    int i = -1;
    try
    {
        int id = std::stoi(searchterm);
        i = FindUserbyID(id);
    }
    catch (...)
    {
        i = FindUserbyUsername(searchterm);
    };
    return(i);
};

std::vector<Employee> EmployeesList::FindbyName(std::string searchterm)const
{   //Looks for the employee by Name (or partial name)
    // returns a vector of matches or an empty vector if none found
    
    std::vector<Employee> matches;

    for (const Employee& employee : employees)
    {
        if (ToLower(employee.GetName()).find(searchterm) != std::string::npos)
            {matches.push_back(employee);};
    };
    return(matches); 
};

void EmployeesList::PrintEmployeesListShort(const std::vector<Employee>& empstoprint) const
{   // prints a list of employees in short form
    if (empstoprint.empty())
    {
        std::cout << "No employees to print.\n";
        return;
    }
    for (const Employee& employee : empstoprint)
        {employee.PrintShortEmployee();};
};

void EmployeesList::MakeSomeEmployees() 
{   // makes some dummy employees for testing
    // if you add more, PLEASE keep the IDs sequential
    // so that you don't break currMaxID
    // Yes, this is not bulletproof, but it's only to make testing
    // easier for the grader.
    
    employees.push_back(
        Employee("Renee Resource", "renee", "passwordHR", 1001, 
            Permissions(true, true, true, true, true, true)));

    employees.push_back(
        Employee("Manny Manager", "manny", "passwordM", 1002, 
            Permissions(true, true, true, false, false, false)));

    employees.push_back(
        Employee("Emmiline Employee", "emmy", "passwordE", 1003, 
            Permissions(true, false, false, false, false, false)));
    
    employees.push_back(
        Employee("Emmiline2 Employee2", "emmy2", "passwordE", 1004, 
            Permissions(true, false, false, false, false, false)));
    
    currMaxID = 1000 + employees.size();
};

void EmployeesList::ViewSelf(const Login& login) const
{   // Prints the employee record of the currently logged in user
    // fancy address to login because of circular .h reference 
    // just a login object. 
    std::cout << login.GetUserIn();
};

void EmployeesList::ViewOther() const
{   // Searches for and prints an employee other than the user
    // or an error message if there is no such user
    // Permissions have already been confirmed

    std::string searchterm;
    std::cout << "Specify employee to print by username or id:\n";
    std::getline(std::cin >> std::ws, searchterm);

    int i = FindbyUsernameorID(searchterm);
    if (i > -1){ std::cout << employees[i];}
    else {std::cout << "Did not find a user with that information.\n";}
};

void EmployeesList::Search() const
{   // Searches for employee(s) by name. 
    // Prints a list of potential matches
    std::string searchterm;

    std::cout << "Specify employee by Name (partial okay, case insensitive):\n";
    std::getline(std::cin >> std::ws, searchterm);

    std::vector<Employee>  matches = FindbyName(searchterm);
    std::cout << matches.size() << " matches found.\n";
    PrintEmployeesListShort(matches);
    std::cout << "\nUse viewother and the username or ID shown here\n\tto view an employee.\n";
};

std::string EmployeesList::GetConfirmedName(bool allowSkip) const
{   // A helper function for Add() and Modify()
    // allows <return> to skip for Modify()
    // Requires Y for confirmation to protect against typos
    std::string name, response;
    while (true)
    {    
        std::cout << "Enter the Employee's full name:\n";
        std::getline(std::cin, name);
        name = Trim(name);
        // <return> to skip for Modify()
        if (allowSkip && name.empty()) {return name;};
        std::cout << name << "\nIs this correct?(Y/n):\n";
        std::getline(std::cin >> std::ws, response);
        // if response is Y, the loop breaks and accepts the name
        if (response == "Y") { break;}
        //if response is 'n' or anything else, the loop continues
    };
    return(name);
};

std::string EmployeesList::GetUniqueUsername(bool allowSkip) const
{   // Gets a unique username
    // A helper function for Add() and Modify()
    // allows <return> to skip for Modify()
    std::string user;
    int uniq;
    do
    {
        std::cout << "Enter a unique username:\n";
        std::getline(std::cin, user);
        user = Trim(user);
        if (allowSkip && user.empty()) {return user;};
        uniq = FindUserbyUsername(user);
        if (uniq != -1) 
            {std::cout << user << " is already in use.\n";};
    } while (uniq != -1); // -1 means username is found ie not unique
    return(user);
};


int EmployeesList::GetUniqueID() const
{   // originally construed as a helper function for Add()
    // deprecated in final revision, with IDs set automatically
    // code retained for portential future use or modification
    int uniq, id;
    std::string ID;

    do
    {
        std::cout << "Enter a valid unique ID number (integer only):\n";
        std::getline(std::cin >> std::ws, ID);

        try
        {
            size_t pos;
            id = std::stoi(ID, &pos);

            if (pos != ID.length())
                { throw std::invalid_argument("Not a pure integer");};

            uniq = FindUserbyID(id);

            if (uniq != -1)
                { std::cout << "That ID is already in use.\n";};
        }
        catch (...)
        {
            std::cout << "That is not a valid integer ID.\n";
            uniq = 0; 
        }
    } while (uniq != -1);
    return(id);
};

Permissions EmployeesList::GetPermissionsPreset() const
{   // returns preset permissions for HR, Managers, employees
    Permissions perms;
    char response;
    do
    {
        std::cout << "At present, you may preset permissions by role.\n"
            << "Set permissions for HR(r), Manager(m), General Employee(e): (r/m/e)\n";
        std::cin >> response;
    } while (response != 'r' && response != 'm' && response != 'e');
    // flush the buffer to get rid of stray <return>s
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    switch (response)
    {
        case 'r':
            perms = Permissions::HRPerms();
            break;
        case 'm':
            perms = Permissions::ManagerPerms();
            break;
        case 'e':
            perms = Permissions::EmployeePerms();
            break;
    };
    return(perms);
};

char EmployeesList::AddPreflight() const
{   // Performs preflight search to make sure user is not adding
    // an employee that already exists, somewhat similar to Search

    std::string searchterm, response;
    // Employee precheck: does this employee exist already
    std::cout << "Before adding an employee, make sure it doesn't exist already.\n"
        << "Specify employee by Name (partial okay, case insensitive):\n";
    std::getline(std::cin >> std::ws, searchterm);
    std::vector<Employee>  matches = FindbyName(searchterm);
    if (!matches.empty())
    {
        PrintEmployeesListShort(matches);
        do
        {
            std::cout << "Add a new employee or modify an existing one? (a/m): ";
            std::getline(std::cin >> std::ws, response);
        }
        while (response != "a" && response != "m"); 
    };
    return(response[0]);
};

void EmployeesList::Add(Login login)
{   // Adds a new employee with necessary input verification
    // checks if employee exists and offers a path to Modify()
    std::string name, user, ID, pwd;
    int id;
    Permissions perms;

    if (AddPreflight() == 'm') { Modify(login); return;};
    name = GetConfirmedName();
    user = GetUniqueUsername();
    id = ++currMaxID;
    perms = GetPermissionsPreset();
    pwd = Employee::GeneratePassword();
    Employee newemp = Employee(name, user, pwd, id, perms);
    employees.push_back(newemp);
    std::cout << "New employee added.\n" << newemp << "\n"
        << "Temporary Password: " << pwd << "\n\n";
    return;
};

void EmployeesList::Modify(Login login)
{   // Modifies existing employee: Name, Username, Permissions (not ID)
    int i;
    std::string newname, newuser, responsestr;
    Permissions newperms;
    char response;

    do
    {   // finds the employee to modify and prints that employee
        std::string searchterm;

        std::cout << "Specify the employee to modify by username or id,\n"
            << "or (b) to back out and run a search at the command prompt:\n";
        std::getline(std::cin >> std::ws, searchterm);
        if (searchterm == "b"){return;};

        i = FindbyUsernameorID(searchterm);
        if (i > -1){ std::cout << employees[i];}
        else {std::cout << "Did not find a user with that information.\n";}
    } while (i == -1);

    Employee& employee = employees[i];
    std::cout << "You may change the employee Name, UserName and Permissions.\n"
        << "ID may not be changed.\n\n";
    
    std::cout << "Employee name: " << employee.GetName() << "\n"
        << "Enter a new name or hit return to skip:\n";
    newname = GetConfirmedName(true);
    if (!newname.empty()){employee.SetName(newname);};
    std::cout << "Employee username: " << employee.GetUsername() << "\n"
        << "Enter a new name or hit return to skip:\n";
    newuser = GetUniqueUsername(true);
    if (!newuser.empty()){employee.SetUsername(newuser);};

    // Checks/validates if user wants to modify permissions
    // does not permit a user to modify their own permissions
    // to prevent disaster where user removes permissions
    // while needing the permission. In the real world, 
    // a superior (even in HR) would need to modify an HR user's perms.
    if (login.GetUserIn().GetID() != employee.GetID())
    {
        do
        {
            std::cout << "Would you like to change the permissions? (Y/n)\n";
            std::getline(std::cin >> std::ws, responsestr);
        } while (responsestr != "Y" && responsestr != "n");
        if (responsestr == "Y"){employee.SetPermissions(GetPermissionsPreset());};
    }
    else {std::cout << "Sorry, but you cannot modify your own permissions.\n";}

    std::cout << "You have modified the employee:\n" << employee;
};

void EmployeesList::Remove()
{   // Removed an employee from the EmployeeList
    // Finds and removes employee, requires validted confirmation
    std::string searchterm;
    std::cout << "Specify employee to remove by username or id:\n";
    std::getline(std::cin >> std::ws, searchterm);

    int i = FindbyUsernameorID(searchterm);

    if (i > -1) // -1 is not found
        { 
            std::cout << "Employee found:\n"
                << employees[i];
            std::string response;
            do // validates confirmation to remove
            {   
                std::cout << "Are you sure you'd like to remove this employee? (Y/n)";
                std::getline(std::cin >> std::ws, response);
            } while (response != "Y" && response != "n");
            if (response == "Y")
            {
                employees.erase(employees.begin() + i);
                std::cout << "Employee identified by " << searchterm   
                    << " was removed from the Employee list.\n\n";
                PrintEmployeesListShort(employees);
            }
            else {std::cout << "Employee was not removed.\n\n";}; //'n'
        }
    else {std::cout << "Did not find an employee with that informtion.\n\n";};
};

// © Mary E Tyler 2026