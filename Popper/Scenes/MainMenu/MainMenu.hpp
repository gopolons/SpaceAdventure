//
//  MainMenu.hpp
//  Popper
//
//  Created by Georgii Polonskii on 13/03/2024.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <SFML/Graphics.hpp>

#include "InputDelegate.hpp"

class MainMenu : public InputDelegate {
public:
    MainMenu(sf::RenderWindow& window);
    
    void drawTitleMenu();
private:
    sf::RenderWindow& window;
};

#endif /* MainMenu_hpp */
