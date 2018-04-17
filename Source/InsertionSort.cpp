//
// Created by viniman on 11/04/18.
//
#include "../Headers/InsertionSort.h"
#include "../Headers/FileUtils.h"

using namespace std;

/**
 * insertionSort sobrecarregado
 * @tparam T: template para aceitar qualquer classe ou tipo
 * @param vet: vector<T> parametrizado com template
 */
template<class T> void InsertionSort::insertionSort(vector<T> &vet)
{
	CompareCount::clearCounters();
	CompareCount::setTimeStart();
	int size = vet.size();
	for (unsigned int i = 1; i < size; i++)
	{
		T pivo = vet[i];
		CompareCount::incrementCopia();
		int j = i - 1;
		while (j >= 0 && vet[j] > pivo)
		{
			CompareCount::incrementComparison();
			CompareCount::incrementComparison();
			vet[j + 1] = vet[j];
			CompareCount::incrementCopia();
			j--;
		}
		CompareCount::incrementComparison();
		CompareCount::incrementComparison();
		vet[j + 1] = pivo;
		CompareCount::incrementCopia();
	}
	CompareCount::timeEnd();
	FileUtils::writeToOutputFile(CompareCount::getDataString());
}

/**
 * InsertionSort sobrecarregado com inicio e fim, para ordenar partições/pedaços de um vector
 * @tparam T: template para aceitar qualquer classe ou tipo
 * @param vet: vector<T> parametrizado com template
 * @param ini: posição inicial para ordenar o vector
 * @param fim: posição final para ordenar o vector
 */
template<class T> void InsertionSort::insertionSort(vector<T> &vet, int ini, int fim)
{
	CompareCount::clearCounters();
	CompareCount::setTimeStart();
	for (int i = ini + 1; i < fim; i++)
	{
		T pivo = vet[i];
		CompareCount::incrementCopia();
		int j = i - 1;
		while (j >= ini && vet[j] > pivo)
		{
			CompareCount::incrementComparison();
			CompareCount::incrementComparison();
			vet[j + 1] = vet[j];
			CompareCount::incrementCopia();
			j--;
		}
		CompareCount::incrementComparison();
		CompareCount::incrementComparison();
		vet[j + 1] = pivo;
		CompareCount::incrementCopia();
	}
	CompareCount::timeEnd();
	FileUtils::writeToOutputFile(CompareCount::getDataString());
}
