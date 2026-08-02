#include "Login.h"

int Login::ProcessAuthentication( EmployeesList emp,
                    std::string username, 
                    std::string pwd) 
{   // Finds the user and authenticates the password
    // In:  EmployeesList emp - the list of all employees
    //      std::string username - the username of the employee logging in
    //      std::string pwd - the password to authenticate
    int userindex = emp.FindUserbyUsername(username);
    if (userindex > -1 ) {
        Employee employee = emp.GetEmployees()[userindex];
        bool check = employee.CheckPassword(pwd);
        if (check){ userin = employee;  };
        return(check); // returns 0 incorrect passwor, or 1 authenticated
    };
    return(-1); // returns -1 if no employee is found with that username
};

int Login::ProcessLogin(EmployeesList emp)
{   // Processes the login, returns a success/failure code
    // User must successfully log in or exit the program

    std::string user, pwd;
    int rescode = -2;
    do
    {   // repeats login process until user logs in or exits
        std::cout << "Please log in to use the EMS or 'exit' to abort.\n";
        do
        {   // gets a non empty username
            std::cout << "Please enter your username:\n";
            std::getline(std::cin, user);
        } while (user.empty());
        if (user == "exit"){break;}
        do
        {   // gets a non-empty password
            std::cout << "Please enter your password:\n";
            std::getline(std::cin, pwd);
        } while (pwd.empty());
        if (pwd == "exit"){break;}
        // if user enters garbage at any point in the process,
        // authentication fails.
        rescode = ProcessAuthentication(emp, user, pwd);
        switch (rescode) // rescode in {-1, 0, 1}
        {
        case -1: 
            std::cout << "There's no user by that name. Please try again.\n";
            break;
        case 0: 
            std::cout << "Password Incorrect! Please try again.\n";
            break;
        case 1:
            std::cout << "Welcome " << userin->GetName() 
                << "! Thanks for logging in.\n";
            break;
        }
    } while (rescode != 1);
    return (rescode); // rescode = 1
};

// © Mary E Tyler 2026