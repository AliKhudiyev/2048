cmake_minimum_required(VERSION 3.5)

project(2048)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

find_package(SDL2 REQUIRED)
include_directories(lib ${SDL2_INCLUDE_DIRS})

add_executable(
    ${PROJECT_NAME} 
    src/main.cpp 
    src/app.cpp 
    src/event.cpp 
    src/surface.cpp 
    src/texture.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})