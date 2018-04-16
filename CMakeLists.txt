cmake_minimum_required(VERSION 3.9)
project(Trabalho_ED2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Trabalho_ED2
        Headers/Answer.h
        Headers/FileUtils.h
        Headers/Hash.h
        Headers/HashSeparated.h
        Headers/HeapSort.h
        Headers/InsertionSort.h
        Headers/HashLinear.h
        Headers/MergeSort.h
        Headers/Question.h
        Headers/QuestionList.h
        Headers/QuickSort.h
        Headers/Tag.h
        Source/Answer.cpp
        Source/FileUtils.cpp
        Source/Hash.cpp
        Source/HashSeparated.cpp
        Source/HeapSort.cpp
        Source/InsertionSort.cpp
        Source/HashLinear.cpp
        Source/MergeSort.cpp
        Source/Question.cpp
        Source/QuestionList.cpp
        Source/QuickSort.cpp
        Source/Tag.cpp
        main.cpp Source/HashDouble.cpp Headers/HashDouble.h Source/HashCoalesced.cpp Headers/HashCoalesced.h Headers/Cenario4.h)
