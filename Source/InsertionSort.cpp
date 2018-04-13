//
// Created by viniman on 11/04/18.
//
#include "../Headers/InsertionSort.h"

using namespace std;

/// Uso de sobrecarga de operadores
//bool operator< (const Question &a, const Question &b) {
  //  return a.getQuestionId() < b.getQuestionId();
//}

//void InsertionSort::insertionSort(vector<Question*> vet, const int &tam)

template <class T> void InsertionSort::insertionSort(vector<T> &vet)
{
    clock_t tStart = clock();
    int size = vet.size();
    for(unsigned int i=1; i<size; i++)
    {
        T pivo = vet[i];
        int j = i-1;
        while(j>=0 && vet[j] > pivo)
        {
            //cout << vet[j] << " > " << pivo << endl;
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
    cout << "tempo de execucao insertion sort" << fixed << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
