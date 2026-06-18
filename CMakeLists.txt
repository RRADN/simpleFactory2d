cmake_minimum_required(VERSION 3.11)
project(simpleFactory2d VERSION 0.2.0 LANGUAGES CXX)

set(SDL3_VERSION "3.0")

# Find or download SDL from a suitable location
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # On Linux, use apt-get or another package manager to fetch SDL Libraries
    find_package(SDL3 REQUIRED)

    if (NOT SDL3_FOUND)
        message(FATAL_ERROR "Unable to find SDL3 on your system. Install it using your package manager.")
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # On Windows, we can use a pre-compiled SDL library stored in the project directory
    set(SDL3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3/include)
    set(SDL3_LIBRARY ${CMAKE_SOURCE_DIR}/external/SDL3/lib/x64/SDL3.lib)
    include_directories(${SDL3_INCLUDE_DIR})
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/simpleFactory.cpp
    src/platform/sdlWindow.cpp
    src/logic/sdlInput.cpp
    src/UI/mainMenu.hpp
)

# Linking SDL libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} SDL3::SDL3)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} ${SDL3_LIBRARY})
endif()