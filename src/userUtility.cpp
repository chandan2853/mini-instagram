#include "../include/userUtility.h"

bool UserUtility::validPassword(std::string password) 
{
    bool hasChar=false, hasDigit=false;
    for (auto &character : password) 
    {
        hasChar |= (character >= 'a' and character <= 'z');
        hasChar |= (character >= 'A' and character <= 'Z');
        hasDigit |= (character >= '0' and character <= '9');
    }
    if (password.size() >= 8 and hasChar and hasDigit) 
    {
        return true;
    } 
    return false;
}

std::string UserUtility::encryptPassword(std::string password) 
{
    for (auto &character: password) 
    {
        character += 5;
    }
    return password;
}

std::string UserUtility::getDecryptedPassword(std::string password) 
{
    std::string tempPassword = "";
    for (auto character : password) {
        tempPassword += char(character - 5);
    }
    return tempPassword;
}

std::map<std::string,std::string> UserUtility::getUsernamesAndPasswords() 
{
    std::fstream inputFile;
    inputFile.open(UserInfoFilePath);
    std::map<std::string,std::string> usernameAndPasswords;
    std::string username, password, tempstr;
    while (inputFile >> username) 
    {        
        inputFile >> password;
        password = getDecryptedPassword(password);
        usernameAndPasswords[username] = password ;
        for(int i=0; i<=4; i++)
        {
            getline(inputFile, tempstr);
        }
    }
    inputFile.close();
    return usernameAndPasswords;
}

bool UserUtility::isValidUser(std::string userName, std::string password) 
{
    std::map<std::string,std::string>userandPassword = getUsernamesAndPasswords();
    auto itr = userandPassword.find(userName);
    if (itr == userandPassword.end() or itr->second != password) 
    {
        return false;
    }
    return true;
}