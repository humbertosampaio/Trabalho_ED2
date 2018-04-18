//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_INSERTIONSORT_H
#define TRABALHO_ED2_INSERTIONSORT_H

#include <iostream>
#include <ctime>
#include <vector>
#include "Question.h"
#include "CompareCount.h"
#include "FileUtils.h"


class InsertionSort {
public:
    template <class T> static void insertionSort(vector<T> &vet, int ini, int fim);
    template <class T> static void insertionSort(vector<T> &vet);
};

#endif //TRABALHO_ED2_INSERTIONSORT_H
