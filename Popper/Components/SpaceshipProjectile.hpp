//
//  SpaceshipProjectile.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 16/03/2024.
//

#ifndef SpaceshipProjectile_hpp
#define SpaceshipProjectile_hpp

#include <SFML/Graphics.hpp>

class SpaceshipProjectile {
public:
    float angle;
    sf::Vector2f origin;
    sf::Vector2f currentPosition;
};

#endif /* SpaceshipProjectile_hpp */
