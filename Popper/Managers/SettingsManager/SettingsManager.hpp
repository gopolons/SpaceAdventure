//
//  SettingsManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 24/04/2024.
//

#ifndef SettingsManager_hpp
#define SettingsManager_hpp

#include <stdio.h>
#include <iostream>
#include "FileManager.hpp"
#include "DifficultyLevel.hpp"

class SettingsManager {
public:
    // returns current difficulty level
    DifficultyLevel currentDifficulty();
    
    // sets current difficulty level
    void setDifficulty(DifficultyLevel difficulty);
    
    // resets the difficulty level to default value
    void resetDifficulty();
private:
    FileManager fileManager;
    DifficultyLevelHelper helper;
};

#endif /* SettingsManager_hpp */
