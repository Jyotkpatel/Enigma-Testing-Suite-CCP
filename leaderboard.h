#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>

class Leaderboard {
public:
    void saveScore(const std::string& username, int score);
    void showLeaderboard();
};

#endif
