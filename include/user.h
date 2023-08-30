#include <iostream>
#include <string>
#include <set>
#include <map>

const std::string UserInfoFilePath = "./data/UserInfo.txt";
const std::string timelinePath = "./data/timeline.txt";
class User 
{
    private:
        std::string name, userName, location, gender, password, bio;
        void setPassword();
        void setUsername();
        std::set<std::string> getUsernames();

    public:
        User();
        ~User();
};
