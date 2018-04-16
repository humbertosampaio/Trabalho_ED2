#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"
#include "Headers/HeapSort.h"
#include "Headers/HashCoalesced.h"
#include "Headers/Cenario4.h"
#include "Headers/CombSort.h"

#include "Source/InsertionSort.cpp"
#include "Source/MergeSort.cpp"
#include "Source/HeapSort.cpp"
#include "Source/CombSort.cpp"

using namespace std;

void sortQuestions(vector<Question> &questionVector);
void sortIntegers(vector<int> &intVector);
vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n);
template<class T> void printVector(const vector<T> &vector);
void openMenu();

int main(int argc, char** argv)
{
	string sourceFileName = argv[1];
	vector<Question> listQuestions;

	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	FileUtils::readFileQuestion(path, listQuestions);
	sortQuestions(listQuestions);
//	openMenu();

	//string path = "/home/edson/pythonquestions/Questions.csv"; //edson
	//string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";

//
//	vector<int> vetQuestionId = getVetQuestionIdAleatorios(listQuestions, 20);
//	sortIntegers(vetQuestionId);

	//string path = "/home/edson/pythonquestions/Questions.csv"; //edson
	//string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";
	//string path = "../pythonquestions/OriginalFiles/Questions.csv";

	//FileUtils::readFileQuestion(path, listQuestions);

	HashCoalesced cl(20);

	for (int i = 0; i < 20; ++i)
	{
		cl.insert(i + 1);
		//cl.printElements();
	}
	for (int i = 0; i < 20; ++i)
		cl.find(i + 1);
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
	CombSort::combSort(questionVector);

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
	cout << "\tCenario 1: Impacto de diferentes estruturas de dados" << endl;
	cout << "\tCenario 2: Impacto de variações do Quicksort" << endl;
	cout << "\tCenario 3: Quicksort X InsertionSort X Mergesort X Heapsort X Meusort" << endl;
	cout << "\tCenario 4: Tratamento de Colisoes: Enderecamento X Encadeamento" << endl;
}

void printEntries_Cenary1_Section1()
{
	cout << "\t\tEntrada 1: Elementos do tipo Inteiro" << endl;
	cout << "\t\tEntrada 2: Elementos do tipo Question" << endl;
}

void printEntries_Cenary2_Section1()
{
	cout << "\t\tEntrada 1: QuickSort recursivo" << endl;
	cout << "\t\tEntrada 2: QuickSort Mediana(k)" << endl;
	cout << "\t\tEntrada 3: QuickSort insercao(m)" << endl;
}

void openMenu()
{
	int secao, cenario, entrada, N = 10; // N será lido do arquivo "entrada.txt"
	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	vector<int> intVec;
	vector<Question> questionVec;

	vector<int> vecQuickSort(intVec);
	vector<int> vecInsertionSort(intVec);
	vector<int> vecMergeSort(intVec);
	vector<int> vecHeapSort(intVec);
	vector<int> vecMeuSort(intVec);

	printSections();
	cin >> secao;
	switch (secao)
	{
		case 1: // Secao 1
			FileUtils::readFileQuestion(path, questionVec);

			printCenaries_Section1();
			cin >> cenario;
			switch (cenario)
			{
				case 1: // Secao 1, Cenario 1
					printEntries_Cenary1_Section1();
					cin >> entrada;
					switch (entrada)
					{
						case 1: // Secao 1, Cenario 1, Entrada 1
							intVec = getVetQuestionIdAleatorios(questionVec, N);
							// Chamar QuickSort para inteiros
							break;
						case 2: // Secao 1, Cenario 1, Entrada 2
							cout << endl;
							// Chamar QuickSort para Questions
							break;
						default:
							cout << "Entrada invalida." << endl;
					}
					break;
				case 2: // Secao 1, Cenario 2
					printEntries_Cenary2_Section1();
					cin >> entrada;

					intVec = getVetQuestionIdAleatorios(questionVec, N);

					switch (entrada)
					{
						case 1: // Secao 1, Cenario 2, Entrada 1
							// Chamar QuickSort recursivo
							break;
						case 2: // Secao 1, Cenario 2, Entrada 2
							// Chamar QuickSort Mediana(k)
							break;
						case 3: // Secao 1, Cenario 2, Entrada 3
							// Chamar QuickSort Insercao(m)
							break;
						default:
							cout << "Entrada Invalida." << endl;
					}
					break;
				case 3: // Secao 1, Cenario 3
					intVec = getVetQuestionIdAleatorios(questionVec, N);

					// Chamar QuickSort
					MergeSort::mergeSort(vecMergeSort, 0, vecMergeSort.size() - 1);
					InsertionSort::insertionSort(vecInsertionSort);
					HeapSort::heapSort(vecHeapSort);
					// Chamar MeuSort
					break;
				case 4: // Secao 1, Cenario 4
					// Colar o Codigo do Edson
					break;
				default:
					cout << "Cenario Invalido." << endl;
			}
			break;
		case 2: // Secao 2

			break;

	}
}
