//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_QUICKSORT_H
#define TRABALHO_ED2_QUICKSORT_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <ctime>
#include <set>
#include <random>
#include <chrono>
#include <string>
#include "Question.h"
#include "FileUtils.h"
#include "InsertionSort.h"
#include "CompareCount.h"

class QuickSort {
public:
    template<class T> static void quickSort(vector<T> &vect, int codigAlgorithm);

private:
    template<class T> static void quickSortRec(vector<T> &vet, int began, int fim);
    template<class T> static void quickSortMediana(vector<T> &values, int ini, int fim, int k);
    template<class T> static void quickSortInsercao(vector<T> &vet, unsigned int m);
};


#endif //TRABALHO_ED2_QUICKSORT_H
