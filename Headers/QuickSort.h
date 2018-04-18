//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_QUICKSORT_H
#define TRABALHO_ED2_QUICKSORT_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include "Question.h"
#include <FileUtils.h>

class QuickSort {
public:
    template<class T> static void quickSort(vector<T> &vect, int codigAlgorithm);

private:
    template<class T> static void quickSortRec(vector<T> &vet, int began, int fim);
    template<class T> static void quickSortMediana(vector<T> &values, int ini, int fim, int k);
    template<class T> static void quickSortInsercao(vector<T> &vet, int m);
};


#endif //TRABALHO_ED2_QUICKSORT_H
