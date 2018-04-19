//
// Created by edson on 17/04/18.
//

#include "../Headers/HashSeparatedS.h"
#include <string>

HashSeparatedS::HashSeparatedS(unsigned int size)
{
    hashTable = new Vertex[size];
    collisionTable = new Vertex[size];
    this->size = size;
}

unsigned long int HashSeparatedS::keyFunctionStr(string value)
{
    unsigned long hash = 5381;
    int c;
    int i = -1;
    while (++i < value.size()) {
        c = (unsigned char) value.at(i);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash%size;
}

void HashSeparatedS::insert(string value)
{
    unsigned long int key = keyFunctionStr(value);
    if (hashTable[key].valueStr.empty() || hashTable[key].valueStr == value) {
        hashTable[key].valueStr = value;
        ++hashTable[key].frequence;
    }
    else
    {
        Vertex* vertex = &collisionTable[key];
        if (vertex->valueStr.empty() || vertex->valueStr == value) {
            if (vertex->valueStr.empty())
                vertex->valueStr = value;
            ++vertex->frequence;
        }
        else {
            while (vertex->next != nullptr && vertex->valueStr != value)
                vertex = vertex->next;
            if (vertex->next == nullptr) {
                vertex->next = new Vertex(value, nullptr, 0);
            }
            ++vertex->next->frequence;
        }
    }
}

void HashSeparatedS::find(string value)
{
    unsigned int key = keyFunctionStr(value);
    if (hashTable[key].valueStr == value) {
        hashTable[key].frequence++;
        return;
    }
    else
    {
        Vertex* vertex = &this->collisionTable[key];
        while (vertex->valueStr != value)
            vertex = vertex->next;
        vertex->frequence++;
    }
}

void HashSeparatedS::printElements()
{
    Vertex* vertex;
    for (int i = 0; i < size; ++i)
    {
        if (!hashTable[i].valueStr.empty()) {
            cout << i+1 << ": ";
            cout << hashTable[i].frequence << hashTable[i].valueStr;
            cout << endl;
        }
        vertex = &collisionTable[i];
        if (!vertex->valueStr.empty()) {
            cout << "colisoes: ";
            while (vertex != nullptr) {
                cout << vertex->frequence<< vertex->valueStr << " ";
                vertex = vertex->next;
            }
            cout << endl;
        }
    }
}

void HashSeparatedS::insertElementsVector(vector<Vertex>& vertexVec)
{
    Vertex* vertex;
    for (int i = 0; i < size; ++i)
    {
        if (!hashTable[i].valueStr.empty()) {
            //vertexVec.emplace_back(hashTable[i].valueStr, hashTable[i].next, hashTable[i].frequence);
            vertexVec.emplace_back(hashTable[i].valueStr, nullptr, hashTable[i].frequence);
        }
        vertex = &collisionTable[i];
        if (vertex != nullptr)
            if (!vertex->valueStr.empty()) {
                while (vertex != nullptr) {
                    vertexVec.emplace_back(vertex->valueStr, nullptr, vertex->frequence);
                    vertex = vertex->next;
            }
        }
    }
}
