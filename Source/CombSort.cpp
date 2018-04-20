//
// Created by Luis on 15/04/2018.
//

#include "../Headers/CompareCount.h"
#include "../Headers/CombSort.h"

/**
 * Referencias sobre o algoritmo se encontra no Link abaixo
 * https://stackoverflow.com/questions/23425502/what-is-the-fastest-simple-sorting-algorithm-except-quick-sort-merge-sort-for
 * @tparam T
 * @param vet
 */
template<class T> void CombSort::combSort(vector<T> &vet)
{
    CompareCount::initializeCounters("Comb Sort", vet.size());
	CompareCount::setTimeStart();
	double magic_number = 1.247330950103979;
	int size = vet.size();
	int gap = size;

	bool swapped = false;
	while ((gap > 1) || swapped)
	{
		CompareCount::incrementComparison();
		if (gap > 1)
		{
			gap = int(gap / magic_number);
		}
		CompareCount::incrementComparison();

		swapped = false;

		for (int i = 0; gap + i < size; i++)
		{
			if (vet[i + gap] < vet[i])
			{
				CompareCount::incrementCopia();
				CompareCount::incrementCopia();
				CompareCount::incrementCopia();
				swap(vet[i + gap], vet[i]);
				swapped = true;
			}
			CompareCount::incrementComparison();
		}
		CompareCount::incrementComparison();
	}
	CompareCount::incrementComparison();
	CompareCount::timeEnd();
	FileUtils::writeToOutputFile(CompareCount::getDataString());
}

