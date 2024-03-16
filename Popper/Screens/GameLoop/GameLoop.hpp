//
//  GameLoop.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#ifndef GameLoop_hpp
#define GameLoop_hpp

#include <SFML/Graphics.hpp>

class GameLoop {
public:
    GameLoop(sf::RenderWindow& window);
    
    void startGame();
private:
    sf::RenderWindow& window;
    
    float shipAngle = 0;
    sf::Vector2f shipPosition;
    
    void handleInput(sf::Sprite& spaceshipSprite);
    
    void drawSpaceshipSprite(sf::Sprite& spaceshipSprite);
};

#endif /* GameLoop_hpp */
