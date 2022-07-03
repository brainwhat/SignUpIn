#include <iostream>
#include <string>
#include <fstream>
#include "funcs.hpp"
using namespace std;

struct User
{
    string login;
    string password;
};

int main(int argc, const char * argv[])
{
    User *info;
    info = new User[100];
    ifstream bazaDannih("/Users/vasilijfrolov/Desktop/simplest projects/SIgn up an Sign in/SIgn up an Sign in/UsersData.txt");
    for(int i=99;i>0;i--) // we write data from file to the back of our array
    {                     // so we can write user input to the beginning
        bazaDannih >> info[i].login >> info[i].password;
    }                     // obvious drawback is that when the number of users is over 100
    // we will meet problems
    menu(info);           // so i need to think about the way to append array
    //every time we get new input
}
