//
//  MenuPrompt.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 27/04/2024.
//

#ifndef MenuPrompt_hpp
#define MenuPrompt_hpp

#include <iostream>
#include <SFML/Graphics.hpp>

class MenuPrompt {
public:
    MenuPrompt();
    
    std::string text;
    sf::Color color;
    
    float getZoomValue();
private:
    bool isGettingBigger;
    float zoom;
};

#endif /* MenuPrompt_hpp */
