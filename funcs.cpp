#include <string>
#include <iostream>
#include <fstream>
#include "funcs.hpp"

using namespace std;

struct User
{
    string login;
    string password;
};

void SignUp(User *info, int n)
{   // here we get data from user and write it to our file
    ofstream baza("/Users/vasilijfrolov/Desktop/simplest projects/SIgn up an Sign in/SIgn up an Sign in/UsersData.txt",ios_base::app);
    cout<<"Put you login in"<<endl;
    cin>>info[n].login;
    cout<<"Put you password in"<<endl;
    cin>>info[n].password;
    baza << info[n].login <<" "<< info[n].password<<"\n";
    
}

void SignIn(User *info)
{
    string log, pass;
    cout<<"Enter your login: ";
    cin>>log;              // the following cycle finds similarities first in logins
    for(int i=0;i<100;i++) // then in passwords
    {
        if(log == info[i].login)
        {
            cout<<"Enter you password: ";
            againPassword:
            cin>>pass;
            if(pass == info[i].password)
            {
                cout<<"Welcome, "<<log<<endl;
                exit(0);    // if everything matches we exit
            }
            else
            {
                cout<<"Wrong one, try again";
                goto againPassword; // if login matches but password doesn't
                // we make user try again
                // so this program doesn't allow users with identical logins
            }
            break;
        }
    }
    
}

void menu(User *info)
{   // user sees a menu where ge can either sign up or sign in
    int option, placeNum=0;
    do{
        cout << "Do you want to sign up(1) or sign in(2)?"<<endl;
        cin >> option;
        switch(option)
        {
            case 1:SignUp(info,placeNum);
                placeNum++;
                break;
            case 2:SignIn(info);
                break;
            case 0:
                break;
            default:
                cout<<"Choose other option"<<endl;
        }
    }
    while (option!=0);
}
