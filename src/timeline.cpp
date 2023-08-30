#include "../include/timeline.h"

void Timeline::showProfile()
{
    std::string uName;
    int flag=0;
    std::cout << "Enter Username: ";
    std::cin >> uName;
    std::fstream inputFile;
    inputFile.open(UserInfoFilePath);
    std::string username, tempstr, passwd, name, gender, bio, location;
    while (inputFile >> username) 
    {
        if(uName==username)
        {
            flag=1;
            inputFile >> tempstr;
            getline(inputFile, passwd);
            std::cout << "Username: " << username << std::endl;
            getline(inputFile, name);
            std::cout << "Name: " << name << std::endl;
            getline(inputFile, gender);
            std::cout << "Gender: " << gender << std::endl;
            getline(inputFile, bio);
            std::cout << "Bio: " << bio << std::endl;
            getline(inputFile, location);
            std::cout << "Location: " << location << std::endl;

        }
        else
        {
            for(int i=0; i<=4; i++)
            {
                inputFile >> tempstr;
            }
        }
       
    }
    if(flag==0)
    {
        std::cout << "User not found!" << std::endl;
    }
    inputFile.close();
}

void Timeline::postOnTimeline(std::string userName)
{
    std::ofstream fileout;
    std::string post;
    system ("clear");
    fileout.open (timelinePath,std::ios_base::app);
    std::cout << "Write what you want to post and press enter when you are done:";
    std::cin.ignore();
    getline(std::cin,post);
    fileout << userName <<std::endl <<post << std::endl;
    fileout <<"Posted by: "<< userName << std::endl;
    fileout <<"Liked by: " << " " << std::endl;
    std::cout << "Successfully Posted on Timeline." << std::endl;
    fileout.close();
    
}

void Timeline::seePost(std::string userName)
{
    system("clear");
    std::fstream file;
    file.open(timelinePath, std::fstream::ios_base::in);
    std::string line, word;
    int count=0, likeCount=0;
    std::cout<<"**********Timeline**********"<<std::endl;
    while(getline(file, line))
    {
        count++;
        std::cout << "**********" << count << "**********" << std::endl;
        if(line==userName)
        {
            getline(file, line);
            std::cout << line << std::endl;
            getline(file, line);
            std::cout << line << std::endl;
            getline(file, line);
            std::cout << line << std::endl;
        }
        else
        {
            getline(file, line);
            std::cout << line << std::endl;
            getline(file, line);
            std::cout << line << std::endl;
            getline(file, line);
        }
        std::stringstream ss(line);
        while (ss >> word)
        {
            likeCount++;
        }
        std::cout << "No. of Likes: " << likeCount-2 << std::endl << std::endl;
        likeCount=0;
    }
    file.close();
    int choice;
    std::cout << "Which Post you want to like else 0: " << std::endl;
    std::cin >> choice;
    if(choice!=0)
    {
        likePost(choice, count, userName);
    }    
}
bool Timeline::likePost(int choice, int count, std::string userName)
{
    if(choice <= count)
    {
        choice*=4;
        std::fstream file;
        std::string line,tstr="";
        file.open(timelinePath);
        file.seekg(0, std::ios::beg);
        for(int i=1; i<=choice; i++)
        {
            getline(file, line);
        }
        int flag=0;
        std::istringstream ss(line);
        std::string word;
        while(ss >> word) 
        {
            if(word==userName)
            {
                flag=1;
                break;
            }
            else
            {
                tstr+=(word+" ");
            }
        }
        
        if(flag==1)
        {
            std::string spaces=" ";
            for (int i=0; i<userName.size() ;i++)
            {
                spaces+=" ";
            }
            file.seekg(0, std::ios::beg);
            for(int i=1; i<choice; i++)
            {
                getline(file, line);
            }
            line.replace(line.begin(), line.end(),tstr);
            file << line+spaces;
            std::cout << "You unliked the post!" << std::endl;
        }
        else
        {
            file.seekg(0, std::ios::beg);
            for(int i=1; i<choice; i++)
            {
                getline(file, line);
            } 
            file << tstr+userName<<" ";
            std::cout << "You liked the post!" << std::endl;
        }
        return true;
    }
    std::cout << "Invalid Post!" << std::endl;
    return false;
}
