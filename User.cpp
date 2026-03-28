#include "User.h"
#include <iostream>
#include <fstream>
#include <functional>

void User::registerUser() {
    string username, password;

    cout << "Enter new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    string hashed = hashPassword(password);

    ofstream file("users.txt", ios::app);
    file << username << " " << hashed << endl;

    cout << "Registration successful!\n";
}

bool User::loginUser(string& loggedInUser) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string hashedInput = hashPassword(password);

    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username && p == hashedInput) {
            cout << "Login successful!\n";
            loggedInUser = username;
            return true;
        }
    }

    cout << "Invalid username or password.\n";
    return false;
}

bool User::adminLogin() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "Admin login successful!\n";
        return true;
    }

    cout << "Invalid admin credentials.\n";
    return false;
}
