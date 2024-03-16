//
//  GameLoop.cpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#include <SFML/Graphics.hpp>
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
}

void GameLoop::handleInput() {
    // Apply rotation to angle property
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shipAngle -= 0.25;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shipAngle += 0.25;
    }
    
    // Calculate and update the ship's position
    sf::Vector2f newPosition;
    float speed = 0.3;
    float radianAngle = convertToRadians(shipAngle);
    float newY = shipPosition.y + speed * sin(radianAngle);
    float newX = shipPosition.x + speed * cos(radianAngle);
    
    newPosition.x = newX;
    newPosition.y = newY;
    
    shipPosition = newPosition;
    
    int screenRightEdge = window.getSize().x;
    int screenLeftEdge = 0;
    
    int screenTopEdge = window.getSize().y;
    int screenBottomEdge = 0;
    
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

void GameLoop::startGame() {
    // Clear any existing window content
    window.clear(sf::Color::White);
     
    // Handle user input
    handleInput();
    
    // Draw spaceship sprite
    drawSpaceshipSprite();
   
    // Display the window contents
    window.display();
}
