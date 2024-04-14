//
//  GameLoop.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <iostream>
#include <cmath>

#include "GameLoop.hpp"
#include "ResourceContainer.hpp"

float convertToRadians(float degree) {
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

GameLoop::GameLoop(sf::RenderWindow& window) : window(window) {
    sf::Vector2u windowCenter = window.getSize();
    shipPosition = sf::Vector2f((windowCenter.x / 2), (windowCenter.y / 2));
    
    screenRightEdge = window.getSize().x;
    screenLeftEdge = 0;
    screenTopEdge = window.getSize().y;
    screenBottomEdge = 0;
    
    bottomLeftCorner = sf::Vector2f{ screenLeftEdge, screenBottomEdge };
    bottomRightCorner = sf::Vector2f{ screenRightEdge, screenBottomEdge };
    topLeftCorner = sf::Vector2f{ screenLeftEdge, screenTopEdge };
    topRightCorner = sf::Vector2f{ screenRightEdge, screenTopEdge };
}

void GameLoop::handleActionButton() {
    // Create projectiles if shoot button is pressed
    Projectile projectile{ shipAngle, shipPosition, shipPosition };
    projectiles.push_back(projectile);
}

void GameLoop::handleLeftButton() {
    shipAngle -= 0.25;
}

void GameLoop::handleRightButton() {
    shipAngle += 0.25;
}

void GameLoop::handleEscapeButton() {
    sceneManager->goToMenu();
}

void GameLoop::updateShipPosition() {
    // Calculate and update the ship's position
    sf::Vector2f newPosition;
    float speed = 0.3;
    float radianAngle = convertToRadians(shipAngle);
    float newY = shipPosition.y + speed * sin(radianAngle);
    float newX = shipPosition.x + speed * cos(radianAngle);
    
    newPosition.x = newX;
    newPosition.y = newY;
    
    shipPosition = newPosition;
    
    // Implement screen wrapping
    if (shipPosition.x > screenRightEdge) {
        shipPosition.x = screenLeftEdge;
    }
    
    if (shipPosition.x < screenLeftEdge) {
        shipPosition.x = screenRightEdge;
    }
    
    if (shipPosition.y > screenTopEdge) {
        shipPosition.y = screenBottomEdge;
    }
    
    if (shipPosition.y < screenBottomEdge) {
        shipPosition.y = screenTopEdge;
    }
}

void GameLoop::drawSpaceshipSprite() {
    // Create spaceship shadow
    sf::Sprite spaceshipShadowSprite;
    
    // Create spaceship texture
    sf::Texture spaceshipTexture;
    if (!spaceshipTexture.loadFromFile(SPACESHIP_PATH)) {
        std::cerr << "Failed to load spaceship sprite!" << std::endl;
        return;
    }
    
    // Set color and alpha on the shadow sprite
    sf::Color shadowColor = sf::Color::Black;
    shadowColor.a = 50;
    spaceshipShadowSprite.setColor(shadowColor);
    
    // Set texture on the shadow sprite
    spaceshipShadowSprite.setTexture(spaceshipTexture);
    
    // Set texture in the middle of the sprite
    sf::FloatRect shadowSpriteCenter = spaceshipShadowSprite.getLocalBounds();
    spaceshipShadowSprite.setOrigin(sf::Vector2f((shadowSpriteCenter.width / 2), (shadowSpriteCenter.height / 2)));
    
    // Set shadow scale
    spaceshipShadowSprite.setScale(0.1, 0.1);
    
    // Position the shadow on the screen
    sf::Vector2f shadowPosition;
    shadowPosition = shipPosition;
    shadowPosition.y += 25;
    shadowPosition.x += 25;
    spaceshipShadowSprite.setPosition(shadowPosition);
    spaceshipShadowSprite.rotate(shipAngle);
    
    // Draw the sprite on the screen
    window.draw(spaceshipShadowSprite);
    
    // Create spaceship sprite
    sf::Sprite spaceshipSprite;
    
    // Set texture on the sprite
    spaceshipSprite.setTexture(spaceshipTexture);
    
    // Set texture in the middle of the sprite
    sf::FloatRect spriteCenter = spaceshipSprite.getLocalBounds();
    spaceshipSprite.setOrigin(sf::Vector2f((spriteCenter.width / 2), (spriteCenter.height / 2)));
    
    // Set sprite scale
    spaceshipSprite.setScale(0.15, 0.15);
    
    // Position the spaceship on the screen
    spaceshipSprite.setPosition(shipPosition);
    spaceshipSprite.rotate(shipAngle);
    
    // Draw the sprite on the screen
    window.draw(spaceshipSprite);
}

void GameLoop::drawProjectileSprites() {
    // Iterate through the projectile vector
    std::vector<Projectile>::iterator iter = projectiles.begin(); // Declaration of vector iterator
    

    for (  ; iter < projectiles.end(); iter++) {
        // Check if projectile still on screen & remove if not
        if ((iter->currentPosition.x > screenRightEdge) || (iter->currentPosition.x < screenLeftEdge) || (iter->currentPosition.y > screenTopEdge) || (iter->currentPosition.y < screenBottomEdge)) {
            projectiles.erase(iter);
            break;
        }
        
        // Create a projectile shape
        sf::CircleShape projectile(10);
        projectile.setFillColor(sf::Color::Green);
        
        sf::Vector2f currentPosition = iter->currentPosition;
        
        // Calculate and update the projectile's position
        sf::Vector2f newPosition;
        float speed = 0.5;
        float radianAngle = convertToRadians(iter->angle);
        float newY = currentPosition.y + speed * sin(radianAngle);
        float newX = currentPosition.x + speed * cos(radianAngle);
        
        newPosition.x = newX;
        newPosition.y = newY;
        
        iter->currentPosition = newPosition;

        projectile.setPosition(newPosition);
        
        // Draw projectile shape on the screen
        window.draw(projectile);
        
        // Iterate through the asteroids vector
        std::vector<Projectile>::iterator asterIter = asteroids.begin(); // Declaration of vector iterator
        for (  ; asterIter < asteroids.end(); asterIter++) {
            // Check if the projectile is inside the position bounds of the asteroid
            // If yes, remove the asteroid from the vector
            float topBound = asterIter->currentPosition.y - 25;
            float leftBound = asterIter->currentPosition.x - 25;
            
            sf::Rect<float> asterBoundRect( leftBound, topBound, 50, 50 );
            
            if (asterBoundRect.intersects(projectile.getGlobalBounds())) {
                asteroids.erase(asterIter);
                projectiles.erase(iter);
                gameScore += 1;
                break;
            }
        }
    }
}

void GameLoop::drawAsteroidSprites() {
    // Get the elapsed time and cast it to int
    int elapsedTime = asteroidClock.getElapsedTime().asSeconds();
    
    // Asteroid should be added every 5 seconds
    if (elapsedTime == 5) {
        // Reset the timer
        asteroidClock.restart();
        
        // Get a random angle
        float angle = rand() % 360;
        
        // Create projectile variable
        Projectile asteroid;
        asteroid.angle = angle;
        
        // Determine the starting quadrant based on the angle
        if (angle < 90) { // bottom-left
            asteroid.origin = bottomLeftCorner;
            asteroid.currentPosition = bottomLeftCorner;
        } else if (angle < 180) { // bottom-right
            asteroid.origin = bottomRightCorner;
            asteroid.currentPosition = bottomRightCorner;
        } else if (angle < 270) { // top-right
            asteroid.origin = topRightCorner;
            asteroid.currentPosition = topRightCorner;
        } else { // top-left
            asteroid.origin = topLeftCorner;
            asteroid.currentPosition = topLeftCorner;
        }
        
        // Add the asteroid to asteroids container
        asteroids.push_back(asteroid);
    }
    
    // Iterate through the asteroids vector
    std::vector<Projectile>::iterator iter = asteroids.begin(); // Declaration of vector iterator
    
    // Create an asteroid texture
    sf::Texture spaceshipTexture;
    if (!spaceshipTexture.loadFromFile(ASTEROID_PATH)) {
        std::cerr << "Failed to load asteroid sprite!" << std::endl;
        return;
    }
    
    for (  ; iter < asteroids.end(); iter++) {
        // Check if projectile still on screen & remove if not
        if ((iter->currentPosition.x > screenRightEdge) || (iter->currentPosition.x < screenLeftEdge) || (iter->currentPosition.y > screenTopEdge) || (iter->currentPosition.y < screenBottomEdge)) {
            asteroids.erase(iter);
            break;
        }
        
        // Get current position
        sf::Vector2f currentPosition = iter->currentPosition;
        
        // Calculate and update the projectile's position
        sf::Vector2f newPosition;
        float speed = 0.25;
        float radianAngle = convertToRadians(iter->angle);
        float newY = currentPosition.y + speed * sin(radianAngle);
        float newX = currentPosition.x + speed * cos(radianAngle);
        
        newPosition.x = newX;
        newPosition.y = newY;
        
        iter->currentPosition = newPosition;
        
        // Create an asteroid shadow sprite
        sf::Sprite asteroidShadowSprite;
        
        // Set color and alpha on the shadow sprite
        sf::Color shadowColor = sf::Color::Black;
        shadowColor.a = 50;
        asteroidShadowSprite.setColor(shadowColor);
        
        // Set texture on the shadow sprite
        asteroidShadowSprite.setTexture(spaceshipTexture);
        
        // Set texture in the middle of the sprite
        sf::FloatRect shadowSpriteCenter = asteroidShadowSprite.getLocalBounds();
        asteroidShadowSprite.setOrigin(sf::Vector2f((shadowSpriteCenter.width / 2), (shadowSpriteCenter.height / 2)));
        
        // Set shadow scale
        asteroidShadowSprite.setScale(0.15, 0.15);
        
        // Position the shadow on the screen
        sf::Vector2f shadowPosition;
        shadowPosition = iter->currentPosition;
        shadowPosition.y += 17;
        shadowPosition.x += 17;
        asteroidShadowSprite.setPosition(shadowPosition);
        asteroidShadowSprite.rotate(iter->angle);
        
        // Create an asteroid sprite
        sf::Sprite asteroidSprite;
        
        // Assign the texture to the sprite
        asteroidSprite.setTexture(spaceshipTexture);
        
        // Set texture in the middle of the sprite
        sf::FloatRect spriteCenter = asteroidSprite.getLocalBounds();
        asteroidSprite.setOrigin(sf::Vector2f((spriteCenter.width / 2), (spriteCenter.height / 2)));
        
        // Set sprite scale
        asteroidSprite.setScale(0.2, 0.2);
        
        // Position the asteroid on the screen
        asteroidSprite.setPosition(iter->currentPosition);
        asteroidSprite.rotate(iter->angle);
        
        // Draw the sprite on the screen
        window.draw(asteroidShadowSprite);
        window.draw(asteroidSprite);
    }
}

void GameLoop::drawScore() {
    // Create a string
    std::string scoreString = "Score: " + std::to_string(gameScore);
    
    // Create a font
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH)) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }
    
    // Create the text object
    sf::Text scoreText{};
    
    scoreText.setString(scoreString);
    scoreText.setFont(font);
    scoreText.setOrigin(-10, 0);
    scoreText.setFillColor(sf::Color::Black);
    
    // Drag the text
    window.draw(scoreText);
}

void GameLoop::startGame() {
    // Clear any existing window content
    window.clear(sf::Color::White);
     
    // Update ship position
    updateShipPosition();
    
    // Draw projectile sprites
    drawProjectileSprites();
    
    // Draw asteroid sprites
    drawAsteroidSprites();
    
    // Draw spaceship sprite
    drawSpaceshipSprite();
    
    // Draw game score
    drawScore();
   
    // Display the window contents
    window.display();
}

void GameLoop::setSceneManager(std::any manager) {
    sceneManager = std::any_cast<SceneManager*>(manager);
}

void GameLoop::run() {
    startGame();
}

InputDelegate* GameLoop::getInputDelegate() {
    return (this);
}
