//
//  FileManager.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include "Game.hpp"

namespace GameEngine {

class FileManager {
  
public:
    FileManager();
    ~FileManager();
    
    static string getApplicationDir();
    static string getResourceDir();
};
}

#endif /* FileManager_hpp */
