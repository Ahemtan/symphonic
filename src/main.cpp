#include "core/window.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

int main() {

  try {
    Window window(800, 600, "Symphonic");
    Window anotherWindow(400, 300, "Another Window");

    while (!window.shouldClose() && !anotherWindow.shouldClose()) {

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glfwSwapBuffers(window.getGLFWwindow());
      glfwPollEvents();
    }

  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return 0;
}
