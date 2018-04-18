//
// Created by edson on 15/04/18.
//

#ifndef TRABALHO_ED2_CENARIO4_H
#define TRABALHO_ED2_CENARIO4_H

#include "Hash.h"
#include "HashSeparated.h"
#include "HashCoalesced.h"
#include "HashLinear.h"
#include "HashDouble.h"
#include <iostream>

using namespace std;

void funcao(vector<int>& vetQuestionId)
{
	unsigned int n = vetQuestionId.size();
	HashSeparated hashSeparated(n);
	HashCoalesced hashCoalesced(n);
	HashLinear hashLinear(n, false);
	HashLinear hashQuadratic(n, true);
	HashDouble hashDouble(n);
	for (vector<int>::iterator it = vetQuestionId.begin(); it != vetQuestionId.end(); ++it)
	{
	}
}

void section2(vector<int>& vetQuestionId)
{

}

#endif //TRABALHO_ED2_CENARIO4_H
