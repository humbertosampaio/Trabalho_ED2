//
// Created by edson on 15/04/18.
//

#include "../Headers/DoubleHash.h"


void DoubleHash::insert(int value)
{
    if (elementCounter < size) {
        unsigned int key = keyFunction(value);
        if (hashTable[key] == 0)
            hashTable[key] = value;
        else {
            unsigned int i = 1;
            unsigned int secKeyConst = secondaryFunction(value);
            unsigned int secKey = secKeyConst;
            while (hashTable[(key + secKey) % size] != 0) {
                secKey = i * secKeyConst;
                ++i;
            }
            hashTable[(key + secKey) % size] = value;
            ++collisionCounter;
        }
        ++elementCounter;
    } else
        cout << "hash cheio, nao foi possivel inserir " << value << endl;
}

unsigned int DoubleHash::secondaryFunction(unsigned int value)
{
    return value;
}
