//
//  ScoreManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 20/04/2024.
//

#ifndef ScoreManager_hpp
#define ScoreManager_hpp

#include "FileManager.hpp"
#include <stdio.h>

class ScoreManager {
public:
    // returns the top score
    int topScore();
    
    // takes in a new score and returns true if its the new high score
    bool registerGameOver(int score);
private:
    FileManager fileManager;
};

#endif /* ScoreManager_hpp */
