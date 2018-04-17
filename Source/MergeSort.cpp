//
// Created by viniman on 11/04/18.
//

#include "../Headers/MergeSort.h"

using namespace std;

/**
 * Algoritmo MergeSort
 * @tparam T: Generelização de método por template
 * @param vet: vector parametrizado para ordenação (int ou Question)
 */
template<class T> void MergeSort::mergeSort(vector<T> &vet) {

    CompareCount::initializeCounters("Merge Sort");
    CompareCount::setTimeStart();
    if (vet.size() > 1)
    {
        typename vector<T>::iterator meio = vet.begin() + (vet.size() / 2);

        vector<T> left(vet.begin(), meio);
        vector<T> right(meio, vet.end());
        for(int i = 0; i < vet.size(); i++)
            CompareCount::incrementCopia();

        MergeSort::mergeSort(left);
        MergeSort::mergeSort(right);


        ///Intercala
        unsigned int itLeft = 0, itRight = 0, itVet = 0;

        while (itLeft < left.size() && itRight < right.size())
        {
            CompareCount::incrementComparison();
            CompareCount::incrementComparison();
            if (left[itLeft] < right[itRight])
            {
                CompareCount::incrementComparison();
                vet[itVet++] = left[itLeft++];
                CompareCount::incrementCopia();
            } else
            {
                vet[itVet++] = right[itRight++];
                CompareCount::incrementCopia();
            }
        }
        CompareCount::incrementComparison();
        CompareCount::incrementComparison();

        while (itLeft < left.size())
        {
            CompareCount::incrementComparison();
            vet[itVet++] = left[itLeft++];
            CompareCount::incrementCopia();
        }
        CompareCount::incrementComparison();
        CompareCount::incrementComparison();

        while (itRight < right.size())
        {
            CompareCount::incrementComparison();
            vet[itVet++] = right[itRight++];
            CompareCount::incrementCopia();
        }
        CompareCount::incrementComparison();
        CompareCount::incrementComparison();
    }
    CompareCount::timeEnd();
    FileUtils::writeToOutputFile(CompareCount::getDataString());
}
