//
//  SettingsManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 24/04/2024.
//

#include "SettingsManager.hpp"
#include "ResourceContainer.hpp"

DifficultyLevel SettingsManager::currentDifficulty() {
    std::string dif_str = fileManager.readFromFile(SETTINGS_FILE_NAME);
    return helper.stringToDifficulty(dif_str);
}

void SettingsManager::setDifficulty(DifficultyLevel difficulty) {
    fileManager.rewriteFile(SETTINGS_FILE_NAME, helper.difficultyToString(difficulty));
}

void SettingsManager::resetDifficulty() {
    fileManager.rewriteFile(SETTINGS_FILE_NAME, "");
}
