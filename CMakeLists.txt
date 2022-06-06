cmake_minimum_required(VERSION 3.20)
project(Gierka)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 20)
add_compile_options(-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window)
link_libraries(-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window)

add_executable(Gierka src/Main.cpp) 