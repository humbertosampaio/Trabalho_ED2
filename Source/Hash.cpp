//
// Created by edson on 13/04/18.
//

#include "Hash.h"

Hash::Hash(unsigned int size)
{
    this->size = size;
    this->collisionCounter = 0;
    this->hashTable = new int [size];
}

Hash::Hash() = default;

unsigned int Hash::keyFunction(int value)
{
    return value;
}