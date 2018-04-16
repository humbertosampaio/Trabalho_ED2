//
// Created by viniman on 11/04/18.
//

#include "../Headers/MergeSort.h"

using namespace std;

template<class T>
void MergeSort::mergeSort(vector<T> &vet) {

    if (vet.size() > 1)
    {
        typename vector<T>::iterator meio = vet.begin() + (vet.size() / 2);

        vector<T> left(vet.begin(), meio);
        vector<T> right(meio, vet.end());

        MergeSort::mergeSort(left);
        MergeSort::mergeSort(right);

        //Intercala
        unsigned int itLeft = 0, itRight = 0, itVet = 0;

        while (itLeft < left.size() && itRight < right.size()) {
            //incrementCount(1);
            if (left[itLeft] < right[itRight]) {
                vet[itVet++] = left[itLeft++];
                //itLeft++;
            } else {
                vet[itVet++] = right[itRight++];
                //itRight++;
            }

            //itVet++;
        }

        while (itLeft < left.size()) {
            vet[itVet++] = left[itLeft++];
            //itLeft++;
            //itVet++;
        }

        while (itRight < right.size()) {
            vet[itVet++] = right[itRight++];
            //itRight++;
            //itVet++;
        }
    }
}
