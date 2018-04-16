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
    this->memorySpend = 4*size + 4;
    extraMemory = 0;
    comparsionCounter = 0;
    numberOfComparsions = 0;
}
/*
 * funcao djb2 de hash para strings com nossa adaptacao para inteiros
 * referencia: http://www.cse.yorku.ca/~oz/hash.html
 * */
unsigned int Hash::keyFunction(unsigned int value)
{
    unsigned long int key = 5381;
    //cria um vetor de caracteres em relacao ao valor a ser inserido
    string str;
    str = to_string(value);
    char c;
    int i = 0;
    while (i < str.size()) {
        c = (char)str.at(i);
        key = ((key << 5) + key) + (int) abs(c); // key * 33 + c
        ++i;
    }
    return key%size;
}

unsigned int Hash::getCollisionCounter() const {
    return collisionCounter;
}

void Hash::printElements()
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << ":";
        if (hashTable[i] != 0)
            cout <<" " << hashTable[i];
        cout << endl;
    }
}