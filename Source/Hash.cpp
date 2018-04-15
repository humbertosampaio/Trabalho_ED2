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
/*
 * funcao djb2 de hash para strings com nossa adaptacao para inteiros
 * referencia: http://www.cse.yorku.ca/~oz/hash.html
 * */
/*
unsigned int Hash::keyFunction(int value)
{
    unsigned long key = 5381;
    //cria um vetor de caracteres em relacao ao valor a ser inserido
    char* str = new char[32];
    itoa(value,str, 10);
    int c;
    while (c = *str++)
        key = ((key << 5) + key) + abs(c); // key * 33 + c
    return key%size;
}
*/

unsigned int Hash::keyFunction(unsigned int value) {
    value = ((value >> 16) ^ value) * 0x119de1f3;
    value = ((value >> 16) ^ value) * 0x119de1f3;
    value = (value >> 16) ^ value;
    return value%size;
}

unsigned int Hash::getCollisionCounter() const {
    return collisionCounter;
}
