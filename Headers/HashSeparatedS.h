//
// Created by edson on 17/04/18.
//

#ifndef TRABALHO_ED2_HASHSEPARATEDS_H
#define TRABALHO_ED2_HASHSEPARATEDS_H

#include <iostream>
#include <vector>
#include <string>
#include "Vertex.h"

using namespace std;

class Vertex;
class HashSeparatedS {
	private:
	unsigned long int size;

	Vertex* collisionTable;
	Vertex* hashTable;

	public:
	HashSeparatedS(unsigned int size);
	unsigned long int keyFunctionStr(string value);
	void insert(string value);
	void find(string value);
	void printElements();
	void insertElementsVector(vector<Vertex>& vertexVec);
};

#endif //TRABALHO_ED2_HASHSEPARATEDS_H
