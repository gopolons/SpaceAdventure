//
//  SceneManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <SFML/Graphics.hpp>

#include "GameLoop.hpp"
#include "MainMenu.hpp"
#include "GameScene.hpp"

class SceneManager {
public:
    SceneManager(sf::RenderWindow& window, MainMenu& menuScene, GameLoop& gameScene);
    
    void updateScene(GameScene scene);
private:
    sf::RenderWindow& window;
    
    MainMenu& menuScene;
    GameLoop& gameScene;
};

#endif /* SceneManager_hpp */
