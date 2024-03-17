//
//  InputManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <SFML/Graphics.hpp>

#include "InputDelegate.hpp"

class InputManager {
public:
    InputManager(InputDelegate* delegate);
    
    void handleEvent(sf::Event event);
    void pollInput();
    
    void updateDelegate(InputDelegate* delegate);
private:
    InputDelegate* delegate;
};

#endif /* InputManager_hpp */
