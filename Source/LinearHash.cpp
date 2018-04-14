//
// Created by edson on 13/04/18.
//

#include "../Headers/LinearHash.h"

void LinearHash::insert(int value)
{
    if (elementCounter < size)
    {
        unsigned int key = Hash::keyFunction(value);
        if (hashTable[key] == 0)
            hashTable[key] = value;
        else
        {
            for (int i = key; i < size  + key; ++i)
                if (hashTable[i % size] == 0) {
                    hashTable[i % size] = value;
                    break;
                }
        }
        ++elementCounter;
    }
    else
        cout << "hash cheio, nao foi possivel inserir " << value << endl;
}

void LinearHash::printElements()
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << ":";
        if (hashTable[i] != 0)
           cout <<" " << hashTable[i];
        cout << endl;
    }
}