//
// Created by vinic on 4/16/2018.
//

#ifndef TRABALHO_ED2_COMPARECOUNT_H
#define TRABALHO_ED2_COMPARECOUNT_H

#include <iostream>
#include <ctime>

class CompareCount
{
	private:
		static int countNumComparisons;
		static int countNumCopias;
		static clock_t timeStart;
		static double runtime;
		static bool runtimeCalc;

	public:
		static void clearCounters();
		static void incrementComparison();
		static void incrementCopia();
		static void setTimeStart();
		static void timeEnd();
		static void printData();
		static std::string getDataString();
};

#endif //TRABALHO_ED2_COMPARECOUNT_H
