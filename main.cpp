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
#include "Headers/HashLinear.h"
#include "Headers/HashDouble.h"
#include "Headers/HashSeparated.h"
#include "Headers/HashSeparatedS.h"
#include "Headers/Vertex.h"

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
	vector<Question> questionVector;
	vector<Answer> answerVector;
	vector<Tag> tagVector;
	vector<int> intVector;

	string sourceFileName;
	string questionPath;
	string answerPath;
	string tagPath;

	vector<int> Ns;
	int N;
	int section;
	int cenary;
	int entry;
};

void openMenu(Variables &vars);
void section1(Variables &vars);
void section1_cenary1(Variables &vars);
void section1_cenary1_entry1(Variables &vars);
void section1_cenary1_entry2(Variables &vars);
void section1_cenary2(Variables &vars);
void section1_cenary3(Variables &vars);
void section1_cenary4(Variables &vars);
void section1_cenary4_hashComparison(Variables &vars);
void section2(Variables &vars);
void section2_1(Variables vars, unsigned int N, vector<Vertex>& sorteredTags);
void section2_2(Variables vars, unsigned int N, vector<Vertex>& sorteredUsers);

int main(int argc, char** argv)
{
	if (argv[1] == nullptr)
	{
		cout << "Erro. Insira um arquivo de entrada como parametro da aplicacao." << endl;
		system("pause");
		return 0;
	}

	const string sourceFileName = argv[1];
	Variables vars;
	vars.sourceFileName = sourceFileName;

	openMenu(vars);

	system("pause");
	return 0;
}

void sortQuestions(vector<Question> &questionVector)
{
	cout << "### Ordenacao Questions ###" << endl;
	random_shuffle(questionVector.begin(), questionVector.end());

	cout << "Vetor Original:" << endl;
	printVector(questionVector);
	InsertionSort::insertionSort(questionVector);

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

void openMenu(Variables &vars)
{
	vars.Ns = FileUtils::readInputFile(vars.sourceFileName);
	vars.N = vars.Ns.size();
	vars.questionPath = "";
	vars.answerPath = "";
	vars.tagPath = "";
	vars.answerVector.clear();
	vars.intVector.clear();
	vars.questionVector.clear();
	vars.tagVector.clear();
	FileUtils::clearFileContent("saida.txt");

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
			int param;
			section2(vars);
			break;
		default:
			cout << "Opcao invalida. Tente novamente:" << endl;
			openMenu(vars);
	}
	char executarNovamente;
	cout << "Executar novamente? (S/N)" << endl;
	cin >> executarNovamente;
	executarNovamente == 'S' || executarNovamente == 's' ? openMenu(vars) : exit(0);
}

void section1(Variables &vars)
{
	string path = "../pythonquestions/OriginalFiles/Questions.csv";
	cout << "NAO ESQUECER DE COLOCAR O CIN AQUI PRO USUARIO DIGITAR O PATH DO ARQUIVO QUESTIONS!!!" << endl;
	FileUtils::readFileQuestion(path, vars.questionVector);

	cout << "\tEscolha o cenario:" << endl;
	cout << "\tCenario 1: Impacto de diferentes estruturas de dados" << endl;
	cout << "\tCenario 2: Impacto de variacoes do Quicksort" << endl;
	cout << "\tCenario 3: QuickSort X InsertionSort X MergeSort X HeapSort X MeuSort(CombSort)" << endl;
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
			section1_cenary4(vars);
			break;
		default:
			cout << "Cenario Invalido. Tente novamente" << endl;
			section1(vars);
	}
}

void section1_cenary1(Variables &vars)
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

void section1_cenary1_entry1(Variables &vars)
{
	string s = "";
	vars.intVector.clear();
	for (int i = 0; i < vars.N; i++)
	{
		vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
		s += "Iteracao " + to_string(i + 1) + ": \n";
		FileUtils::writeToOutputFile(s);
		QuickSort::quickSort(vars.intVector, 0);
		//printVector(vars.intVector);
	}
}

void section1_cenary1_entry2(Variables &vars)
{
	vector<Question> tempVector;
	string s = "";
	for (int i = 0; i < vars.N; i++)
	{
		getVetQuestionsRand(tempVector, vars.Ns[i]);
		s += "Iteracao " + to_string(i + 1) + ": \n";
		FileUtils::writeToOutputFile(s);
		QuickSort::quickSort(tempVector, 0);
		//printVector(vars.questionVector);
	}
}

void section1_cenary2(Variables &vars)
{
	cout << "\t\tEscolha uma entrada:" << endl;
	cout << "\t\tEntrada 1: QuickSort Recursivo" << endl;
	cout << "\t\tEntrada 2: QuickSort Mediana(k)" << endl;
	cout << "\t\tEntrada 3: QuickSort Insercao(m)" << endl;
	cout << "\t\t0: Voltar" << endl;
	cout << "\t\t";

	int entrada;
	cin >> entrada;
	int lastIndex = vars.intVector.size() - 1;

	switch (entrada)
	{
		case 0:
			section1(vars);
			break;
		case 1: // Secao 1, Cenario 2, Entrada 1 -- Quick Sort Recursivo
			QuickSort::quickSort(vars.intVector, 0);
			break;
		case 2: // Secao 1, Cenario 2, Entrada 2 -- Quick Sort Mediana
			QuickSort::quickSort(vars.intVector, 5);
			break;
		case 3: // Secao 1, Cenario 2, Entrada 3 -- Quick Sort Insercao
			QuickSort::quickSort(vars.intVector, 100);
			break;
		default:
			cout << "Entrada Invalida. Tente novamente." << endl;
			section1_cenary2(vars);
	}
	printVector(vars.intVector);
}

