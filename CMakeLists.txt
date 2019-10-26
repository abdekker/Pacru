cmake_minimum_required (VERSION 3.10)
project (Pacru)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH /usr/share/SFML/cmake/Modules)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(Pacru
	main.cpp
	catch.hpp)

target_compile_options(Pacru PUBLIC -std=c++1z -Werror -Wall -Wextra)
target_link_libraries(Pacru PUBLIC -lm)
