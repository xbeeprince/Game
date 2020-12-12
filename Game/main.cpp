//
//  main.cpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#include <iostream>
#include "Game.hpp"
#include "BaseGame.hpp"
#include "Window.hpp"
#include "TriangleGame.hpp"

using namespace std;
using namespace GameEngine;


int main(int argc, const char * argv[]) {
    BaseGame *game = new TriangleGame();
    Window *window = new Window(game);
    
    window->loop();
    return 0;
}

