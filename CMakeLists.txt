cmake_minimum_required(VERSION 3.9.6)
project(Trabalho_ED2)

set(CMAKE_CXX_STANDARD 11)

include_directories(Headers)

add_executable(Trabalho_ED2
        Headers/Answer.h
        Headers/CombSort.h
        Headers/CompareCount.h
        Headers/FileUtils.h
        Headers/Hash.h
        Headers/HashCoalesced.h
        Headers/HashDouble.h
        Headers/HashLinear.h
        Headers/HashSeparated.h
        Headers/HashSeparatedS.h
        Headers/HeapSort.h
        Headers/InsertionSort.h
        Headers/MergeSort.h
        Headers/Question.h
        Headers/QuickSort.h
        Headers/Tag.h
        Headers/Vertex.h
        Source/Answer.cpp
        Source/CombSort.cpp
        Source/CompareCount.cpp
        Source/FileUtils.cpp
        Source/Hash.cpp
        Source/HashCoalesced.cpp
        Source/HashDouble.cpp
        Source/HashLinear.cpp
        Source/HashSeparated.cpp
        Source/HashSeparatedS.cpp
        Source/HeapSort.cpp
        Source/InsertionSort.cpp
        Source/MergeSort.cpp
        Source/Question.cpp
        Source/QuickSort.cpp
        Source/Tag.cpp
        Source/Vertex.cpp
        main.cpp)
