#include "User.h"
#include <iostream>
#include <fstream>
#include <functional>

using namespace std ;


string User::hashPassword(string password){ //for hashing password
    hash <string> hasher ;
    return to_string(hasher(password)) ;
}


bool User::userExists(string user_name){ //to check if user exist or not
    ifstream file("users.txt") ;
    string u, p ;

    while(file >> u >> p)
    {
        if (u == user_name) return true ;
    }
    
    return false ;

}


void User::registerUser(){ //register new user
    string user_name, passw ;

    cout <<"Enter new username : " ;
    cin >> user_name ;

    if(userExists(user_name))
        {
        cout << "| Username already exists.. |\n" ;
        return ;
        }

    cout <<"Enter password : " ;
    cin >> passw ;

    string hashed = hashPassword(passw) ;

    ofstream file("users.txt", ios::app);
    file << user_name <<" "<< hashed << endl ;

    cout <<"| Registration successful.. |\n" ;
}


bool User::loginUser(string& loggedInUser){ //login existing user
    string user_name, passw;

    cout <<"Enter username : " ;
    cin >> user_name;
    cout <<"Enter password : " ;
    cin >> passw ;

    string hashedInput = hashPassword(passw) ;

    ifstream file("users.txt") ;
    string u, p ;

    while(file >> u >> p)
    {
        if (u == user_name && p == hashedInput) 
        {
            cout <<"Login Successful\n" ;
            loggedInUser = user_name ;
            return true ;
        }
    }

    cout <<"| Invalid user username or password.. |\n" ;


    return false ;
}


bool User::adminLogin(){  //login page of admin
    string user_name, passw ;

    cout <<"Enter Username: " ;
    cin >> user_name ;
    cout <<"Enter Password: " ;
    cin >> passw ;

    if(user_name == "admin" && passw == "admin123")
    {
        cout <<"admin login successful..\n" ;
        return true ;
    }

    cout <<" | Invalid admin username Or password.. |\n" ;


    return false ;
}
