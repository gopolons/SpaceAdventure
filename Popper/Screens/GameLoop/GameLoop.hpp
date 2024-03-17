//
//  GameLoop.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#ifndef GameLoop_hpp
#define GameLoop_hpp

#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "SpaceshipProjectile.hpp"

class GameLoop {
public:
    GameLoop(sf::RenderWindow& window);
    
    void startGame();
    void handleUserShot();
private:
    sf::RenderWindow& window;
    
    float shipAngle = 0;
    sf::Vector2f shipPosition;
    std::vector<SpaceshipProjectile> projectiles{};
    
    sf::Clock asteroidClock;
    std::vector<SpaceshipProjectile> asteroids{};
    
    void handleInput();
    
    void drawSpaceshipSprite();
    void drawProjectileSprites();
    void drawAsteroidSprites();
};

#endif /* GameLoop_hpp */
