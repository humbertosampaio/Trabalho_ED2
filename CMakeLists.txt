cmake_minimum_required(VERSION 3.9.6)
project(Trabalho_ED2)

set(CMAKE_CXX_STANDARD 11)

include_directories(Headers)

add_executable(Trabalho_ED2
        Headers/Answer.h
        Headers/FileUtils.h
        Headers/HeapSort.h
        Headers/InsertionSort.h
        Headers/MergeSort.h
        Headers/Question.h
        Headers/QuickSort.h
        Headers/Tag.h
        Headers/HashSeparated.h
        Headers/QuestionList.h
        Source/QuestionList.cpp
        Source/HashSeparated.cpp
        Source/Answer.cpp
        Source/FileUtils.cpp
        Source/HeapSort.cpp
        Source/InsertionSort.cpp
        Source/MergeSort.cpp
        Source/Question.cpp
        Source/QuickSort.cpp
        Source/Tag.cpp
        main.cpp Source/Hash.cpp Headers/Hash.h Headers/LinearHash.cpp Headers/LinearHash.h)
