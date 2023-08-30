#include "../src/user.cpp"
#include "../src/timeline.cpp"

class Instagram
{
    private:
        std::string login();
        void menu(std::string);
    public:
        Instagram();
        static bool validateFileLocation(std::string);
};