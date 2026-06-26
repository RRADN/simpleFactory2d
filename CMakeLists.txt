cmake_minimum_required(VERSION 3.30)
project(simpleFactory2d VERSION 0.2.0 LANGUAGES CXX)

set(SDL3_VERSION "3.0")

# Find or download SDL from a suitable location
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # On Linux, use your package manager to fetch SDL Libraries
    find_package(SDL3 REQUIRED)
    find_package(SDL3_image REQUIRED)

    if (NOT SDL3_FOUND)
        message(FATAL_ERROR "Unable to find SDL3 on your system. Install it using your package manager.")
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # On Windows, we can use a pre-compiled SDL library stored in the project directory
    set(SDL3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3/include)
    set(SDL3_LIBRARY ${CMAKE_SOURCE_DIR}/external/SDL3/lib/x64/SDL3.lib)
    include_directories(${SDL3_INCLUDE_DIR})

    set(SDL3_IMAGE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3_image/include)
    set(SDL3_IMAGE_LIBRARY ${CMAKE_SOURCE_DIR}/external/SDL3_image/lib/x64/SDL3_image.lib)
    include_directories(${SDL3_IMAGE_INCLUDE_DIR}) 
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/simpleFactory.cpp
    src/platform/sdlWindow.cpp
    src/logic/sdlInput.cpp
    src/UI/mainMenu.hpp
    src/platform/rendering/testrender.cpp
)

# Linking SDL libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3 
    SDL3_image::SDL3_image
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(${PROJECT_NAME} ${SDL3_LIBRARY} ${SDL3_IMAGE_LIBRARY})
endif()

#copy assets to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)