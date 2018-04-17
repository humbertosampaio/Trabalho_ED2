//
// Created by viniman on 11/04/18.
//

#include <ctime>
#include <set>
#include <random>
#include <chrono>
#include "../Headers/InsertionSort.h"
#include "../Headers/QuickSort.h"

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
void QuickSort::quickSortMediana(vector<T> &vet, int began, int end , int k)
{
    if(k==3 || k==5) {
        ///Se o vetor tiver menos de 10 elementos, ordena com InsertionSort (Knuth)
        if(end-began < 10)
        {
            InsertionSort::insertionSort(vet, began, end);
        }
        else {
            /***Mediana***/
            srand((time(nullptr)));
            long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
            mt19937 eng(seed);    ///mersenne twister engine
            uniform_int_distribution<unsigned long> uniformDistribution(began, end-1);
            vector<T> vecMediana;
            while (vecMediana.size() < k) {
                unsigned int rnd = uniformDistribution(eng);
                if (count(vecMediana.begin(), vecMediana.end(), vet[rnd]) == 0)
                    vecMediana.push_back(vet[rnd]);
            }
            for(auto it : vecMediana)
                cout << it << " ";
            cout << endl;
            ///Ordenar vector para selecionar a mediana entre os valores
            InsertionSort::insertionSort(vecMediana, 0, vecMediana.size());
            auto meio = vet.begin() + began + (end - began + 1) / 2;
            auto mediana = find(vet.begin(), vet.end(), vecMediana[vecMediana.size() / 2]);

            iter_swap(mediana, meio);
            auto aux = meio;
            T pivo = vet[(began + end) / 2];
            /***Fim Mediana***/

            /***QuickSort***/
            int i, j;
            i = began;
            j = end - 1;
            while (i <= j) {
                while (vet[i] < pivo && i < end) {
                    i++;
                }
                while (vet[j] > pivo && j > began) {
                    j--;
                }
                if (i <= j) {
                    T aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                    i++;
                    j--;
                }
            }
            if (j > began)
                quickSortMediana(vet, began, j + 1, k);
            if (i < end)
                quickSortMediana(vet, i, end, k);
        }
    }
    else
        cout << "Erro! Experimente com k=3 ou k=5." << endl;
}

template<class T>
void QuickSort::quickSortInsercao(vector<T> &vet, int m)
{
    if(m==10 || m==100)
    {
        for(int i = 0; i*m < vet.size(); i++)
        {
            InsertionSort::insertionSort(vet,i*m,((i*m+m<=vet.size()) ? i*m+m : vet.size()));
        }
        ///Chamada do quickSort recursivo para terminar as ordenação que começaram a ser feita por partições de inserção
        quickSort(vet, 0, vet.size());
    }
    else
        cout << "Erro! Experimente com m=10 ou m=100." << endl;
}
