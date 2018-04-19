//
// Created by edson on 13/04/18.
//

#ifndef TRABALHO_ED2_HASH_H
#define TRABALHO_ED2_HASH_H

#include <cmath>
#include <iostream>

using namespace std;

class Hash {
	protected:
	unsigned int size;
	unsigned int collisionCounter;
	int* hashTable;
	unsigned int memorySpend;
	unsigned int extraMemory;
	bool extraSize;

	public:
	unsigned int keyFunction(unsigned int value);
	float getAvergareComparsions();
	unsigned int getMemorySpend();
	void printElements();
	virtual void insert(unsigned int value) {};
	virtual void find(unsigned int value) {};
	Hash(unsigned int size, bool extraSize);
	~Hash();
	unsigned int numberOfComparsions;
	unsigned int comparsionCounter;

	unsigned int getCollisionCounter() const;
};


#endif //TRABALHO_ED2_HASH_H
