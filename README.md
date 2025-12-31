# Sample-Raylib-Project

A template for creating a new Raylib project

## How to use

1. Run
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git checkout raygui
git submodule update --init --recursive --depth 1 --jobs 8
```
2. Find and replace Sample-Raylib-Project with the name of your project

## How to run

### Executable

- Download the latest release
- Unzip it
- Run main or main.exe depending on your system

### [Web version](SemkiShow.github.io/Sample-Raylib-Project/)

## How to build

### Executable

1. If on Linux, install raylib's dependencies following [this tutorial](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies)
1. You'll need a C/C++ compiler and CMake
1. Run 
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git submodule update --init --recursive --depth 1 --jobs 8
chmod +x run.sh
./run.sh
```

### Web version

1. If on Linux, install raylib's dependencies following [this tutorial](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#dependencies)
1. You'll need a C/C++ compiler and CMake
1. Setup Emscripten using [this tutorial](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5))
1. Run
```bash
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git submodule update --init --recursive --depth 1 --jobs 8
chmod +x run.sh
./run.sh --web
```
