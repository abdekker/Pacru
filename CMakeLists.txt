cmake_minimum_required (VERSION 3.10)
project (Pacru)

set(CMAKE_BUILD_TYPE Debug)

add_executable(Pacru
	main.cpp
	catch.hpp)

target_compile_options(Pacru PUBLIC -std=c++1z -Werror -Wall -Wextra)
#target_link_libraries(Pacru PUBLIC cmocka -lm)
target_link_libraries(Pacru PUBLIC -lm)
