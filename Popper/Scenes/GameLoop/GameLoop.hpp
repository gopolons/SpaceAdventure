//
//  GameLoop.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#ifndef GameLoop_hpp
#define GameLoop_hpp

#include <SFML/Graphics.hpp>

#include "Projectile.hpp"
#include "InputDelegate.hpp"

class GameLoop : public InputDelegate {
public:
    GameLoop(sf::RenderWindow& window);
    
    void startGame();
    
    void handleActionButton() override;
    void handleLeftButton() override;
    void handleRightButton() override;
private:
    sf::RenderWindow& window;
    
    float shipAngle = 0;
    sf::Vector2f shipPosition;
    std::vector<Projectile> projectiles{};
    
    sf::Clock asteroidClock;
    std::vector<Projectile> asteroids{};
    
    void updateShipPosition();
    
    void drawSpaceshipSprite();
    void drawProjectileSprites();
    void drawAsteroidSprites();
    
    float screenRightEdge;
    float screenLeftEdge;
    float screenTopEdge;
    float screenBottomEdge;

    sf::Vector2f bottomLeftCorner;
    sf::Vector2f bottomRightCorner;
    sf::Vector2f topLeftCorner;
    sf::Vector2f topRightCorner;
};

#endif /* GameLoop_hpp */
