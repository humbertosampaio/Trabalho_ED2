//
// Created by viniman on 11/04/18.
//

#include "../Headers/QuickSort.h"

/**
 *
 * @tparam T
 * @param vect
 * @param codigAlgorithm
 */
template<class T> void QuickSort::quickSort(vector<T> &vect, int codigAlgorithm)
{
    if (codigAlgorithm == 0)
    {
        CompareCount::initializeCounters("Quick Sort Recursivo", vect.size());
        CompareCount::setTimeStart();
        quickSortRec(vect, 0, vect.size());
    }
    else if (codigAlgorithm == 3 || codigAlgorithm == 5)
    {
        CompareCount::initializeCounters("Quick Sort Mediana (K = " + to_string(codigAlgorithm) + ")", vect.size());
        CompareCount::setTimeStart();
        quickSortMediana(vect, 0, vect.size(), codigAlgorithm);
    }
    else if (codigAlgorithm == 10 || codigAlgorithm == 100)
    {
        CompareCount::initializeCounters("Quick Sort Insercao (M = " + to_string(codigAlgorithm) + ")", vect.size());
        CompareCount::setTimeStart();
        quickSortInsercao(vect, codigAlgorithm);
    }
    else
    {
        CompareCount::initializeCounters("Quick Sort - Código de versão de Algoritmo QSort errado.", 0);
        CompareCount::setTimeStart();
        cout << "De acordo com as especificações, o codigo de algoritmo esta errado!" << endl;
        cout << "Para Quick Sort Recursivo: código 0" << endl;
        cout << "Para Quick Sort Mediana: código 3 ou 5" << endl;
        cout << "Para Quick Sort Insercao: código 10 ou 100" << endl;
    }
    CompareCount::timeEnd();
    FileUtils::writeToOutputFile(CompareCount::getDataString());
}

/**
 *
 * @tparam T
 * @param vect
 * @param ini
 * @param fim
 */
template<class T> void QuickSort::quickSortRec(vector<T> &vect, int ini, int fim) {
    int i, j;
    i = ini;
    j = fim - 1;
    T pivo = vect[(ini + fim) / 2];
    CompareCount::incrementCopia();
    ///Inicio Particionamento
    while (i <= j) {
        CompareCount::incrementComparison();
        while (vect[i] < pivo && i < fim) {
            CompareCount::incrementComparison();
            CompareCount::incrementComparison();
            i++;
        }
        CompareCount::incrementComparison();
        while (vect[j] > pivo && j > ini) {
            CompareCount::incrementComparison();
            CompareCount::incrementComparison();
            j--;
        }
        CompareCount::incrementComparison();
        if (i <= j) {
            T aux = vect[i];
            vect[i] = vect[j];
            vect[j] = aux;
            i++;
            j--;
            CompareCount::incrementCopia();
            CompareCount::incrementCopia();
            CompareCount::incrementCopia();
        }
        CompareCount::incrementComparison();
    }
    ///Fim Particionamento

    ///Chamadas recursivas
    CompareCount::incrementComparison();
    if (j > ini)
        quickSortRec(vect, ini, j + 1);
    CompareCount::incrementComparison();
    if (i < fim)
        quickSortRec(vect, i, fim);
    CompareCount::incrementComparison();
}


/**
 *
 * @tparam T
 * @param vect
 * @param ini
 * @param fim
 * @param k
 */
template<class T> void QuickSort::quickSortMediana(vector<T> &vect, int ini, int fim, int k) {
    ///Se o vetor tiver menos de 10 elementos, ordena com InsertionSort (Knuth)
    if (fim - ini < 10) {
        InsertionSort::insertionSort(vect, ini, fim);
    } else {
        /***Mediana***/
        ///Gerador de números aleatorios C++11
        long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
        mt19937 eng(seed);    ///mersenne twister engine
        uniform_int_distribution<unsigned long> uniformDistribution(ini, fim - 1);
        vector<T> vecMediana;
        while (vecMediana.size() < k) {
            unsigned int rnd = uniformDistribution(eng);
            if (count(vecMediana.begin(), vecMediana.end(), vect[rnd]) == 0)
            {
                vecMediana.push_back(vect[rnd]);
                CompareCount::incrementCopia();
            }
        }
        ///Ordenar vector para selecionar a mediana entre os valores
        InsertionSort::insertionSort(vecMediana, 0, vecMediana.size());
        auto meio = vect.begin() + ini + (fim - ini + 1) / 2;
        auto mediana = find(vect.begin(), vect.end(), vecMediana[vecMediana.size() / 2]);

        CompareCount::incrementCopia();
        CompareCount::incrementCopia();
        CompareCount::incrementCopia();
        iter_swap(mediana, meio);

        CompareCount::incrementCopia();
        T pivo = vect[(ini + fim) / 2];
        /***Fim Mediana***/

        /***QuickSort***/
        int i, j;
        i = ini;
        j = fim - 1;
        ///Inicio Particionamento
        while (i <= j) {
            CompareCount::incrementComparison();
            while (vect[i] < pivo && i < fim) {
                CompareCount::incrementComparison();
                CompareCount::incrementComparison();
                i++;
            }
            CompareCount::incrementComparison();
            while (vect[j] > pivo && j > ini) {
                CompareCount::incrementComparison();
                CompareCount::incrementComparison();
                j--;
            }
            CompareCount::incrementComparison();
            if (i <= j) {
                T aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
                i++;
                j--;
                CompareCount::incrementCopia();
                CompareCount::incrementCopia();
                CompareCount::incrementCopia();
            }
            CompareCount::incrementComparison();
        }
        ///Fim Particionamento

        ///Chamadas recursivas
        CompareCount::incrementComparison();
        if (j > ini)
            quickSortMediana(vect, ini, j + 1, k);
        CompareCount::incrementComparison();
        if (i < fim)
            quickSortMediana(vect, i, fim, k);
        CompareCount::incrementComparison();
    }
}
/**
 * Ordenação feita por blocos de m=10 ou m=100 com o Insertion Sort, e depois terminado a ordenação com Quick Sort
 * @tparam T: template
 * @param vet: vector para ser ordenado
 * @param m número de objetos em cada bloco para ordenar (m=10 ou m=100)
 */
template<class T> void QuickSort::quickSortInsercao(vector<T> &vet, unsigned int m) {
    for (int i = 0; i * m < vet.size(); i++) {
        ///Calcula indicie inicial do bloco
        unsigned int ini = i * m;
        ///Calcula indice final do bloco
        unsigned int fim = (i * m + m <= vet.size()) ? i * m + m : vet.size();
        InsertionSort::insertionSort(vet, ini, fim);
    }
    ///Chamada do quickSort recursivo para terminar as ordenação que começaram a ser feita por partições de inserção
    quickSortRec(vet, 0, vet.size());
}


