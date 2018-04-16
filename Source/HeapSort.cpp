//
// Created by viniman on 11/04/18.
//

#include "../Headers/HeapSort.h"

template <class T> void HeapSort::heapSort(vector<T> &vector)
{
    clock_t tStart = clock();

    int length = vector.size();
    for(int i = (length / 2) - 1; i >= 0; i--)
    	makeHeapForOneRamification(vector, i, length);

    while(length > 0)
    {
    	T maior = vector[0];
    	vector[0] = vector[length - 1];
    	vector[length - 1] = maior;
    	makeHeapForOneRamification(vector, 0, --length);
    }

    cout << "Tempo de execucao Heap Sort: " << fixed << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl << endl;
}

template <class T> void HeapSort::makeHeapForOneRamification(vector<T> &vector, int rootIndex, int length)
{
	int childIndex;
	auto rootValue = vector[rootIndex];

	while(rootIndex < length / 2)
	{
		childIndex = (rootIndex * 2) + 1;

		if((childIndex < length - 1) && (vector[childIndex] < vector[childIndex + 1]))
			++childIndex;

		T childValue = vector[childIndex];
		if(rootValue >= childValue)
			break;

		vector[rootIndex] = childValue;
		rootIndex = childIndex;
	}
	vector[rootIndex] = rootValue;
}