cmake_minimum_required(VERSION 3.10)
project(Bejeweled)

set(CMAKE_CXX_STANDARD 11)

configure_file(images/background.png images/background.png COPYONLY)
configure_file(images/cursor.png images/cursor.png COPYONLY)
configure_file(images/gems.png images/gems.png COPYONLY)
configure_file(sounds/period.ogg sounds/period.ogg COPYONLY)
configure_file(fonts/kiss_me_quick/kiss_me_quick.ttf fonts/kiss_me_quick/kiss_me_quick.ttf COPYONLY)
configure_file(images/dinkyminaj.png images/dinkyminaj.png COPYONLY)
configure_file(images/pink-background.png images/pink-background.png COPYONLY)
configure_file(images/black.png images/black.png COPYONLY)
configure_file(images/yellow.png images/yellow.png COPYONLY)
configure_file(fonts/ValentineCute/valentine-cute.ttf fonts/ValentineCute/valentine-cute.ttf COPYONLY)

# Define sources and executable
set(EXECUTABLE_NAME "Bejeweled")

add_executable(${EXECUTABLE_NAME} main.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()