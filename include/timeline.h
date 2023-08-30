#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string timelinepath = "./timeline.txt";
const std::string userInfoFilePath = "./data/UserInfo.txt";

class Timeline
{
    public:
        void showProfile();
        void postOnTimeline(std::string);
        void seePost(std::string);
        static bool likePost(int, int, std::string);

};