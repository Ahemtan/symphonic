#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// constructor for shader
// requires path to vertex and fragment shader
Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {

  // loading file contents
  std::string vertexCode = loadFile(vertexPath);
  std::string fragmentCode = loadFile(fragmentPath);

  // compiling shader
  GLuint vertexShader = compileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
  GLuint fragmentShader =
      compileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

  // creating programing and attaching
  ID = glCreateProgram();
  glAttachShader(ID, vertexShader);
  glAttachShader(ID, fragmentShader);
  glLinkProgram(ID);

  /// checking for errors return if so
  GLint success;
  char infoLog[1024];
  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(ID, 1024, nullptr, infoLog);
    std::cerr << "[ERROR] Shader program linking failed:\n"
              << infoLog << std::endl;
  }

  // cleaning up shader
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

// use shader
void Shader::use() const { glUseProgram(ID); }

// loading file function
// function that can load any txt file
std::string Shader::loadFile(const std::string &path) {
  // define buffet and path of file
  std::ifstream file(path);
  std::stringstream buffer;

  // check if file is open and exists
  if (file.is_open()) {
    buffer << file.rdbuf();
    file.close();
  } else {
    std::cerr << "[ERROR] Cannot open file: " << path << std::endl;
  }

  // return file contents
  return buffer.str();
}

// compiling shader
GLuint Shader::compileShader(const char *source, GLenum shaderType) {
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  GLint success;
  char infoLog[1024];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
    std::cerr << "[ERROR] Shader compilation failed:\n" << infoLog << std::endl;
  }

  return shader;
}

// options

void Shader::setBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}