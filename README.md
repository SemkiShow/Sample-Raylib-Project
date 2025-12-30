# Sample-Raylib-Project

A template for creating a new Raylib project

## How to use

Find and replace Sample-Raylib-Project with the name of your project

## How to run

### Executable

- Download the latest release
- Unzip it
- Run main or main.exe depending on your system

### [Web version](SemkiShow.github.io/Sample-Raylib-Project/)

## How to build

### Executable

1. Install Raylib following one of these tutorials based on your system: [Linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux), [Windows](https://github.com/raysan5/raylib/wiki/Working-on-Windows), [macOS](https://github.com/raysan5/raylib/wiki/Working-on-macOS)
1. Run 
```
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git checkout raygui
git submodule update --init --recursive --depth 1 --jobs 8
chmod +x run.sh
./run.sh
```

### Web version

1. Install Raylib following one of these tutorials based on your system: [Linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux), [Windows](https://github.com/raysan5/raylib/wiki/Working-on-Windows), [macOS](https://github.com/raysan5/raylib/wiki/Working-on-macOS)
1. Setup Emscripten using [this tutorial](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5))
1. Run
```
git clone https://github.com/SemkiShow/Sample-Raylib-Project
cd Sample-Raylib-Project
git checkout raygui
git submodule update --init --recursive --depth 1 --jobs 8
chmod +x run.sh
./run.sh --web
```
