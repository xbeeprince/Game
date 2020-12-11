//
//  FileManager.cpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#include "FileManager.hpp"
#include <unistd.h>
namespace GameEngine {

string FileManager::getApplicationDir() {
    char buffer[PATH_MAX];
    getcwd(buffer, PATH_MAX);
    return string(buffer) + "/Game";

}

string FileManager::getResourceDir() {
    return getApplicationDir() + "/res";
}
}
