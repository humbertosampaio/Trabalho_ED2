//
// Created by viniman on 11/04/18.
//

#include <iostream>
#include "../Headers/InsertionSort.h"


void InsertionSort::insertionSort(int *vet, const int &tam)
{
    clock_t tStart = clock();
    for(unsigned int i=1; i<tam; i++)
    {
        int pivo = vet[i];
        int j = i-1;
        while(j>=0 && vet[j] > pivo)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
    cout << "tempo de execucao insertion sort" << fixed << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
