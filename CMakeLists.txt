cmake_minimum_required(VERSION 3.20)
project(Symphonic LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add GLM (header-only)
add_subdirectory(external/glm)

# Sources (include glad.c!)
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/glad.c
)

add_executable(Symphonic ${SOURCES})

target_include_directories(Symphonic PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Link libraries
if (WIN32)
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
        gdi32
        glm          # Link GLM target from add_subdirectory
    )
elseif (APPLE)
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
        glm
    )
else()
    target_link_libraries(Symphonic PRIVATE
        glfw
        OpenGL::GL
        X11 pthread Xrandr Xi dl
        glm
    )
endif()

file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${CMAKE_BINARY_DIR})
