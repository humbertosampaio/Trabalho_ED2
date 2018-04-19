#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <fstream>

#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"
#include "Headers/HeapSort.h"
#include "Headers/CombSort.h"
#include "Headers/HashCoalesced.h"
#include "Headers/HashDouble.h"
#include "Headers/HashSeparated.h"
#include "Headers/HashSeparatedS.h"
#include "Headers/HashLinear.h"
#include "Headers/Vertex.h"


/**arquivos .cpp dos algoritmos de ordenação precisaram ser importados
 * na main.cpp, pois sao classes com metodos que usam template.
 */
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
	string path;
	string questionPath;
	string answerPath;
	string tagPath;

	vector<int> Ns;
	unsigned long N;
	int section;
	int cenary;
	int entry;

	void entryPath(string _path) {
		path = _path;
		if (path[path.size() - 1] != '\\' && path[path.size() - 1] != '/' && !path.empty())
			path.push_back('/');
		if(!path.empty())
            cout << "Path informado: " << path << endl;
		else
            cout << "Como nao foi informado a path, consideraremos o diretorio do executavel como path" << endl;
		questionPath = path + "pythonquestions/Questions.csv";
		answerPath = path + "pythonquestions/Answers.csv";
		tagPath = path + "pythonquestions/Tags.csv";
		sourceFileName = path + "entrada.txt";
	}
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
void section1_cenary2_entry1(Variables &vars);
void section1_cenary2_entry2(Variables &vars);
void section1_cenary2_entry3(Variables &vars);
void section1_cenary2_entry4(Variables &vars);
void section1_cenary2_entry5(Variables &vars);
void section2_1(Variables vars, unsigned int N, vector<Vertex>& sorteredTags);
void section2_2(Variables vars, unsigned int N, vector<Vertex>& sorteredUsers);

int main(int argc, char** argv)
{
	FileUtils::showTop();
	if (argc != 2 && argc != 1)
	{
        cout << "Erro na chamada do programa. Informe corretamente o path (caminho) padrao inicial." << endl;
        cout << "Ou deixe em branco, caso queira considerar o diretorio do executavel como path" << endl;
        cout << R"(Certifique-se de no path estar o arquivo "entrada.txt" e a pasta "pythonsquestions".)" << endl;
        cout << R"(Eh necessario que os arquivos "Answers.csv", "Questions.csv" e "Tags.csv" estao no diretorio "pythonsquestions".)" << endl;
        cout << "Formato a inserir na linha de comando para execucao do algoritmo:" << endl;
        cout << "<./executavel> <pathDoDiretorioInicial>" << endl;
        FileUtils::endProgram();
		return 0;
	}

	Variables vars;
	vars.entryPath(argc==1 ? "" : argv[1]);
	vars.Ns = FileUtils::readInputFile(vars.sourceFileName);
	vars.N = vars.Ns.size();
    FileUtils::clearFileContent("saida.txt");

	openMenu(vars);
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
    //long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
    random_device rd; // obtain a random number from hardware
    int seed = rd();
    std::mt19937 eng(seed); // seed the generator
    uniform_int_distribution<unsigned long> distAleatoria(0, vetQuestions.size() - 1);///distribuicao uniforme aleatoria

    vector<Question> vetQuestionsCopy(vetQuestions);
	vector<int> vetQuestionsAleatorio; /// Vector de questions gerados aleatoriamente


	for (int i = 0; i < n; i++)
	{
		unsigned int indice;
		do
		{
			indice = static_cast<unsigned int>(distAleatoria(eng));
		} while (vetQuestionsCopy[indice].getQuestionId() == -1);
		vetQuestionsAleatorio.emplace_back(vetQuestionsCopy[indice].getQuestionId());
		vetQuestionsCopy[indice].setQuestionId(-1);
	}
	FileUtils::writeToOutputFile("Seed: " + to_string(seed));
	return vetQuestionsAleatorio;
}

