//
// Created by viniman on 11/04/18.
//

#ifndef TRABALHO_ED2_HEAPSORT_H
#define TRABALHO_ED2_HEAPSORT_H

#include <iostream>
#include <ctime>
#include <vector>
#include "Question.h"
#include "FileUtils.h"
#include "CompareCount.h"

class HeapSort
{
	public:
	template <class T> static void heapSort(vector<T> &vector);
	template <class T> static void makeHeapForOneRamification(vector<T> &vector, int rootIndex, int length);
};

#endif //TRABALHO_ED2_HEAPSORT_H
