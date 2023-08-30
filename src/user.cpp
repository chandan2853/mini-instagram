#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include "../include/user.h"
#include "./userUtility.cpp"

User::User() 
{
    User::setUsername();
    User::setPassword();
    std::cout << "Enter Name: ";
    getline(std::cin, name);
    std::cout << "Enter Gender: " ;
    std::cin >> gender;
    std::cin.ignore();
    std::cout << "Enter Bio: ";
    getline(std::cin, bio);
    std::cout << "Enter Location: " ;
    getline(std::cin, location);
}

User::~User() 
{
    std::fstream outFile(UserInfoFilePath, std::ios_base::app);
    if(!outFile.is_open() && outFile.fail()) 
    {
        std::cout << "File failed to open" << std::endl;
    }
    outFile << userName << std::endl << password << std::endl << name << std::endl << gender << std::endl << bio << std::endl << location << std::endl;
    outFile.close();
}

std::set<std::string> User::getUsernames() 
{
    std::fstream inputFile;
    inputFile.open(UserInfoFilePath);
    std::set<std::string> usernames;
    std::string username, tempstr;
    while (inputFile >> username) 
    {
        usernames.insert(username);
        for(int i=0; i<=5; i++)
        {
            getline(inputFile,tempstr);
        }
        
    }
    inputFile.close();
    return usernames;
}

void User::setUsername() 
{
    std::set<std::string> userNames = getUsernames();
    bool flag = true;
    do 
    {
        std::cout << "Enter Username: ";
        getline(std::cin, userName);
        if (userNames.find(userName) != userNames.end()) 
        {
            std::cout <<"Username already exist !! Try again: \n";
        } 
        else 
        {
            flag = false;
        }
    } while (flag);
}

void User::setPassword() 
{
    bool flag = true;
    do 
    {
        password = getpass("Enter your Password: ");
        if (!UserUtility::validPassword(password)) 
        {
            std::cout << "Not a valid Password !! Try again: \n";
        } 
        else 
        {
            flag = false;
        }
    } while (flag);
    password = UserUtility::encryptPassword(password);
}
