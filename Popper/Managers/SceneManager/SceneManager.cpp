//
//  SceneManager.cpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow& window, MainMenu& menuScene, GameLoop& gameScene) : window(window), menuScene(menuScene), gameScene(gameScene) {}

void SceneManager::updateScene(GameScene scene) {
    switch (scene) {
        case GameScene::Menu:
            menuScene.drawTitleMenu();
            break;
        case GameScene::Game:
            gameScene.startGame();
            break;
        default:
            break;
    }
}
