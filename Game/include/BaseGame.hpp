//
//  BaseGame.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef BaseGame_hpp
#define BaseGame_hpp

#include "Game.hpp"

namespace GameEngine {

    class BaseGame {
    
    private:
    
    public:
        virtual void initialize();
        virtual void update();
        virtual void render();
    };
}


#endif /* BaseGame_hpp */
