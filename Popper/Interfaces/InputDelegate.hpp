//
//  InputDelegate.h
//  Popper
//
//  Created by Georgy Polonskiy on 17/03/2024.
//

#ifndef InputDelegate_hpp
#define InputDelegate_hpp

class InputDelegate {
public:
    virtual void handleActionButton() {};
    virtual void handleLeftButton() {};
    virtual void handleRightButton() {};
    virtual void handleUpButton() {};
    virtual void handleDownButton() {};
    virtual void handleEscapeButton() {};
};

#endif /* InputDelegate_hpp */
