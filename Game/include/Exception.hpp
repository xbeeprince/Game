//
//  Exception.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef Exception_hpp
#define Exception_hpp

#include "Game.hpp"
using namespace std;

#pragma once
namespace GameEngine {
class Exception {
  
public:
    Exception(const string& message) : reason(message) {
        
    }
    
    const std::string reason;
};
}

#endif /* Exception_hpp */
