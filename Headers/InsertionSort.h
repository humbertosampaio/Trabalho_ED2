//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_INSERTIONSORT_H
#define TRABALHO_ED2_INSERTIONSORT_H
#include <iostream>
#include <ctime>
#include <vector>
#include "Question.h"



class InsertionSort {
public:
    //template <class T> static void insertionSort( T *vet, const int &tam);
   // bool operator< (const Question &b);
    //static void insertionSort(vector<Question> vet, const int &tam);

    //static void insertionSort(vector<Question *> vet, const int &tam);
    template <class T> static void insertionSort(vector<T> &vet);
};

#endif //TRABALHO_ED2_INSERTIONSORT_H
