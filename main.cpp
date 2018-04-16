#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"
#include "Source/InsertionSort.cpp"
#include "Source/MergeSort.cpp"
#include "Headers/HeapSort.h"
#include "Source/HeapSort.cpp"
#include "Headers/HashCoalesced.h"
#include "Headers/Cenario4.h"

using namespace std;

void sortQuestions(vector<Question> &questionVector);
void sortIntegers(vector<int> &intVector);
vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n);
template<class T> void printVector(const vector<T> &vector);

int main(int argc, char** argv)
{
	//string path = "/home/edson/pythonquestions/Questions.csv"; //edson
	//string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";
	//string path = "../pythonquestions/OriginalFiles/Questions.csv";

	vector<Question> listQuestions;
	//FileUtils::readFileQuestion(path, listQuestions);


    HashCoalesced cl(20);


    for (int i = 0; i < 20; ++i) {
        cl.insert(i+1);
        //cl.printElements();
    }
    for (int i = 0; i < 20; ++i)
        cl.find(i+1);
    cl.printElements();
    cout << "numero de colisoes " << cl.getCollisionCounter() << endl;
    cout << "numero de comparacoes " << cl.numberOfComparsions << " numero de vezes " << cl.comparsionCounter;

    /*
    sortQuestions(listQuestions);

	vector<int> vetQuestionId = getVetQuestionIdAleatorios(listQuestions, 20);
	sortIntegers(vetQuestionId);
*/
	return 0;
}

void sortQuestions(vector<Question> &questionVector)
{
	cout << "### Ordenacao Questions ###" << endl;
	random_shuffle(questionVector.begin(), questionVector.end());

	cout << "Vetor Original:" << endl;
	printVector(questionVector);
	HeapSort::heapSort(questionVector);

	cout << "Vetor Ordenado:" << endl;
	printVector(questionVector);
}

void sortIntegers(vector<int> &intVector)
{
	cout << "### Ordenacao Inteiros ###" << endl;
	random_shuffle(intVector.begin(), intVector.end());

	cout << "Vetor Original:" << endl;
	printVector (intVector);
	HeapSort::heapSort(intVector);

	cout << "Vetor Ordenado:" << endl;
	printVector(intVector);
}

vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions,
		const int &n)
{
	vector<int> vetQuestionId;    // = new vector<int>;
	long seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 eng(seed);    ///mersenne twister engine
	uniform_int_distribution<unsigned long> distAleatoria(0,
			listQuestions.size() - 1);

	//srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < n; i++)
	{
		vetQuestionId.emplace_back(
				listQuestions[distAleatoria(eng)].getQuestionId());
		//vetQuestionId[i] = listQuestions->at(rand()%(listQuestions->size()-1))->getQuestionId();
	}

	return vetQuestionId;
}

template<class T> void printVector(const vector<T> &vector)
{
	for (const auto it : vector)
		cout << it << " ";
	cout << endl << endl;
}
