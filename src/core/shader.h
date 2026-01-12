#pragma once

#include <string>
#include <glad/glad.h>

class Shader {
public:
  GLuint ID;

  Shader(const std::string &vertexPath, const std::string &fragmentPath);
  void use() const;

  // Utility functions
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;

private:
  std::string loadFile(const std::string &path);
  GLuint compileShader(const char *source, GLenum shaderType);
};
