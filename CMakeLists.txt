cmake_minimum_required(VERSION 3.20)
project(Symphonic LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Sources (include glad.c!)
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/glad.c
)

add_executable(Symphonic ${SOURCES})

target_include_directories(Symphonic PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

if (WIN32)
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
        gdi32
    )
elseif (APPLE)
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
    )
else()
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
        X11 pthread Xrandr Xi dl
    )
endif()
