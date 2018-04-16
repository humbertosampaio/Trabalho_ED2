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

using namespace std;

void sortQuestions(vector<Question> &questionVector);
void sortIntegers(vector<int> &intVector);
vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n);
template<class T> void printVector(const vector<T> &vector);
template<class T> void openMenu(vector<T> &vector);

int main(int argc, char** argv)
{
	string sourceFileName = argv[1];
	vector<Question> listQuestions;

	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	FileUtils::readFileQuestion(path, listQuestions);
	sortQuestions(listQuestions);
//	openMenu(listQuestions);

	//string path = "/home/edson/pythonquestions/Questions.csv"; //edson
	//string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";

//
//	vector<int> vetQuestionId = getVetQuestionIdAleatorios(listQuestions, 20);
//	sortIntegers(vetQuestionId);

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
	printVector(intVector);
	HeapSort::heapSort(intVector);

	cout << "Vetor Ordenado:" << endl;
	printVector(intVector);
}

vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n)
{
	vector<int> vetQuestionId;    // = new vector<int>;
	long seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 eng(seed);    ///mersenne twister engine
	uniform_int_distribution<unsigned long> distAleatoria(0, listQuestions.size() - 1);

	//srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < n; i++)
	{
		vetQuestionId.emplace_back(listQuestions[distAleatoria(eng)].getQuestionId());
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

void printSections()
{
	cout << "Escolha a secao: " << endl;
	cout << "Secao 1: Analise dos Algoritmos" << endl;
	cout << "Secao 2: Implementacao das Tags Frequentes e dos Usuarios Ativos" << endl;
}

void printCenaries_Section1()
{
	cout << "\tCenario 1: Elementos do tipo Inteiro" << endl;
	cout << "\tCenario 2: Elementos do tipo Question" << endl;
}

template<class T> void openMenu(vector<T> &vector)
{
	int secao, cenario, N = 10; // N será lido do arquivo "entrada.txt"
	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	printSections();
	cin >> secao;
	switch (secao)
	{
		case 1:
			printCenaries_Section1();
			cin >> cenario;
			switch (cenario)
			{
				case 1:
					getVetQuestionIdAleatorios(vector, N);
					// Chamar QuickSort para inteiros
					break;
				case 2:
					vector = FileUtils::readFileQuestion(path, vector);
			}

	}
}