void section1_cenary3(Variables &vars)
{
	vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.N);
	vector<int> auxVec(vars.intVector);
	QuickSort::quickSort(auxVec, 0);
	cout << "Ordenacao por Quick Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVector;
	vector<int> vecMergeSort(vars.intVector);
	MergeSort::mergeSort(auxVec);
	cout << "Ordenacao por Merge Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVector;
	vector<int> vecInsertionSort(vars.intVector);
	InsertionSort::insertionSort(auxVec);
	cout << "Ordenacao por Insertion Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVector;
	vector<int> vecHeapSort(vars.intVector);
	HeapSort::heapSort(auxVec);
	cout << "Ordenacao por Heap Sort" << endl;
	printVector(auxVec);
	auxVec.clear();

	auxVec = vars.intVector;
	vector<int> vecCombSort(vars.intVector);
	CombSort::combSort(auxVec);
	cout << "Ordenacao por Comb Sort" << endl;
	printVector(auxVec);
	auxVec.clear();
}

void section1_cenary4(Variables &vars)
{
	for (int i = 0; i < vars.N; i++)
	{
		getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
		section1_cenary4_hashComparison(vars);
	}
}

void section1_cenary4_hashComparison(Variables &vars)
{
	unsigned int n = vars.intVector.size();
	int memorySpend = 0;
	int averageComparison = 0;
	string hashName;
	Hash* hash = nullptr;

	for (int i = 0; i < 5; ++i) {
		switch (i)
		{
			case 0: 
				hash = new HashSeparated(n, false);
				hashName = "Encadeamento Separado"; 
				break;
			case 1: 
				hash = new HashCoalesced(n);
				hashName = "Encadeamento Coalescido (sem porão)";
				break;
			case 2: 
				hash = new HashLinear(n, false);
				hashName = "Endereçamento – Sondagem Linear";
				break;
			case 3: 
				hash = new HashLinear(n, true);
				hashName = "Endereçamento – Sondagem Quadrática";
				break;
			case 4: 
				hash = new HashDouble(n);
				hashName = "Endereçamento – Duplo Hash";
				break;
			default: break;
		}
		for (vector<int>::iterator it = vars.intVector.begin(); it != vars.intVector.end(); ++it) {
			hash->insert(*it);
		}
		for (vector<int>::iterator it = vars.intVector.begin(); it != vars.intVector.end(); ++it)
			hash->find(*it);

		averageComparison += hash->getAvergareComparsions() / 5;
		if (memorySpend == 0)
			memorySpend = hash->getMemorySpend();

		string s = hashName + "\t" + to_string(hash->getAvergareComparsions()) +
			"\t" + to_string(hash->getMemorySpend());
		FileUtils::writeToOutputFile(s);
		delete hash;
	}
}

void section2(Variables &vars)
{
	FileUtils::readFileQuestion("/home/edson/pythonquestions/Questions.csv", vars.questionVector);
	FileUtils::readFileTag("/home/edson/pythonquestions/Tags.csv", vars.tagVector);
	//FileUtils::readFileAnswer("/home/edson/pythonquestions/Answers.csv", vars.answerVector);
	int param;
	cout << "Digite o numero(positivo) de Questions desejados na leitura" << endl;
	cin >> param;
	while (param < 0) {
		cout << "Numero de questions invalido! digite novamente" << endl;
		cin >> param;
	}
	vector<Vertex> sorteredTags;
	section2_1(vars, param, sorteredTags);
	for (int i = 0; i < 10; ++i)
		cout << sorteredTags.at(i).valueStr << " " << sorteredTags.at(i).frequence << endl;
}

void section2_1(Variables vars, unsigned int N, vector<Vertex>& sorteredTags)
{
	vars.intVector.clear();
	vars.intVector = getVetQuestionsIdRand(vars.questionVector, N);
	QuickSort::quickSort(vars.intVector, 3);
	HashSeparatedS hashTag((unsigned int)ceil(0.1*N));
	vector<Tag>::iterator itTag = vars.tagVector.begin();
	for (int &it : vars.intVector) {
		for (; (*itTag).getQuestionId() < it; ++itTag);
		if ((*itTag).getQuestionId() == it)
			for (auto &itStr : (*itTag).getTagList())
				hashTag.insert(itStr);
	}
	hashTag.insertElementsVector(sorteredTags);
	QuickSort::quickSort(sorteredTags, 0);
}

void section2_2(Variables vars, unsigned int N, vector<Vertex>& sorteredUsers)
{
	vars.intVector.clear();
	vars.intVector = getVetQuestionsIdRand(vars.questionVector, N);
	QuickSort::quickSort(vars.intVector, 3);
	HashSeparated hashAnswer((unsigned int)ceil(0.1*N), true);
	QuickSort::quickSort(vars.answerVector, 3);
	vector<Answer>::iterator itAnswer = vars.answerVector.begin();

	for (int &it : vars.intVector) {
		if (it == -1) continue;
		for (; (*itAnswer).getQuestionId() < it; ++itAnswer);
		if ((*itAnswer).getQuestionId() == it)
			hashAnswer.insert((*itAnswer).getUserId());
	}
	hashAnswer.insertElementsVector(sorteredUsers);
	QuickSort::quickSort(sorteredUsers, 0);
}