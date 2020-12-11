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

BaseGame *game;



void game_initialize() {
    
    game = new TriangleGame();
    game->initialize();
    
    
    
    
}

void game_update() {
    //调整transform、scale、rotate等
    game->update();
}

void game_render() {
    //渲染
    game->render();
    
}

void game_loop() {
    game_update();
    game_render();
}


int main(int argc, const char * argv[]) {
    
    Window *window = new Window();
    game_initialize();
    
    window->loop(game_loop);
    return 0;
}

