cmake_minimum_required(VERSION 3.10.0)
project(simpleFactory2d VERSION 0.1.0 LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES ON)

# Integrar mingw64
set(mingw64_DIR "${CMAKE_SOURCE_DIR}/external/mingw64")
set(CMAKE_PREFIX_PATH "${mingw64_DIR}/lib/cmake" ${CMAKE_PREFIX_PATH})
set(CMAKE_PROGRAM_PATH "${mingw64_DIR}/bin" ${CMAKE_PROGRAM_PATH})

# Configurar compilador de mingw64
set(CMAKE_CXX_COMPILER "${mingw64_DIR}/bin/g++.exe")
set(CMAKE_C_COMPILER "${mingw64_DIR}/bin/gcc.exe")
set(CMAKE_MAKE_PROGRAM "${mingw64_DIR}/bin/mingw32-make.exe" CACHE FILEPATH "Make program")

# Find SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML/lib/cmake/SFML")

find_package(SFML 3.0.2 COMPONENTS Graphics Window System REQUIRED)


add_executable(simpleFactory2d
    src/main/main.cpp
    src/game/simpleFactory.cpp
    src/platform/sfmlWindow.cpp
    src/entities/primitive/entity.cpp
    src/entities/player/player.cpp
    src/entities/handlers/entitiesHandler.cpp
    src/entities/primitive/tile.cpp
    src/logic/event.cpp
    src/logic/movement/movement.cpp
)

# Agregar rutas de include de SFML
target_include_directories(simpleFactory2d PRIVATE "${CMAKE_SOURCE_DIR}/external/SFML/include")

# Link SFML libraries

target_link_libraries(simpleFactory2d
    SFML::Graphics
    SFML::Window
    SFML::System
)

#copy assets to build directory

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY
    ${CMAKE_SOURCE_DIR}/external/SFML/bin/sfml-graphics-3.dll
    ${CMAKE_SOURCE_DIR}/external/SFML/bin/sfml-window-3.dll
    ${CMAKE_SOURCE_DIR}/external/SFML/bin/sfml-system-3.dll
    ${CMAKE_SOURCE_DIR}/external/mingw64/bin/libgcc_s_seh-1.dll
    ${CMAKE_SOURCE_DIR}/external/mingw64/bin/libstdc++-6.dll
    ${CMAKE_SOURCE_DIR}/external/mingw64/bin/libwinpthread-1.dll
    DESTINATION ${CMAKE_BINARY_DIR}
)