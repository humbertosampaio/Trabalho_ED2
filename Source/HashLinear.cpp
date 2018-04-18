//
// Created by edson on 13/04/18.
//

#include "../Headers/HashLinear.h"

void HashLinear::insert(unsigned int value)
{
    if (elementCounter < size) {
        if (quadratic) insertQuadratic(value);
        else insertLinear(value);
        ++elementCounter;
    }
    else
        cout << "hash cheio, nao foi possivel inserir " << value << endl;
}

void HashLinear::insertLinear(int value)
{
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        for (int i = key + 1; i <= size  + key; ++i)
            if (hashTable[i % size] == 0) {
                hashTable[i % size] = value;
                break;
            }
        ++collisionCounter;
    }
}

void HashLinear::insertQuadratic(int value)
{
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        int i = 1;
        while (hashTable[(key+(i*i)) % size] != 0){
            ++i;
            }
        hashTable[(key+(i*i)) % size] = value;
        ++collisionCounter;
    }
}

void HashLinear::find(unsigned int value)
{
    if (quadratic) findQuadratic(value);
    else findLinear(value);
}

void HashLinear::findLinear(int value)
{
    ++numberOfComparsions;
    ++comparsionCounter;
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == value)
        return;
    else
    {
        ++numberOfComparsions;
        for (int i = key + 1; i <= size  + key; ++i) {
            ++numberOfComparsions;
            if (hashTable[i % size] == value) {
                return;
            }
        }
    }
}

void HashLinear::findQuadratic(int value)
{
    ++numberOfComparsions;
    ++comparsionCounter;
    unsigned int key = Hash::keyFunction(value);
    if (hashTable[key] == value)
        return;
    else
    {
        int i = 1;
        while (hashTable[(key+(i*i)) % size] != value){
            ++numberOfComparsions;
            ++i;
        }
    }
}