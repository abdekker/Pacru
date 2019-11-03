cmake_minimum_required (VERSION 3.10)

# Pacru is boardgame
project (Pacru)

# Build type (uncomment these for RELEASE builds)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# SFML is the graphics library
set(CMAKE_MODULE_PATH /usr/share/SFML/cmake/Modules)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(Pacru
	main.cpp
	catch.hpp
	globals.hpp
	Board.cpp Board.hpp
	Game.cpp Game.hpp
	GameState.cpp GameState.hpp)

target_compile_options(Pacru PUBLIC -std=c++1z -Werror -Wall -Wextra)
target_link_libraries(Pacru PUBLIC -lm)
target_link_libraries(Pacru PUBLIC -lm ${SFML_LIBRARIES})
