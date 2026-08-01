#include "EmployeesList.h"
#include "Login.h"

EmployeesList::EmployeesList() 
{
    MakeSomeEmployees();
};

int EmployeesList::FindUserbyUsername(std::string username) const
{   //Looks for the employee, returns the index or -1 if not found
    // loop through the employees
    for (size_t i = 0; i < employees.size(); i++)
    {   // look for the username and return the index
        if (employees[i].GetUsername() == username) {return (i);};
    }
    return(-1); //return -1 if not found
};

int EmployeesList::FindUserbyID(int id) const
{   //Looks for the employee, returns the index or -1 if not found
    // loop through the employees
    for (size_t i = 0; i < employees.size(); i++)
    {   // look for the username and return the index
        if (employees[i].GetID() == id) {return (i);};
    }
    return(-1); //return -1 if not found
};

int EmployeesList::FindbyUsernameorID(std::string searchterm)const
{   // If the user enters a non-numeric string, the try fails and 
    // the catch searches by username. If the user enters a number
    // the try succeeds and the try searches by ID
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
{   //Looks for the employee by name
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
{
    if (empstoprint.empty())
    {
        std::cout << "No employees to print.\n";
        return;
    }
    for (const Employee& employee : empstoprint)
        {employee.PrintShortEmployee();};
};

void EmployeesList::MakeSomeEmployees() 
{   //just makes some dummy employees for testing
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
};

void EmployeesList::ViewSelf(const Login& login) const
{
    std::cout << login.GetUserIn();
};

void EmployeesList::ViewOther() const
{   // Searches for and print an employee other than the user
    // Permissions have already been confirmed

    std::string searchterm;
    std::cout << "Specify employee by username or id:\n";
    std::cin >> searchterm;

    int i = FindbyUsernameorID(searchterm);
    if (i > -1){ std::cout << employees[i];}
    else {std::cout << "Did not find a user with that informtion.\n";}
};

void EmployeesList::Search() const
{
    std::string searchterm;

    std::cout << "Specify employee by username or id:\n";
    std::cin >> searchterm;

    std::vector<Employee>  matches = FindbyName(searchterm);
    std::cout << matches.size() << " matches found.\n";
    PrintEmployeesListShort(matches);
    std::cout << "\nUse viewother and the username or ID shown here\n\tto view an employee.\n";
};

void EmployeesList::Add()
{
};

void EmployeesList::Modify()
{
};

void EmployeesList::Remove()
{
    std::string searchterm;
    std::cout << "Specify employee to remove by username or id:\n";
    std::cin >> searchterm;

    int i = FindbyUsernameorID(searchterm);

    if (i > -1)
        { 
            std::cout << "Employee found:\n"
                << employees[i];
            char response;
            do
            {   
                std::cout << "Are you sure you'd like to remove this employee? (Y/n)";
                std::cin >> response;
            } while (response != 'Y' && response != 'n');
            if (response == 'Y')
            {
                employees.erase(employees.begin() + i);
                std::cout << "Employee identified by " << searchterm   
                    << " was removed from the Employee list.\n\n";
                PrintEmployeesListShort(employees);
            }
            else {std::cout << "Employee was not removed.\n\n";};
        }
    else {std::cout << "Did not find an employee with that informtion.\n\n";};
};