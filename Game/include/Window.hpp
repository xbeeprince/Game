//
//  Window.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef Window_hpp
#define Window_hpp

#include "Game.hpp"

namespace GameEngine {

typedef void (*function_ptr)(void);

class Window {
private:
    GLFWwindow* m_window;
public:
    Window();
    ~Window();
    
    void create();
    void loop(function_ptr);
};
}

#endif /* Window_hpp */
