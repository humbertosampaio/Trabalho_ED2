//
// Created by viniman on 11/04/18.
//

#include <ctime>
#include <set>
#include "../Headers/QuickSort.h"
/*
//int QuickSort::particiona(int *vet, int left, int right, double pivo)
template<class T> int QuickSort::particiona(vector<T> &vet, int left, int right, T pivo)
{
    int leftPtr = left-1;
    int rightPtr = right;

    while (true)
    {
        while (vet[++leftPtr] < pivo);
        while(rightPtr > 0 &&vet[--rightPtr] > pivo);

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

template<class T> void QuickSort::quickSort(vector<T> &vet, int left, int right)
{
    if(right-left <=0)
        return;
    else
    {
        T pivo = vet[right];

        int partition = particiona(vet, left, right, pivo);
        quickSort(vet, left,partition-1);
        quickSort(vet, partition+1, right);
    }
}
*/

/*template <class T>
void QuickSort::quickSort(vector<T> &vet)
{
    if(vet.size() <=0)
        return;
    else
    {
        int pivo = vet[vet.size()-1];

        int left,right;
        //int partition = particiona(vet, left, right, pivo);
        quickSort(vet);
        quickSort(vet);




        while (true) {
            while (vet[++left] < pivo);
            while (right > 0 && vet[--right] > pivo);

            if (left >= right)
                break;
            else {
                //std::swap(leftPtr, rightPtr);
                int aux = left;
                left = right;
                right = aux;
            }
        }

        int aux = left;
        left = right;
        right = aux;

        return  left;
    }
}
*/

template<class T>
void QuickSort::quickSort(vector<T> &values, int began, int end)
{
    int i, j;
    i = began;
    j = end-1;
    T pivo = values[(began + end) / 2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end)
        {
            i++;
        }
        while(values[j] > pivo && j > began)
        {
            j--;
        }
        if(i <= j)
        {
            T aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quickSort(values, began, j+1);
    if(i < end)
        quickSort(values, i, end);
}


template<class T>
void QuickSort::quickSortMediana(vector<T> &values, int began, int end)
{
    int i, j;
    i = began;
    j = end-1;
    T pivo = values[(began + end) / 2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end)
        {
            i++;
        }
        while(values[j] > pivo && j > began)
        {
            j--;
        }
        if(i <= j)
        {
            T aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quickSortMediana(values, began, j+1);
    if(i < end)
        quickSortMediana(values, i, end);
}


///k=3,k=5
template<class T>
int QuickSort::mediana(vector<T> &vet, int k)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    set<T> s;
    int mediana;
    while (s.size() < k)
        s.insert(vet[rand()%vet.size()]);
    if(s)
    mediana = s.[s.size()/2];

    //colocar pivo na direita
    swap(vet[center], vet[right-1]);
    return vet[right-1];
}