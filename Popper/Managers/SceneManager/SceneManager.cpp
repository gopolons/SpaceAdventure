//
//  SceneManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 14/04/2024.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(SceneManagerDelegate* gameLoop, SceneManagerDelegate* mainMenu, SceneManagerDelegate* gameOver, SceneManagerDelegate* settings) : gameLoop(gameLoop), mainMenu(mainMenu), gameOver(gameOver), settingsMenu(settings) {
    std::any any_pointer = this;
    
    gameLoop->setSceneManager(any_pointer);
    mainMenu->setSceneManager(any_pointer);
    gameOver->setSceneManager(any_pointer);
    settingsMenu->setSceneManager(any_pointer);
    
    scene = GameScene::Menu;
};

void SceneManager::runActiveScene() {
    switch (scene) {
        case (GameScene::Menu):
            mainMenu->run();
            return;
        case (GameScene::Game):
            gameLoop->run();
            return;
        case (GameScene::GameOver):
            gameOver->run();
            return;
        case (GameScene::SettingsMenu):
            settingsMenu->run();
            return;
    }
}

std::any SceneManager::getCurrentInputDelegate() {
    std::any anyValue;
    switch (scene) {
        case (GameScene::Menu):
            anyValue = mainMenu->getInputDelegate();
            return anyValue;
        case (GameScene::Game):
            anyValue = gameLoop->getInputDelegate();
            return anyValue;
        case (GameScene::GameOver):
            anyValue = gameOver->getInputDelegate();
            return anyValue;
        case (GameScene::SettingsMenu):
            anyValue = settingsMenu->getInputDelegate();
            return anyValue;
    }
}

void SceneManager::goToGame() {
    scene = GameScene::Game;
}

void SceneManager::goToMenu() {
    int highScore = scoreManager.topScore();
    SceneSetupData data{ highScore };
    mainMenu->setup(data);
    scene = GameScene::Menu;
}

void SceneManager::goToGameOver(int score) {
    bool isHighScore = scoreManager.registerGameOver(score);
    SceneSetupData data = { score, isHighScore };
    gameOver->setup(data);
    scene = GameScene::GameOver;
}

void SceneManager::saveSettings(SceneSetupData data) {
    settingsManager.setDifficulty(data.difficulty);
    
    if (data.reset) {
        settingsManager.resetDifficulty();
        scoreManager.resetScore();
    }
    scene = GameScene::Menu;
}

void SceneManager::goToSettings() {
    DifficultyLevel currentDifficulty = settingsManager.currentDifficulty();
    int highScore = scoreManager.topScore();
    SceneSetupData data{ highScore, false, currentDifficulty, false };
    settingsMenu->setup(data);
    scene = GameScene::SettingsMenu;
}
