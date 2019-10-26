cmake_minimum_required (VERSION 3.10)

# Pacru is boardgame
project (Pacru)

# Build type
set(CMAKE_BUILD_TYPE Debug)

# SFML is the graphics library
set(CMAKE_MODULE_PATH /usr/share/SFML/cmake/Modules)
find_package(SFML COMPONENTS graphics window system)

add_executable(Pacru
	main.cpp
	catch.hpp)

target_compile_options(Pacru PUBLIC -std=c++1z -Werror -Wall -Wextra)
target_link_libraries(Pacru PUBLIC -lm)