vector<Question> getVetQuestionsRand(vector<Question> &vetQuestions, const int &n)
{
    ///Gerador de numeros aleatorios (Nao sao previsiveis)
    random_device rd; // obtain a random number from hardware
    int seed = rd();
    std::mt19937 eng(seed); // seed the generator
    uniform_int_distribution<unsigned long> distAleatoria(0, vetQuestions.size() - 1);///distribuicao uniforme aleatoria

	vector<Question> vetQuestionsCopy(vetQuestions);
	vector<Question> vetQuestionsAleatorio; /// Vector de questions gerados aleatoriamente

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
    FileUtils::writeToOutputFile("Seed: " + to_string(seed));
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
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Escolha a secao: " << endl;
	cout << "Secao 1: Analise dos Algoritmos" << endl;
	cout << "Secao 2: Implementacao das Tags Frequentes e dos Usuarios Ativos" << endl;
	cout << "0: Sair" << endl;
	cout << "----------" << endl;
	cout << "Opcao: ";
    cin >> vars.section;
    cout << "-----------------------------------------------------------------------" << endl;
	switch (vars.section)
	{
		case 0:
        FileUtils::endProgram();
		case 1: /// Secao 1
			section1(vars);
			break;
		case 2: /// Secao 2
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
	while (executarNovamente != 'N' && executarNovamente != 'n' && executarNovamente != 'S' && executarNovamente != 's')
		cout << "Entrada invalida! Tente novamente:" << endl;
	executarNovamente == 'S' || executarNovamente == 's' ? openMenu(vars) : FileUtils::endProgram();
}

void section1(Variables &vars) {
	if(vars.questionVector.empty())
		FileUtils::readFileQuestion(vars.questionPath, vars.questionVector);
	do {
		cout << "\t---------------------------------------------------------------------------------" << endl;
		cout << "\tEscolha o cenario:" << endl;
		cout << "\tCenario 1: Impacto de diferentes estruturas de dados" << endl;
		cout << "\tCenario 2: Impacto de variacoes do Quicksort" << endl;
		cout << "\tCenario 3: QuickSort X InsertionSort X MergeSort X HeapSort X MeuSort(CombSort)" << endl;
		cout << "\tCenario 4: Tratamento de Colisoes: Enderecamento X Encadeamento" << endl;
		cout << "\t0: Voltar" << endl;
		cout << "\t----------" << endl;
		cout << "\tOpcao: ";
		cin >> vars.cenary;
		cout << "\t---------------------------------------------------------------------------------" << endl;
		switch (vars.cenary) {
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
	} while (vars.cenary >= 1 && vars.cenary <= 4);
}

void section1_cenary1(Variables &vars)
{
	cout << "\t\t----------------------------------------" << endl;
	cout << "\t\tEscolha uma entrada:" << endl;
	cout << "\t\tEntrada 1: Elementos do tipo Inteiro" << endl;
	cout << "\t\tEntrada 2: Elementos do tipo Question" << endl;
	cout << "\t\t0: Voltar" << endl;
	cout << "\t\t----------" << endl;
	cout << "\t\tOpcao: ";
	cin >> vars.entry;
	cout << "\t\t----------------------------------------" << endl;
	if(vars.entry == 1 ||vars.entry == 2)
    {
        FileUtils::writeToOutputFile("----------------------------------------------------");
        FileUtils::writeToOutputFile("Cenario 1: Impacto de diferentes estruturas de dados");
    }
	switch (vars.entry)
	{
		case 0:
			section1(vars);
			break;
		case 1: /// Secao 1, Cenario 1, Entrada 1
			section1_cenary1_entry1(vars);
			break;
		case 2: /// Secao 1, Cenario 1, Entrada 2
			section1_cenary1_entry2(vars);
			break;
		default:
			cout << "Entrada invalida. Tente novamente" << endl;
			section1_cenary1(vars);
	}
}

void section1_cenary1_entry1(Variables &vars)
{
    string str = "----------------------------------------------------";
    str += "\nQuick Sort Recursivo com vector de inteiros.";
    str += "\n----------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    vars.intVector.clear();
	for (int i = 0; i < vars.N; i++)
	{
	    str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
		FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 0);
        }
	}
}

void section1_cenary1_entry2(Variables &vars)
{
    string str = "----------------------------------------------------";
    str += "\nQuick Sort Recursivo com vector de Questions.";
    str += "\n----------------------------------------------------";
    FileUtils::writeToOutputFile(str);
	for (int i = 0; i < vars.N; i++)
	{
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vector<Question> tempVector;
            tempVector = getVetQuestionsRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(tempVector, 0);
        }
	}
}

