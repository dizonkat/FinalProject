cmake_minimum_required(VERSION 3.22)
project(FinalProject)

set(CMAKE_CXX_STANDARD 17)

# Find the SFML library
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

# Add the executable and link the SFML libraries
add_executable(FinalProject main.cpp lib/src/Ball.cpp lib/src/Paddle.cpp lib/src/Game.cpp)
target_link_libraries(FinalProject PRIVATE sfml-system sfml-network sfml-graphics sfml-window)