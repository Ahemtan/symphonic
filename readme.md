# OpenGL Audio Visualizer

A real-time audio visualizer built in **C++** using **OpenGL**.

---

## Features

- Real-time audio visualization
- Supports multiple visualization modes (bars, waves, particles, etc.)
- Cross-platform support: Windows, macOS, Linux
- Uses modern C++17 and OpenGL 3.3+
- Easy to extend with new visualization effects

---

## Prerequisites

Make sure the following tools and libraries are installed on your system:

- **CMake** (version 3.20 or higher)
- **C++17 compatible compiler**
- **OpenGL**
- **GLFW 3.3**
- **GLEW** (Windows only)
- Audio library (e.g., **PortAudio** or **SFML audio module**) if you plan to capture audio input

---

## Building

1. **Clone the repository**:

```bash
git clone https://github.com/yourusername/OpenGLAudioVisualizer.git
cd OpenGLAudioVisualizer
```

2. **Create a build directory and configure CMake:**:

```bash
mkdir build
cd build
cmake .. -DPROJECT_NAME_CUSTOM=AudioVisualizer
```

3. **Create a build directory and configure CMake:**:

```bash
cmake --build .
```

Run the executable:
On Windows: bin/AudioVisualizer.exe
On macOS/Linux: bin/AudioVisualizer

## Project Structure

```
OpenGLAudioVisualizer/
├── include/ # Header files
├── src/ # Source files
├── shaders/ # GLSL shader files
├── assets/ # Audio samples, textures, etc.
├── CMakeLists.txt
└── README.md
```
