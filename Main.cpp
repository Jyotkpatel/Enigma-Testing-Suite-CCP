#include <iostream>
#include "User.h"
#include "Quiz.h"
#include "Leaderboard.h"
#include "Admin.h"

using namespace std;

int main() {
    User user;
    Quiz quiz;
    Leaderboard lb;
    Admin admin;

    int choice;
    string loggedInUser;

    while (true) {
        cout << "\n=== QUIZ SYSTEM ===\n";
        cout << "1. Register\n";
        cout << "2. Login & Take Quiz\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            user.registerUser();
            break;

        case 2:
            if (user.loginUser(loggedInUser)) {
                quiz.startQuiz(loggedInUser);
            }
            break;

        case 3:
            if (user.adminLogin()) {
                int adminChoice;
                while (true) {
                    cout << "\n=== ADMIN PANEL ===\n";
                    cout << "1. View Leaderboard\n";
                    cout << "2. Add Question\n";
                    cout << "3. View Questions\n";
                    cout << "4. Logout\n";
                    cout << "Enter choice: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        lb.showLeaderboard();
                    }
                    else if (adminChoice == 2) {
                        admin.addQuestion();
                    }
                    else if (adminChoice == 3) {
                        admin.viewQuestions();
                    }
                    else if (adminChoice == 4) {
                        break;
                    }
                    else {
                        cout << "Invalid choice!\n";
                    }
                }
            }
            break;

        case 4:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}