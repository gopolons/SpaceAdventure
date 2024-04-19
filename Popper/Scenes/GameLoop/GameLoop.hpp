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
#include "SceneManagerDelegate.hpp"
#include "SceneManager.hpp"

class GameLoop : public InputDelegate, public SceneManagerDelegate {
public:
    GameLoop(sf::RenderWindow& window);
    
    void handleActionButton() override;
    void handleLeftButton() override;
    void handleRightButton() override;
    void handleEscapeButton() override;
    
    void setSceneManager(std::any manager) override;
    void run() override;
    InputDelegate* getInputDelegate() override;
private:
    void startGame();
    void endGame();
    
    SceneManager* sceneManager;
    
    int gameScore = 0;
    
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
    void drawScore();
    
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
