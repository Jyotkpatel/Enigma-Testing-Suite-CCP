#include <iostream>
using namespace std ;
#include "Quiz.h"
#include "Leaderboard.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>



int Quiz::startQuiz(const string& username) {
    ifstream file("questions.txt");
    string line;
    int score = 0;
    int total = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> parts;
        string part;

        while (getline(ss, part, '|')) {
            parts.push_back(part);
        }

        if (parts.size() != 6) continue;

        cout << "\n" << parts[0] << endl;
        for (int i = 1; i <= 4; i++) {
            cout << i << ". " << parts[i] << endl;
        }

        int answer;
        cout << "Your answer: ";
        cin >> answer;

        if (to_string(answer) == parts[5]) {
            score++;
        }

        total++;
    }

    cout << "\nQuiz completed!\n";
    cout << "Your score: " << score << " / " << total << endl;

    
    Leaderboard lb;
    lb.saveScore(username, score);

    return score;
}
