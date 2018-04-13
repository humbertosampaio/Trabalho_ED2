//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_QUICKSORT_H
#define TRABALHO_ED2_QUICKSORT_H

#include <iostream>
#include <algorithm>
#include <utility>

class QuickSort {
public:
    static void quickSort(int *vet, int inicio, int fim);

private:
    static int particiona(int *vet, int left, int right, double pivo);
};


#endif //TRABALHO_ED2_QUICKSORT_H
