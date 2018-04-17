//
// Created by viniman on 11/04/18.
//

#include "../Headers/HeapSort.h"

template <class T> void HeapSort::heapSort(vector<T> &vector)
{
	CompareCount::initializeCounters("Heap Sort");
	CompareCount::setTimeStart();
    int length = vector.size();
    for(int i = (length / 2) - 1; i >= 0; i--)
	{
		CompareCount::incrementComparison();
		makeHeapForOneRamification(vector, i, length);
	}
	CompareCount::incrementComparison();

    while(length > 0)
    {
		CompareCount::incrementComparison();
    	T maior = vector[0];
    	vector[0] = vector[length - 1];
    	vector[length - 1] = maior;
    	CompareCount::incrementCopia();
		CompareCount::incrementCopia();
		CompareCount::incrementCopia();
    	makeHeapForOneRamification(vector, 0, --length);
    }
	CompareCount::incrementComparison();
	CompareCount::timeEnd();
	FileUtils::writeToOutputFile(CompareCount::getDataString());
}

template <class T> void HeapSort::makeHeapForOneRamification(vector<T> &vector, int rootIndex, int length)
{
	int childIndex;
	auto rootValue = vector[rootIndex];
	CompareCount::incrementCopia();
	while(rootIndex < length / 2)
	{
		CompareCount::incrementComparison();
		childIndex = (rootIndex * 2) + 1;

		CompareCount::incrementComparison();
		CompareCount::incrementComparison();
		if((childIndex < length - 1) && (vector[childIndex] < vector[childIndex + 1]))
			++childIndex;

		CompareCount::incrementCopia();
		T childValue = vector[childIndex];
		CompareCount::incrementComparison();
		if(rootValue >= childValue)
			break;

		CompareCount::incrementCopia();
		vector[rootIndex] = childValue;
		rootIndex = childIndex;
	}
	CompareCount::incrementComparison();
	vector[rootIndex] = rootValue;
	CompareCount::incrementCopia();
}
