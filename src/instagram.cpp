#include <iostream>
#include "../include/instagram.h"


Instagram::Instagram() 
{

    Instagram::validateFileLocation(UserInfoFilePath);
    Instagram::validateFileLocation(timelinePath);
    
    int choice=0;
    do 
    {
        system("clear");
        std::cout << "**********Instagram**********" << std::endl;
        std::cout << "1. SignUp" << std::endl << "2. Login " << std::endl << "3. Exit " << std::endl;
        std::cout << "Enter Your choice: ";
        std::cin >> choice;
        if(std::cin.fail())
        {
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
            choice = 0;
        }
        std::cin.ignore();
        if (choice == 1) 
        {
            User createNewUser;
        } 
        else if (choice == 2) 
        {
            std::string user_name = login();
            if(user_name.size() != 0) 
            {
                menu(user_name);
            }
        } 
        else if (choice == 3) 
        {
            break;
        } 
        else 
        {
            std::cout << "Not a valid choice !! Try again. " << std::endl;
        }
    }while(true);
    std::cout << "Thank You for using Instagram!!" << std::endl;
}

std::string Instagram::login() 
{
    std::string userName, password;
    std::cout << "Enter Username: ";
    getline(std::cin,userName);
    password = getpass("Enter your Password: ");
    if (UserUtility::isValidUser(userName, password)) 
    {
        std::cout << "Login successfully." << std::endl;
        return userName;
    }
    std::cout << "Username/Password is not valid!! Try again." << std::endl;
    return "";
}
void Instagram::menu(std::string userName)
{
    int choice;
    while(true)
    {
        std::cout << "*********Menu*********" << std::endl;
        std::cout << "1.Display Profile \n2.Post on timeline \n3.See Post \n4.Sign Out " << std::endl;
        std::cout << "Enter choice : ";
        std::cin >> choice;
        if(std::cin.fail())
        {
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
            std::cout << "Invalid input,Give Integer value" << std::endl;
            choice=0;
        }
        else
        {
            Timeline timeline;
            if(choice == 1)
            {
                timeline.showProfile();
            }
            else if(choice == 2)
            {
                timeline.postOnTimeline(userName);
            }
            else if(choice == 3)
            {
                timeline.seePost(userName);
            }
            else if(choice == 4)
            {
                break;
            }
            else
            {
                std::cout << "Wrong Choice!" << std::endl;
            }
        }
    }
}
bool Instagram::validateFileLocation(std::string filePath)
{
    std::ifstream filein;
    filein.open(filePath);
    if(filein)
    {
        filein.close();
        return true;
    }
    else
    {
        std::ofstream fileout;
        fileout.open(filePath);
        fileout.close();
        return false;
    }
    
}