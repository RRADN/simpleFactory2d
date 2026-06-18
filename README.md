## Simplefactory 2D

Simplefactory 2D is a factorio, satisfactory like inspired game, whit some twists and new mechanics.

It was born from my need to start learning the basics from game dev.

The game engine has undergone multiple refactoring cycles and iterations over the past few months.

## What is this?

This project is a small 2D game engine experiment using SFML.
The goal was to learn:

- Simple 2D rendering 
- Event handling
- Basic game loop architecture

## Learning Curve 

To actualy develop something playable I had to learn:

- C++ (I had previous expiriense with it)
- CMake (Just get the basic to make a proyect run)
- SDL (The "core" of my proyect)

## How to run?

1. Clone the repo:
   `bash
git clone https://github.com/reyjaz007/simpleFactory2d.git
cd simpleFactory2d
`
2. Install dependencies.
   - On Linux, install SDL3 via your package manager.
   - On Windows, place SDL3 headers and libraries under `external/SDL3` as expected by `CMakeLists.txt`.
3. Build the project:
   `bash
mkdir -p build
cd build
cmake ..
cmake --build . --target simpleFactory2d
`
4. Run the executable:
   - Linux/macOS:
     `bash
./simpleFactory2d
`
   - Windows (PowerShell):
     `powershell
./simpleFactory2d.exe
`

## Proyect State

On development, accepting tips or suggestions, but not direct contributions. 

Tenkius for reading! :)
