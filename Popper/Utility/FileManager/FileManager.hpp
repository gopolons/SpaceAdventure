//
//  FileManager.hpp
//  Popper
//
//  Created by Georgy Polonskiy on 20/04/2024.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <string>

class FileManager {
public:
    void rewriteFile(std::string fileName, std::string content);
    std::string readFromFile(std::string fileName);
};

#endif /* FileManager_hpp */
