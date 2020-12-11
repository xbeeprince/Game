//
//  TriangleGame.hpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#ifndef TriangleGame_hpp
#define TriangleGame_hpp

#include "Game.hpp"
#include "BaseGame.hpp"
#include "ShaderManager.hpp"
#include "FileManager.hpp"

namespace GameEngine {
class TriangleGame : public BaseGame {
    
private:
    ShaderManager *shader;
    GLuint vao;
    GLuint vbo;
    string vpath;
    string fpath;

public:
    TriangleGame();
    ~TriangleGame();
    void initialize();
    void update();
    void render();
};
}

#endif /* TriangleGame_hpp */
