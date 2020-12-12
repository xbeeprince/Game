//
//  Window.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef Window_hpp
#define Window_hpp

#include "Game.hpp"
#include "BaseGame.hpp"

namespace GameEngine {

typedef void (*function_ptr)(void);

class Window {
private:
    GLFWwindow* m_window;
    BaseGame *m_game;
public:
    Window();
    ~Window();
    
    Window(BaseGame*);
    void create();
    void loop();
};
}

#endif /* Window_hpp */
