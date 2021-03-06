//
// Created by edson on 15/04/18.
//

#include "../Headers/HashDouble.h"


void HashDouble::insert(unsigned int value)
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

void HashDouble::find(unsigned int value)
{
    ++comparsionCounter;
    ++numberOfComparsions;
    unsigned int key = keyFunction(value);
    if (hashTable[key] == value)
        return;
    else
    {
        unsigned int i = 1;
        unsigned int secKeyConst = secondaryFunction(value);
        unsigned int secKey = secKeyConst;
        ++numberOfComparsions;
        while (hashTable[(key + secKey) % size] != value) {
            secKey = i * secKeyConst;
            ++i;
            ++numberOfComparsions;
        }
    }
}
/*
unsigned int HashDouble::secondaryFunction(unsigned int value)
{
    while (value%size == 0)
        ++value;
    return value%size;
}
*/
unsigned int HashDouble::secondaryFunction(unsigned int value)
{
    unsigned long key = 0;
    string str = to_string(value);
    char c;
    int i = 0;
    while (c = str.size()) {
        c = (char)str.at(i);
        key = c + (key << 6) + (key << 16) - key;
    }
    while (key%size == 0)
        ++key;
    return key;
}