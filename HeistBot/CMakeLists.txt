# CMakeList.txt : CMake project for HeistBot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (HeistBot "HeistBot.cpp" "HeistBot.h" "MovementEngine.cpp" "MovementEngine.h" "resource.h" "Vector2.cpp" "Vector2.h")

# TODO: Add tests and install targets if needed.
