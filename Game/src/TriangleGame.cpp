//
//  TriangleGame.cpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#include "TriangleGame.hpp"

namespace GameEngine {

static const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

static const string vertex_path = "vertexShader.vert";
static const string frag_path = "fragmengShader.frag";

TriangleGame::TriangleGame() {
    string dir = FileManager::getResourceDir();
    
    vpath = dir + "/" + vertex_path;
    fpath = dir + "/" + frag_path;
}

TriangleGame::~TriangleGame() {
    if (shader) {
        delete shader;
    }
}

void TriangleGame::initialize() {
    cout << "initialize..." << endl;
    //背景
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    shader = new ShaderManager();
    shader->CompileShaders(vpath, fpath);
    shader->LinkShaders();
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void TriangleGame::update() {
    cout << "update..." << endl;
}

void TriangleGame::render() {
    cout << "render" << endl;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    shader->Use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
}
