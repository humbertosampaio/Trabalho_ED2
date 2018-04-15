//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_COALESCEDHASH_H
#define TRABALHO_ED2_COALESCEDHASH_H

#include "Hash.h"
#include <iostream>

using namespace std;

class CoalescedHash : public Hash {
public:

    void insert (unsigned int value);
    void printElements();

    CoalescedHash(unsigned int size):Hash(size)
    {
        pointerTable = new int[size];
        for (int i = 0; i < size; ++i)
            pointerTable[i] = -2;
        elementCounter = 0;
    }

private:
    int* pointerTable;
    int elementCounter;
};


#endif //TRABALHO_ED2_COALESCEDHASH_H
