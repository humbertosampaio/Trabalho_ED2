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
        Headers/MergeSort.h
        Headers/Question.h
        Headers/QuestionList.h
        Headers/QuickSort.h
        Headers/Tag.h
        Headers/CombSort.h
        Headers/HashDouble.h
        Headers/HashLinear.h
        Headers/Cenario4.h
        Headers/HashCoalesced.h
        Source/CombSort.cpp
        Source/HashCoalesced.cpp
        Source/HashDouble.cpp
        Source/HashLinear.cpp
        Source/Answer.cpp
        Source/FileUtils.cpp
        Source/Hash.cpp
        Source/HashSeparated.cpp
        Source/HeapSort.cpp
        Source/InsertionSort.cpp
        Source/MergeSort.cpp
        Source/Question.cpp
        Source/QuestionList.cpp
        Source/QuickSort.cpp
        Source/Tag.cpp
        main.cpp)
