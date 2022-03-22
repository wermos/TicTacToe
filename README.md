Tic Tac Toe
====

# Building the Project

## Pre-Requisites

1. A C++20 compliant compiler
    * GCC >= 11 or MSVC >= 19.30 should do.
2. CMake

## Instructions
1. Clone the repository.
    * You can clone the repo by running `git clone https://github.com/wermos/TicTacToe.git`.
2. Run CMake on the repository.
    * Run `cmake -S. -Bbuild -G[generator]`.
	* Run `cmake --build build`.
        - On Linux, you can also append `-- -j<num>` to the end of the above command, to run the build on `<num>` cores. For example,
        ```bash
        cmake --build build -- -j4  # for 4 cores
        ```
3. Run the executable.
	* The executable will be in `build/TicTacToe/`. The name of the executable `TicTacToe` (Linux) or `TicTacToe.exe` (Windows).
