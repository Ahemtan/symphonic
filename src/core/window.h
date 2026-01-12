#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
  GLFWwindow *window;
  int width, height;
  std::string title;

public:
  Window(int w, int h, const std::string &title);
  ~Window();

  bool shouldClose() const;
  void update();
  void input();
  GLFWwindow *getGLFWwindow() const;
};