void section1_cenary2(Variables &vars)
{
	cout << "\t\t----------------------------------------" << endl;
	cout << "\t\tEscolha uma entrada:" << endl;
	cout << "\t\tEntrada 1: QuickSort Recursivo" << endl;
	cout << "\t\tEntrada 2: QuickSort Mediana com K=3" << endl;
    cout << "\t\tEntrada 3: QuickSort Mediana com K=5" << endl;
	cout << "\t\tEntrada 4: QuickSort Insercao com M=10" << endl;
    cout << "\t\tEntrada 5: QuickSort Insercao com M=100" << endl;
	cout << "\t\t0: Voltar" << endl;
	cout << "\t\t----------" << endl;
	cout << "\t\tOpcao: ";
	int entrada;
	cin >> entrada;
	cout << "\t\t----------------------------------------" << endl;

	if(vars.entry >= 1 ||vars.entry <= 5)
    {
        FileUtils::writeToOutputFile("--------------------------------------------");
        FileUtils::writeToOutputFile("Cenario 2: Impacto de variacoes do Quicksort");
    }

    //unsigned long lastIndex = vars.intVector.size() - 1;

	switch (entrada) {
        case 0:
            section1(vars);
            break;
        case 1: /// Secao 1, Cenario 2, Entrada 1 -- Quick Sort Recursivo
            section1_cenary2_entry1(vars);
            break;
		case 2: /// Secao 1, Cenario 2, Entrada 2 -- Quick Sort Mediana K=3
            section1_cenary2_entry2(vars);
			break;
        case 3: /// Secao 1, Cenario 2, Entrada 2 -- Quick Sort Mediana K=5
            section1_cenary2_entry3(vars);
            break;
		case 4: /// Secao 1, Cenario 2, Entrada 3 -- Quick Sort Insercao M=10
            section1_cenary2_entry4(vars);
			break;
        case 5: /// Secao 1, Cenario 2, Entrada 3 -- Quick Sort Insercao M=100
            section1_cenary2_entry5(vars);
            break;
		default:
			cout << "Entrada Invalida. Tente novamente." << endl;
			section1_cenary2(vars);
	}
}

void section1_cenary2_entry1(Variables &vars)
{
    string str = "--------------------------------------------";
    str += "\nQuick Sort Recursivo";
    str += "\n--------------------------------------------";
    FileUtils::writeToOutputFile(str);
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 0);
        }
    }
}

void section1_cenary2_entry2(Variables &vars)
{
    string str = "--------------------------------------------";
    str += "\nQuick Sort Mediana com K=3";
    str += "\n--------------------------------------------";
    FileUtils::writeToOutputFile(str);
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 3);
        }
    }
}

void section1_cenary2_entry3(Variables &vars)
{
    string str = "--------------------------------------------";
    str += "\nQuick Sort Mediana com K=5";
    str += "\n--------------------------------------------";
    FileUtils::writeToOutputFile(str);
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 5);
        }
    }
}

void section1_cenary2_entry4(Variables &vars)
{
    string str = "--------------------------------------------";
    str += "\nQuick Sort Insercao com M=10";
    str += "\n--------------------------------------------";
    FileUtils::writeToOutputFile(str);
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 10);
        }
    }
}

void section1_cenary2_entry5(Variables &vars)
{
    string str = "--------------------------------------------";
    str += "\nQuick Sort Insercao com K=100";
    str += "\n--------------------------------------------";
    FileUtils::writeToOutputFile(str);
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 100);
        }
    }
}


void section1_cenary3(Variables &vars)
{
    string str = "\n-------------------------------------------------------------------------------";
    str += "\nCenario 3: QuickSort X InsertionSort X MergeSort X HeapSort X MeuSort(CombSort)";
    str += "\n-------------------------------------------------------------------------------";
    str += "\nOrdenacao por Quick Sort Recursivo (melhor variacao)";
    str += "\n-------------------------------------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    cout << str;
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            QuickSort::quickSort(vars.intVector, 0);
        }
    }


    str = "\n-------------------------------------------------------------------------------";
    str += "\nOrdenacao por Insertion Sort";
    str += "\n-------------------------------------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    cout << str;
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            InsertionSort::insertionSort(vars.intVector);
        }
    }


    str = "\n-------------------------------------------------------------------------------";
    str += "\nOrdenacao por Merge Sort";
    str += "\n-------------------------------------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    cout << str;
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            MergeSort::mergeSort(vars.intVector);
        }
    }


    str = "\n-------------------------------------------------------------------------------";
    str += "\nOrdenacao por Heap Sort";
    str += "\n-------------------------------------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    cout << str;
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            HeapSort::heapSort(vars.intVector);
        }
    }


    str = "\n-------------------------------------------------------------------------------";
    str += "\nOrdenacao por Comb Sort (outro Sort escolhido pelo grupo)";
    str += "\n-------------------------------------------------------------------------------";
    FileUtils::writeToOutputFile(str);
    cout << str;
    for (int i = 0; i < vars.N; i++)
    {
        str = "\nExperimento " + to_string(i+1) + ": N = " + to_string(vars.Ns[i]);
        FileUtils::writeToOutputFile(str);
        cout << str << endl;
        for(int j = 1; j <= 5; j++)
        {
            str = "Iteracao " + to_string(j);
            FileUtils::writeToOutputFile(str);
            cout << str << endl;
            vars.intVector.clear();
            vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
            CombSort::combSort(vars.intVector);
        }
    }

	FileUtils::pauseScreen(true);
}

