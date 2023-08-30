#include <iostream>
#include <string>
#include <set>
#include <map>
class UserUtility
{
    public:
        static bool validPassword(std::string);
        static std::string encryptPassword(std::string);
        static std::string getDecryptedPassword(std::string);
        static bool isValidUser(std::string, std::string);
        static std::map<std::string, std::string> getUsernamesAndPasswords();

};