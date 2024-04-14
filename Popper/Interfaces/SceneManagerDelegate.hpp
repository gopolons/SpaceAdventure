//
//  SceneManagerDelegate.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 14/04/2024.
//

#ifndef SceneManagerDelegate_h
#define SceneManagerDelegate_h

#include <any>
#include "InputDelegate.hpp"

// SceneManagerDelegate is an interface used by SceneManager to control the current
// state of the game. It is implemented by game scenes and contains utility methods
// used to control the game state & assign the managers
class SceneManagerDelegate {
public:
    virtual void setSceneManager(std::any manager) {};
    virtual void run() {};
    virtual InputDelegate* getInputDelegate() { return nullptr; };
};

#endif /* SceneManagerDelegate_h */
