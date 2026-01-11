#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <initializer_list>
#include <iostream>

int main() {
  if (!glfwInit()) {
    std::cerr << "GLFW failed\n";
    return -1;
  }

  GLFWwindow *win = glfwCreateWindow(800, 600, "Symponic", nullptr, nullptr);
  glfwMakeContextCurrent(win);

  if (glewInit() != GLEW_OK) {
    std::cerr << "GLEW failed\n";
    return -1;
  }

  while (!glfwWindowShouldClose(win)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(win);
    glfwPollEvents();
  }
  return 0;
}
