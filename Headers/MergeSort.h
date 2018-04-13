//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_MERGESORT_H
#define TRABALHO_ED2_MERGESORT_H

#include <vector>
#include "Question.h"

//class vector;

class MergeSort {

    template <class T> static void intercala(vector<T> &vet, int inicio, int meio, int fim);

public:
    template <class T> static void mergeSort(vector<T> &vet, int inicio, int fim);
};


#endif //TRABALHO_ED2_MERGESORT_H
