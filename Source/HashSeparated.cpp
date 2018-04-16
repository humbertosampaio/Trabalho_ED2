//
// Created by edson on 13/04/18.
//

#include "../Headers/HashSeparated.h"


HashSeparated::~HashSeparated()
{
    delete []collisionTable;
    delete []hashTable;
}

void HashSeparated::insert(unsigned int value)
{
    unsigned int key = keyFunction(value);
    if (hashTable[key] == 0)
        hashTable[key] = value;
    else
    {
        ++collisionCounter;
        Vertex* vertex = &collisionTable[key];
        if (vertex->value == 0)
            vertex->value = value;
        else {
            while (vertex->next != nullptr)
                vertex = vertex->next;
            vertex->next = new Vertex(value, nullptr);
        }
    }
}

void HashSeparated::find(unsigned int value)
{
    ++numberOfComparsions;
    ++comparsionCounter;
    unsigned int key = keyFunction(value);
    if (hashTable[key] == value)
        return;
    else
    {
        ++numberOfComparsions;
        Vertex* vertex = this->collisionTable;
        while (vertex->value != value)
        {
            vertex = vertex->next;
            ++numberOfComparsions;
        }
    }
}

void HashSeparated::printElements()
{
    Vertex* vertex;
    for (int i = 0; i < size; ++i)
    {
        cout << i+1 << ": ";
        if (hashTable[i] != 0) {
            cout << hashTable[i];
            cout << endl;
        }
        vertex = &collisionTable[i];
        if (vertex->value != 0) {
            cout << "colisoes: ";
            while (vertex != nullptr) {
                cout << vertex->value << " ";
                vertex = vertex->next;
            }
            cout << endl;
        }
    }
}