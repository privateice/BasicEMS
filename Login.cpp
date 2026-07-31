#include "Login.h"

int Login::ProcessAuthentication( EmployeesList emp,
                    std::string username, 
                    std::string pwd) 
{
    int userindex = emp.FindUserbyUsername(username);
    if (userindex > -1 ) {
        Employee employee = emp.GetEmployees()[userindex];
        bool check = employee.CheckPassword(pwd);
        if (check){ userin = employee;  };
        return(check);
    };
    return(-1);
};

int Login::ProcessLogin(EmployeesList emp)
{   std::string user, pwd;
    int rescode = -2;
    do
    {   
        std::cout << "Please log in to use the EMS or 'exit' to abort.\n";
        do
        {
            std::cout << "Please enter your username:\n";
            std::getline(std::cin, user);
        } while (user.empty());
        if (user == "exit"){break;}
        do
        {
            std::cout << "Please enter your password:\n";
            std::getline(std::cin, pwd);
        } while (pwd.empty());
        if (pwd == "exit"){break;}
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
    return (rescode);
};

