cmake_minimum_required(VERSION 3.9)
project(Trabalho_ED2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Trabalho_ED2 main.cpp
        Headers/FileUtils.h
        Headers/Question.h
        Headers/Answer.h
        Headers/Tag.h
        Source/Tag.cpp
        Source/Answer.cpp
        Source/Question.cpp
        Source/FileUtils.cpp
        )