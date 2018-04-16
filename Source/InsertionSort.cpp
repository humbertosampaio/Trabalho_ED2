//
// Created by viniman on 11/04/18.
//
#include "../Headers/InsertionSort.h"

using namespace std;


template <class T>
void InsertionSort::insertionSort(vector<T> &vet, int ini, int fim)
{
    for(int i=ini+1; i<fim; i++)
    {
        T pivo = vet[i];
        int j = i-1;
        while(j>=ini && vet[j] > pivo)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
}
