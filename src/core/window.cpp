#include "window.h"
#include "GLFW/glfw3.h"
#include <iostream>

Window::Window(int w, int h, const std::string &title)
    : width(w), height(h), window(nullptr) {

  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

  if (!window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwDestroyWindow(window);
    glfwTerminate();
    throw std::runtime_error("Failed to initialize GLAD");
  }

  std::cout << "Vendor:      " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Renderer:    " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Version:     " << glGetString(GL_VERSION) << std::endl;

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Window::update() {
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void Window::input() {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

Window::~Window() {
  if (window)
    glfwDestroyWindow(window);
  glfwTerminate();
}

bool Window::shouldClose() const { return glfwWindowShouldClose(window); }

GLFWwindow *Window::getGLFWwindow() const { return window; }