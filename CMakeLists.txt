cmake_minimum_required(VERSION 3.20)
project(OpenGLApp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include headers
file(GLOB_RECURSE HEADERS "include/*.h")
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(OpenGLApp ${SOURCES} ${HEADERS})

# Find packages
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Link libraries based on platform
if(WIN32)
    target_link_libraries(OpenGLApp PRIVATE glfw OpenGL::GL glew32 opengl32 gdi32)
elseif(APPLE)
    find_library(COCOA Cocoa)
    find_library(IOKIT IOKit)
    find_library(COREVIDEO CoreVideo)
    target_link_libraries(OpenGLApp PRIVATE glfw OpenGL::GL ${COCOA} ${IOKIT} ${COREVIDEO})
else()
    target_link_libraries(OpenGLApp PRIVATE glfw OpenGL::GL GL X11 pthread Xrandr Xi dl)
endif()
