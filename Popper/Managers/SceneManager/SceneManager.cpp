//
//  SceneManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 14/04/2024.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(SceneManagerDelegate* gameLoop, SceneManagerDelegate* mainMenu, SceneManagerDelegate* gameOver) : gameLoop(gameLoop), mainMenu(mainMenu), gameOver(gameOver) {
    std::any any_pointer = this;
    
    gameLoop->setSceneManager(any_pointer);
    mainMenu->setSceneManager(any_pointer);
    gameOver->setSceneManager(any_pointer);
    
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
        default:
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
    }
}

void SceneManager::goToGame() {
    scene = GameScene::Game;
}

void SceneManager::goToMenu() {
    scene = GameScene::Menu;
}

void SceneManager::goToGameOver() {
    scene = GameScene::GameOver;
}
