//
//  main.cpp
//  Game
//
//  Created by iprincewang on 2020/12/11.
//

#include <iostream>
#include "Game.hpp"
#include "BaseGame.hpp"
#include "FileManager.hpp"
#include "ShaderManager.hpp"

using namespace std;
using namespace GameEngine;

ShaderManager *shader_manager;
GLuint vao;
GLuint vbo;
const float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};


void initialize() {
    //背景
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    string dir = FileManager::getResourceDir();
    
    cout << dir << endl;
    
    shader_manager = new ShaderManager();
    
    const string& vertex_path = dir + "/vertexShader.vert";
    const string& frag_path = dir + "/fragmengShader.frag";
    
    shader_manager->CompileShaders(vertex_path, frag_path);
    
    shader_manager->LinkShaders();
    
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void update() {
    //调整transform、scale、rotate等
}

void render() {
    //渲染
    glClear(GL_COLOR_BUFFER_BIT);
    
    shader_manager->Use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    glfwInit();
    //    主版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //    次版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //    告诉glfw 我们使用的是core_profile 核心模块
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //    向前兼容
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //    创建一个GLFW 窗口   宽 高  窗口名字  后边两个暂时不用管
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //    通知GLFW将我们窗口的上下文设置为当前线程的主上下文了
    glfwMakeContextCurrent(window);
    
    //    GLAD 是用来管理openGL 的函数指针的。所以在调用任何openGL函数之前我们都需要初始化GLAD。
    //    我们给GLAD传入了用来加载系统相关的OpenGL函数指针地址的函数。GLFW给我们的是glfwGetProcAddress，它根据我们编译的系统定义了正确的函数。
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //    创建渲染的视口: 我们必须要告诉OpenGl 需要渲染的尺寸大小，即为视口 viewport(),这样openGL 才能知道根据窗口大小显示数据和坐标。
    //    glViewport 前两个参数控制视口左下角位置，后两个参数控制视口的宽和高
    //    openGL 幕后使用的是glViewport 定义的 位置和宽高进行2D转换

    //    窗口调整的时候 视口应该也被调整  对窗口注册一个回调函数每次窗口大小被调整的时候会被调用
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    
    
    //   通过 glfwSetFramebufferSizeCallback glfw 函数 当窗口frame 变化时会调用。
    //    对于视网膜屏 Retain 屏   宽度和高度明显比原输入值更高一点。
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    void processInput(GLFWwindow *window);
    
    
    initialize();
    //   为了防止 渲染的图像一出现就退出 我们使用while 循环 。我们可以称之为Render Loop
    //    glfwWindowShouldClose 每次循环开始前检查一次GLFW 是否被要求退出 是true 的话渲染便结束了。
    while(!glfwWindowShouldClose(window)) {
        //输出控制
        processInput(window);
        //        glfwSwapBuffers 会交换颜色缓冲（他是存储着GLFW 窗口每一个像素色值的大缓冲），将会作为输出显示在屏幕上
        //        当程序退出的时候 使用一个自定义的颜色清空屏幕  在每个新的渲染迭代可是的时候我们总希望清屏否则总是看到上次渲染的结果。
        //        我们可以使用glClear   GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。 我们清空颜色 。
        
        update();
        render();
        
        glfwSwapBuffers(window);
        //        glfwPollEvents 检查函数有没有触发什么事件 键盘输入 鼠标移动 并调用对应函数
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

