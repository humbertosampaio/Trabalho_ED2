//
// Created by viniman on 11/04/18.
//

#include "../Headers/QuickSort.h"

int QuickSort::particiona(int *vet, int left, int right, double pivo)
{
    int leftPtr = left-1;
    int rightPtr = right;

    while (true)
    {
        while (vet[++leftPtr] < pivo);
        while(rightPtr > 0 && vet[--rightPtr] > pivo);

        if(leftPtr >= rightPtr)
            break;
        else
        {
            //std::swap(leftPtr, rightPtr);
            int aux = leftPtr;
            leftPtr = rightPtr;
            rightPtr = aux;
        }

    }

    //std::swap(leftPtr, rightPtr-1);
    int aux = leftPtr;
    leftPtr = right;
    right = aux;

    return  leftPtr;
}

void QuickSort::quickSort(int *vet, int left, int right)
{
    if(right-left <=0)
        return;
    else
    {
        int pivo = vet[right];

        int partition = particiona(vet, left, right, pivo);
        quickSort(vet, left,partition-1);
        quickSort(vet, partition+1, right);
    }
}

