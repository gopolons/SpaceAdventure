//
//  GameOver.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 19/04/2024.
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include "InputDelegate.hpp"
#include "SceneManagerDelegate.hpp"
#include "SceneManager.hpp"
#include <SFML/Graphics.hpp>

class GameOver: public InputDelegate, public SceneManagerDelegate {
public:
    GameOver(sf::RenderWindow& window);
    
    void handleActionButton() override;
    
    void setSceneManager(std::any manager) override;
    void run() override;
    InputDelegate* getInputDelegate() override;
private:
    SceneManager* sceneManager;

    sf::RenderWindow& window;
    
    void showEndGameScreen();
    
    sf::Vector2f screenCenter;
};

#endif /* GameOver_hpp */
