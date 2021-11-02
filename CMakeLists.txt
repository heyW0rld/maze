cmake_minimum_required(VERSION 3.19.2)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab2 src/main.cpp src/map.cpp src/labirintManager.cpp include/labirintManager.h src/player.cpp include/player.h src/maze.cpp include/maze.h strategy/greedy.cpp strategy/greedy.h strategy/leftHand.cpp strategy/leftHand.h strategy/rightHand.cpp strategy/rightHand.h strategy/backRevert.cpp strategy/backRevert.h strategy/strategy.cpp strategy/strategy.h)
