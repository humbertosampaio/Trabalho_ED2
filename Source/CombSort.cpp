//
// Created by Luis on 15/04/2018.
//

#include "../Headers/CombSort.h"

template<class T> void CombSort::combSort(vector<T> &vet)
{
	double magic_number = 1.247330950103979;
	int size = vet.size();
	int gap = size;

	bool swapped = false;
	while ((gap > 1) || swapped)
	{
		if (gap > 1)
		{
			gap = int(gap / magic_number);
		}

		swapped = false;

		for (int i = 0; gap + i < size; i++)
		{
			if (vet[i + gap] < vet[i])
			{
				swap(vet[i + gap], vet[i]);
				swapped = true;
			}

		}

	}

}

