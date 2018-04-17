//
// Created by vinic on 4/16/2018.
//

#include "../Headers/CompareCount.h"

int CompareCount::countNumComparisons;
int CompareCount::countNumCopias;
clock_t CompareCount::timeStart;
double CompareCount::runtime;
bool CompareCount::runtimeCalc;

void CompareCount::clearCounters()
{
    if(runtimeCalc)
    {
        countNumComparisons = 0;
        countNumCopias = 0;
        timeStart = 0;
        runtime = 0;
        runtimeCalc = false;
    }
}

void CompareCount::incrementComparison()
{
    countNumComparisons++;
}

void CompareCount::incrementCopia()
{
    countNumCopias++;
}

void CompareCount::setTimeStart()
{
    timeStart = clock();
}

void CompareCount::timeEnd()
{
    runtimeCalc = true;
    runtime = (double) (clock() - timeStart) / CLOCKS_PER_SEC;
}

void CompareCount::printData()
{
    std::cout << "Comparacoes: " << countNumComparisons << std::endl;
    std::cout << "Copias: " << countNumCopias << std::endl;
    std::cout << "Tempo de Execução: ";
    runtimeCalc ?  std::cout << runtime << std::endl : std::cout << "Nao foi calculado" << std::endl;
}
