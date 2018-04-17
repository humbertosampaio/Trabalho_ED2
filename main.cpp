#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"
#include "Headers/HeapSort.h"
#include "Headers/CombSort.h"
#include "Headers/HashCoalesced.h"
#include "Headers/Cenario4.h"

#include "Source/QuickSort.cpp"
#include "Source/InsertionSort.cpp"
#include "Source/MergeSort.cpp"
#include "Source/HeapSort.cpp"
#include "Source/CombSort.cpp"

using namespace std;

void sortQuestions(vector<Question> &questionVector);
void sortIntegers(vector<int> &intVector);
vector<int> getVetQuestionsIdRand(vector<Question> &vetQuestions, const int &n);
vector<Question> getVetQuestionsRand(vector<Question> &vetQuestions, const int &n);
template<class T> void printVector(const vector<T> &vector);

struct Variables
{
		vector<Question> questionVec;
		vector<Answer> answerVec;
		vector<Tag> tagVec;
		vector<int> intVec;

		string sourceFileName;
		string questionPath;
		string answerPath;
		string tagPath;

		int N; // N será lido do arquivo "entrada.txt"
		int section;
		int cenary;
		int entry;
};

void openMenu(Variables vars);
void section1(Variables vars);
void section1_cenary1(Variables vars);
void section1_cenary1_entry1(Variables vars);
void section1_cenary1_entry2(Variables vars);
void section1_cenary2(Variables vars);
void section1_cenary3(Variables vars);
void section1_cenary4(Variables vars);
void section2(Variables vars);

