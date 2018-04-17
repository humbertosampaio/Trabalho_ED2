//
// Created by edson on 15/04/18.
//

#include "../Headers/HashCoalesced.h"


void HashCoalesced::insert(unsigned int value)
{

    if (elementCounter < size) {
        unsigned int key = keyFunction(value);
        if (hashTable[key] == 0) {
            hashTable[key] = value;
            pointerTable[key] = -1;
        }
        else {
            if (pointerTable[key] > 0) {
                int i = pointerTable[key];
                while (pointerTable[i] > 0)
                    i = pointerTable[i];

                int j;
                for (j = i; -1 < j; --j)
                    if (pointerTable[j] == -2)
                        break;

                hashTable[j] = value;
                pointerTable[j] = -1;
                pointerTable[i] = j;
            }
            else
            {
                int i;
                for (i = size-1; i > -1; --i)
                    if (pointerTable[i] == -2)
                        break;
                hashTable[i] = value;
                pointerTable[i] = -1;
                pointerTable[key] = i;
            }
            ++collisionCounter;
        }
        ++elementCounter;
    }
    else
        cout << "hash cheio, nao foi possivel inserir " << value << endl;
}

void HashCoalesced::find(unsigned int value)
{
    ++comparsionCounter;
    ++numberOfComparsions;
    unsigned int key = keyFunction(value);
    int i = key;
    while (hashTable[i] != value && i >= 0)
    {
        i = pointerTable[i];
        ++numberOfComparsions;
    }
}

void HashCoalesced::printElements()
{
    for (int i = 0; i < size; ++i)
        cout << i << ": " << hashTable[i] << " " << pointerTable[i] << endl;
}