cmake_minimum_required(VERSION 3.13)

# set the project name
project(TicTacToe VERSION 0.4)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB SOURCES
	 CONFIGURE_DEPENDS
	 *.cpp
) 

# add the executable
add_executable(TicTacToe ${SOURCES})

