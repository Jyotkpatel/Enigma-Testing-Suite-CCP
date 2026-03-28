#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Add new question
void Admin::addQuestion() {
    string question, opt1, opt2, opt3, opt4;
    int correct;

    cin.ignore(); // clear input buffer

    cout << "Enter question: ";
    getline(cin, question);

    cout << "Enter option 1: ";
    getline(cin, opt1);

    cout << "Enter option 2: ";
    getline(cin, opt2);

    cout << "Enter option 3: ";
    getline(cin, opt3);

    cout << "Enter option 4: ";
    getline(cin, opt4);

    cout << "Enter correct option number (1-4): ";
    cin >> correct;

    ofstream file("questions.txt", ios::app);
    file << question << "|"
         << opt1 << "|"
         << opt2 << "|"
         << opt3 << "|"
         << opt4 << "|"
         << correct << endl;

    cout << "Question added successfully!\n";
}

// View all questions
void Admin::viewQuestions() {
    ifstream file("questions.txt");
    string line;
    int qNo = 1;

    cout << "\n=== ALL QUESTIONS ===\n";
    while (getline(file, line)) {
        cout << qNo++ << ". " << line << endl;
    }
}