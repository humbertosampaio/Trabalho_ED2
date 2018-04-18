//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_CENARIO4_H
#define TRABALHO_ED2_CENARIO4_H

#include "Hash.h"
#include "HashSeparated.h"
#include "HashCoalesced.h"
#include "HashLinear.h"
#include "HashDouble.h"
#include "HashSeparatedS.h"
#include <iostream>

using namespace std;

void hashComparsion (vector<int> &vetQuestionId, int *memorySpend, float* averageComparsion)
{
    unsigned int n = vetQuestionId.size();
    Hash* hash = nullptr;

    for (int i = 0; i < 5; ++i) {
        switch (i)
        {
            case 0: hash = new HashSeparated(n, false);break;
            case 1: hash = new HashCoalesced(n);break;
            case 2: hash = new HashLinear(n, false);break;
            case 3: hash = new HashLinear(n, true);break;
            case 4: hash = new HashDouble(n);break;
            default: break;
        }
        for (vector<int>::iterator it = vetQuestionId.begin(); it != vetQuestionId.end(); ++it) {
            hash->insert(*it);
        }
        for (vector<int>::iterator it = vetQuestionId.begin(); it != vetQuestionId.end(); ++it)
            hash->find(*it);

        averageComparsion[i] += hash->getAvergareComparsions()/5;
        if (memorySpend != nullptr)
            memorySpend[i] = hash->getMemorySpend();

        cout << i << "\t" << hash->getAvergareComparsions() << "\t" << hash->getMemorySpend() << endl;

        delete hash;
    }
}

void scenario4 (int numberOfSeeds)
{
    int memorySpend[5];
    int averageComparsions[5];
    for (int i = 0; i < 5; ++i)
        averageComparsions[i] = 0;
}


void section2 (vector<int>& vetQuestionId, string tagPath, string questionPath, string answerPath)
{
    
}

#endif //TRABALHO_ED2_CENARIO4_H