int main(int argc, char** argv)
{
	Variables vars;
	vars.sourceFileName = argv[1];

//	string path = "../pythonquestions/OriginalFiles/Questions.csv";
//	FileUtils::readFileQuestion(path, listQuestions);
//	sortQuestions(listQuestions);
	openMenu(vars);

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

vector<int> getVetQuestionsIdRand(vector<Question> &vetQuestions, const int &n)
{
	vector<Question> vetQuestionsCopy(vetQuestions);
	vector<int> vetQuestionsAleatorio; /// Vector de questions gerados aleatoriamente
	long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 eng(seed);    ///mersenne twister engine
	uniform_int_distribution<unsigned long> distAleatoria(0, vetQuestions.size() - 1);

	for (int i = 0; i < n; i++)
	{
		unsigned int indice;
		do
		{
			indice = distAleatoria(eng);
		} while (vetQuestionsCopy[indice].getQuestionId() == -1);
		vetQuestionsAleatorio.emplace_back(vetQuestionsCopy[indice].getQuestionId());
		vetQuestionsCopy[indice].setQuestionId(-1);
	}
	return vetQuestionsAleatorio;
}

vector<Question> getVetQuestionsRand(vector<Question> &vetQuestions, const int &n)
{
	vector<Question> vetQuestionsCopy(vetQuestions);
	vector<Question> vetQuestionsAleatorio; /// Vector de questions gerados aleatoriamente
	long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 eng(seed);    ///mersenne twister engine
	uniform_int_distribution<unsigned long> distAleatoria(0, vetQuestions.size() - 1);

	for (int i = 0; i < n; i++)
	{
		unsigned int indice;
		do
		{
			indice = distAleatoria(eng);
		} while (vetQuestionsCopy[indice].getQuestionId() == -1);
		vetQuestionsAleatorio.emplace_back(vetQuestionsCopy[indice]);
		vetQuestionsCopy[indice].setQuestionId(-1);
	}
	return vetQuestionsAleatorio;
}

template<class T> void printVector(const vector<T> &vector)
{
	for (const auto it : vector)
		cout << it << " ";
	cout << endl << endl;
}

/// Menu
void openMenu(Variables vars)
{
	vars.N = 100;
	vars.answerPath = "";
	vars.answerVec.clear();
	vars.intVec.clear();
	vars.questionPath = "";
	vars.questionVec.clear();
	vars.tagPath = "";
	vars.tagVec.clear();

	cout << "Escolha a secao: " << endl;
	cout << "Secao 1: Analise dos Algoritmos" << endl;
	cout << "Secao 2: Implementacao das Tags Frequentes e dos Usuarios Ativos" << endl;
	cout << "0: Sair" << endl;

	cin >> vars.section;
	switch (vars.section)
	{
		case 0:
			exit(0);
		case 1: // Secao 1
			section1(vars);
			break;
		case 2: // Secao 2
			section2(vars);
			break;
	}
	char executarNovamente;
	cout << "Executar novamente? (S/N)" << endl;
	cin >> executarNovamente;
	executarNovamente == 'S' || executarNovamente == 's' ? openMenu(vars) : exit(0);
}

void section1(Variables vars)
{
	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	FileUtils::readFileQuestion(path, vars.questionVec);

	cout << "\tEscolha o cenario:" << endl;
	cout << "\tCenario 1: Impacto de diferentes estruturas de dados" << endl;
	cout << "\tCenario 2: Impacto de variações do Quicksort" << endl;
	cout << "\tCenario 3: Quicksort X InsertionSort X Mergesort X Heapsort X Meusort" << endl;
	cout << "\tCenario 4: Tratamento de Colisoes: Enderecamento X Encadeamento" << endl;
	cout << "\t0: Voltar" << endl;
	cout << "\t";

	cin >> vars.cenary;
	switch (vars.cenary)
	{
		case 0:
			openMenu(vars);
			break;
		case 1: // Secao 1, Cenario 1
			section1_cenary1(vars);
			break;
		case 2: // Secao 1, Cenario 2
			section1_cenary2(vars);
			break;
		case 3: // Secao 1, Cenario 3
			section1_cenary3(vars);
			break;
		case 4: // Secao 1, Cenario 4
			// Colar o Codigo do Edson
			break;
		default:
			cout << "Cenario Invalido. Tente novamente" << endl;
			section1(vars);
	}
}

void section1_cenary1(Variables vars)
{
	cout << "\t\tEscolha uma entrada:" << endl;
	cout << "\t\tEntrada 1: Elementos do tipo Inteiro" << endl;
	cout << "\t\tEntrada 2: Elementos do tipo Question" << endl;
	cout << "\t\t0: Voltar" << endl;
	cout << "\t\t";

	cin >> vars.entry;
	switch (vars.entry)
	{
		case 0:
			section1(vars);
			break;
		case 1: // Secao 1, Cenario 1, Entrada 1
			section1_cenary1_entry1(vars);
			break;
		case 2: // Secao 1, Cenario 1, Entrada 2
			section1_cenary1_entry2(vars);
			break;
		default:
			cout << "Entrada invalida. Tente novamente" << endl;
			section1_cenary1(vars);
	}
}

void section1_cenary1_entry1(Variables vars)
{
	vars.intVec.clear();
	vars.intVec = getVetQuestionsIdRand(vars.questionVec, vars.N);
	QuickSort::quickSort(vars.intVec, 0, vars.intVec.size() - 1);
	printVector(vars.intVec);
}

void section1_cenary1_entry2(Variables vars)
{
	QuickSort::quickSort(vars.questionVec, 0, vars.questionVec.size() - 1);
	printVector(vars.questionVec);
}

void section1_cenary2(Variables vars)
{
	cout << "\t\tEscolha uma entrada:" << endl;
	cout << "\t\tEntrada 1: QuickSort recursivo" << endl;
	cout << "\t\tEntrada 2: QuickSort Mediana(k)" << endl;
	cout << "\t\tEntrada 3: QuickSort insercao(m)" << endl;
	cout << "\t\t0: Voltar" << endl;
	cout << "\t\t";

	int entrada;
	cin >> entrada;
	int lastIndex = vars.intVec.size() - 1;

	switch (entrada)
	{
		case 0:
			section1(vars);
			break;
		case 1: // Secao 1, Cenario 2, Entrada 1
			QuickSort::quickSort(vars.intVec, 0, lastIndex);
			break;
		case 2: // Secao 1, Cenario 2, Entrada 2
			QuickSort::quickSortMediana(vars.intVec, 0, lastIndex, 5);
			break;
		case 3: // Secao 1, Cenario 2, Entrada 3
			QuickSort::quickSortInsercao(vars.intVec, 0, lastIndex, 5);
			break;
		default:
			cout << "Entrada Invalida. Tente novamente." << endl;
			section1_cenary2(vars);
	}
	printVector(vars.intVec);
}

void section1_cenary3(Variables vars)
{
	vars.intVec = getVetQuestionsIdRand(vars.questionVec, vars.N);
	vector<int> auxVec(vars.intVec);
	QuickSort::quickSort(auxVec, 0, auxVec.size() - 1);
	cout << "Ordenacao por Quick Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVec;
	vector<int> vecMergeSort(vars.intVec);
	MergeSort::mergeSort(auxVec);
	cout << "Ordenacao por Merge Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVec;
	vector<int> vecInsertionSort(vars.intVec);
	InsertionSort::insertionSort(auxVec);
	cout << "Ordenacao por Insertion Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVec;
	vector<int> vecHeapSort(vars.intVec);
	HeapSort::heapSort(auxVec);
	cout << "Ordenacao por Heap Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVec;
	vector<int> vecCombSort(vars.intVec);
	CombSort::combSort(auxVec);
	cout << "Ordenacao por Comb Sort" << endl;
	printVector(auxVec);
	auxVec.clear();
}

void section1_cenary4(Variables vars)
{

}

void section2(Variables vars)
{

}
