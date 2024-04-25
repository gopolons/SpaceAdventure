//
//  ScoreManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 20/04/2024.
//

#include "ScoreManager.hpp"
#include "ResourceContainer.hpp"

int ScoreManager::topScore() {
    // get the score string and filter it
    std::string scoreString = fileManager.readFromFile(HIGHSCORE_FILE_NAME);
    scoreString.erase(std::remove_if(scoreString.begin(), scoreString.end(), [](char c) { return !(std::isalnum(c)); }), scoreString.end());
    
    if (scoreString.empty()) {
        return 0;
    } else {
        return stoi(scoreString);
    }
}

bool ScoreManager::registerGameOver(int score) {
    int highScore = topScore();
    
    if (highScore < score) {
        fileManager.rewriteFile(HIGHSCORE_FILE_NAME, std::to_string(score));
        return true;
    } else {
        return false;
    }
}

void ScoreManager::resetScore() {
    fileManager.rewriteFile(HIGHSCORE_FILE_NAME, std::to_string(0));
}
