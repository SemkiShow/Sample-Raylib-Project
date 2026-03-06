# Sample-Raylib-Project

A template for creating a new Raylib project

## How to use

1. Run
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git checkout raygui
git submodule update --init --recursive --depth 1
```
2. Find and replace Sample-Raylib-Project with the name of your project

## How to run

### Executable

- Download the latest release
- Unzip it
- Run Sample-Raylib-Project or Sample-Raylib-Project.exe depending on your system

### [Web version](SemkiShow.github.io/Sample-Raylib-Project/)

## How to build

### Executable

1. If on Linux, install [raylib's dependencies](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies)
2. You'll need a C/C++ compiler and CMake
3. Run 
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git submodule update --init --recursive --depth 1
chmod +x run.sh
./run.sh
```

### Web version

1. If on Linux, install [raylib's dependencies](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies)
2. You'll need a C/C++ compiler and CMake
3. Setup Emscripten using [this tutorial](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5))
4. Run
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git submodule update --init --recursive --depth 1
chmod +x run.sh
./run.sh --web
```
