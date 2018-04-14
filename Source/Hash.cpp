//
// Created by edson on 13/04/18.
//

#include "../Headers/Hash.h"

Hash::Hash(unsigned int size)
{
    this->size = size;
    this->collisionCounter = 0;
    this->hashTable = new int [size];
    for (int i = 0; i < size; ++i)
        hashTable[i] = 0;
}

unsigned int Hash::keyFunction(int value)
{
    return value;
}