void section1_cenary4(Variables &vars)
{
	for (int i = 0; i < vars.N; i++)
	{
		vars.intVector = getVetQuestionsIdRand(vars.questionVector, vars.Ns[i]);
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
				hashName = "Encadeamento Coalescido (sem porao)";
				break;
			case 2:
				hash = new HashLinear(n, false);
				hashName = "Enderecamento - Sondagem Linear";
				break;
			case 3:
				hash = new HashLinear(n, true);
				hashName = "Enderecamento - Sondagem Quadratica";
				break;
			case 4:
				hash = new HashDouble(n);
				hashName = "Enderecamento - Duplo Hash";
				break;
			default: break;
		}

		for (vector<int>::iterator it = vars.intVector.begin(); it != vars.intVector.end(); ++it)
			hash->insert(*it);

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

void section2 (Variables& vars)
{
    if(vars.questionPath.empty())
        FileUtils::readFileQuestion(vars.questionPath, vars.questionVector);
    if(vars.tagPath.empty())
        FileUtils::readFileTag(vars.tagPath, vars.tagVector);
    if(vars.answerPath.empty())
        FileUtils::readFileAnswer(vars.answerPath, vars.answerVector);
    int N;
    cout << "Digite um numero de Questions desejados na leitura: " << endl;
    cin >> N;
    while (N < 0) {
        cout << "Numero de questions invalido! digite novamente:" << endl;
        cin >> N;
    }
    vector<Vertex> sorteredTags;
    section2_1(vars, N, sorteredTags);
    vector<Vertex> sorteredUsers;
    section2_2(vars, N, sorteredUsers);

    cout << "Digite um numero de Tags e UserIDs mais frequentes:" << endl;
    cin >> N;
    while (N < 0) {
        cout << "Parametro invalido! digite novamente:" << endl;
        cin >> N;
    }
    ofstream saida;
    saida.open("saida.txt");
    string s = "################# SECAO 2-TAGS E USUARIOS FREQUENTES #################\n";
    saida << s;
    saida << setw(12)<< "frequencia" << setw(12) << "Tags\n";
    for (int i = 0; i < N && i < sorteredTags.size(); ++i)
        saida << left << setw(12) << sorteredTags.at(i).frequence << setw(25) << sorteredTags.at(i).valueStr << endl;
    saida << "\n\n\n";
    saida << setw(12)<< "frequencia" << setw(12) << "UserIDs\n";
    for (int i = 0; i < N && i < sorteredUsers.size(); ++i) {
        saida << left << setw(12)<< sorteredUsers.at(i).frequence << setw(12) << sorteredUsers.at(i).value << endl;
    }
    cout << setiosflags;
}

void section2_1(Variables vars, unsigned int N, vector<Vertex>& sorteredTags)
{
	vars.intVector.clear();
	vars.intVector = getVetQuestionsIdRand(vars.questionVector, N);
    QuickSort::quickSort(vars.intVector, 3);
    HashSeparatedS hashTag ((unsigned int)ceil(0.1*N));
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

void section2_2 (Variables vars, unsigned int N, vector<Vertex>& sorteredUsers)
{
	vars.intVector.clear();
	vars.intVector = getVetQuestionsIdRand(vars.questionVector, N);
	QuickSort::quickSort(vars.intVector, 3);
	HashSeparated hashAnswer ((unsigned int)ceil(0.1*N), true);

	QuickSort::quickSort(vars.answerVector, 0);
    QuickSort::quickSort(vars.questionVector, 0);
	vector<Answer>::iterator itAnswer = vars.answerVector.begin();
    vector<Question>::iterator itQuestion = vars.questionVector.begin();

	for (int &it : vars.intVector) {
		if (it == -1) continue;
		for (; (*itAnswer).getQuestionId() < it; ++itAnswer);
        for (; (*itQuestion).getQuestionId() < it; ++itQuestion);
		if ((*itAnswer).getQuestionId() == it && (*itAnswer).getUserId() != -1)
				hashAnswer.insert((*itAnswer).getUserId());
        if ((*itQuestion).getQuestionId() == it && (*itQuestion).getUserId() != -1)
            hashAnswer.insert((*itQuestion).getUserId());
	}
	hashAnswer.insertElementsVector(sorteredUsers);
	QuickSort::quickSort(sorteredUsers, 0);
}