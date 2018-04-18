//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_COALESCEDHASH_H
#define TRABALHO_ED2_COALESCEDHASH_H

#include "Hash.h"
#include <iostream>

using namespace std;

class HashCoalesced : public Hash {
public:

    void insert (unsigned int value)override;
    void find (unsigned int value)override;
    void printElements();

    HashCoalesced(unsigned int size):Hash(size, false)
    {
        pointerTable = new int[size];
        for (int i = 0; i < size; ++i)
            pointerTable[i] = -2;
        elementCounter = 0;
        //4*size da lista auxliar de ponteiros, +4 do ponteiro do inicio da lista + 4 de element counter
        extraMemory += 4*size + 4 + 4;
    }

private:
    int* pointerTable;
    int elementCounter;
};


#endif //TRABALHO_ED2_COALESCEDHASH_H
