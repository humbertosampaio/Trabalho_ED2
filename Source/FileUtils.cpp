//
// Created by edson on 28/03/18.
//

#include "../Headers/FileUtils.h"
#include <string>

void FileUtils::clearFileContent(string path)
{
	ofstream writer(path, std::ofstream::out | std::ofstream::trunc);
	if (writer.is_open())
		writer.clear();
	else
		cout << "Falha ao limpar o conteudo do arquivo \"" << path << "\"." << endl;
}

void FileUtils::readFileQuestion(string path, vector<Question> &questionList)
{
	fstream file;
	file.open(path.c_str());

	if (file.is_open())
	{
	    cout << "Lendo arquivo de registros Questions.csv" << endl;
	    cout << "Path (caminho): " << path << endl;
		//variavel para calcular tempo de execucao
		clock_t tStart = clock();

		//lendo o arquivo em blocos de 4MB
		unsigned int length = 4 * 1024 * 1024;

		//criando e inicializando buffer
		char *buffer = new char[length];
		file.read(buffer, length);

		//variaveis auxiliares
		string tempString;
		string *obj = new string[6];
		int objPosition = 0;
		int quotationMarksCount = 0;
		long registriesCount = 0;
		int i = 0;

		//ignorando cabecalho
		for (; buffer[i] != '\n'; ++i)
			;

		//iteracao principal
		while (!file.eof())
		{
			while (++i < length && buffer[i] != char_traits<char>::eof())
			{
				if (buffer[i] != ',' && buffer[i] != '\n')
				{
					if (buffer[i] == '"')
						quotationMarksCount++;
					tempString.push_back(buffer[i]);
				}
				else if (quotationMarksCount % 2 == 0)
				{
					obj[objPosition] = tempString;
					tempString.clear();
					++objPosition;
				}
				if (objPosition > 5)
				{
					questionList.emplace_back(obj);
					registriesCount++;

					if (registriesCount % 50000 == 0)
						cout << "Registros lidos: " << registriesCount << "\r" << std::flush;

					objPosition = 0;
					quotationMarksCount = 0;
					delete[] obj;
					obj = new string[6];

					/*if (registriesCount > 10000)
						break;*/
				}
			}
			file.read(buffer, length);
			i = -1;

			/*if (registriesCount > 10000)
				break;*/
		}
		cout << endl;
		cout << "Quantidade de registros lidos: " << registriesCount << endl;
		cout << "Tempo gasto na leitura: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;
		file.close();
		delete[] buffer;
		delete[] obj;
		return;
	}
	cout << "falha na leitura do arquivo!" << endl;
}

void FileUtils::readFileTag(string path, vector<Tag> &tagList)
{
	fstream file;
	file.open(path.c_str());

	if (file.is_open())
	{
		string tag;
		int questionId;
		int atualId;
		file >> tag;
		file >> questionId >> tag;
		tag.erase(0, 1);
		atualId = questionId;
		list<string> atualList;
		atualList.push_back(tag);
		int i = 0;
		while (file >> questionId >> tag)
		{
			//apaga a virgua da string
			tag.erase(0, 1);
			if (atualId != questionId) {
				tagList.emplace_back(atualId, atualList);
				atualList.clear();
			}
			atualList.push_back(tag);
			atualId = questionId;
			//if (++i > 16)
			//	break;
		}
		tagList.emplace_back(atualId, atualList);
		return;
	}
	cout << "falha na leitura do arquivo!" << endl;
}

void FileUtils::readFileAnswer(string path, vector<Answer> &answerList)
{
	fstream file;
	file.open(path.c_str());

	if (file.is_open())
	{
		//variavel para calcular tempo de execucao
		clock_t tStart = clock();

		//lendo o arquivo em blocos de 4MB
		unsigned int length = 4 * 1024 * 1024;

		//criando e inicializando buffer
		char *buffer = new char[length];
		file.read(buffer, length);

		//variaveis auxiliares
		string tempString;
		string *obj = new string[6];
		int objPosition = 0;
		int quotationMarksCount = 0;
		long registriesCount = 0;
		int i = 0;

		//ignorando cabecalho
		for (; buffer[i] != '\n'; ++i)
			;

		//iteracao principal
		while (!file.eof())
		{
			while (++i < length && buffer[i] != char_traits<char>::eof())
			{
				if (buffer[i] != ',' && buffer[i] != '\n')
				{
					if (buffer[i] == '"')
						quotationMarksCount++;
					tempString.push_back(buffer[i]);
				}
				else if (quotationMarksCount % 2 == 0)
				{
					obj[objPosition] = tempString;
					tempString.clear();
					++objPosition;
				}
				if (objPosition > 5)
				{
					answerList.emplace_back(obj);
					registriesCount++;

					if (registriesCount % 50000 == 0)
						cout << "Registros lidos: " << registriesCount << endl;

					objPosition = 0;
					quotationMarksCount = 0;
					delete[] obj;
					obj = new string[6];

					//if (registriesCount > 50)
					  //  break;
				}
			}
			file.read(buffer, length);
			i = -1;

			//if (registriesCount > 50)
			  //  break;
		}
		cout << "Quantidade de registros lidos: " << registriesCount << endl;
		cout << "Tempo gasto na leitura: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;
		file.close();
		delete[] buffer;
		delete[] obj;
		return;
	}
	cout << "falha na leitura do arquivo!" << endl;
}

vector<int> FileUtils::readInputFile(string path)
{
	ifstream reader(path, std::ifstream::in);
	vector<int> vector;
	if (reader.is_open())
	{
		int line, n, i = 0;
		reader >> n;
		while (reader >> line)
		{
			vector.push_back(line);
			i++;
		}

		if (n != i)
		{
			cout << "ERRO! Tente novamente!" << endl;
			cout << "Arquivo de entrada fora do padrao!" << endl;
			cout << "O numero fornecido na primeira linha do arquivo nao reflete a quantidade de N's." << endl;
			FileUtils::endProgram();
		}
	}
	else
	{
		cout << "ERRO! Tente novamente!" << endl;
		cout << "Desculpe, mas aconteceu algo inesperado." << endl;
		cout << "Verifique se o arquivo entrada.txt esta no diretorio indicado na execucao" << endl;
		cout << "O caminho tentado foi: \"" << path << "\"." << endl;
		cout << "VERIFIQUE tambem se digitou o nome do diretorio path corretamente." << endl;
		cout << "O numero fornecido na primeira linha do arquivo nao reflete a quantidade de N's." << endl;
		cout << "Obs: o arquivo \"entrada.txt\" precisa estar no path informado na execucao do programa." << endl;
	}
	return vector;
}

void FileUtils::writeToOutputFile(string text)
{
	string outputFileName = "saida.txt";
	ofstream writer(outputFileName, ios::app);
	if (writer.is_open())
	{
		writer << text << endl;
		writer.close();
	}
	else
		cout << "Falha ao escrever no arquivo \"" << outputFileName << "\"." << endl;
}


void FileUtils::endProgram()
{

	cout << "\n\n         --             FIM DO PROGRAMA            --" << endl;
	cout << "           Os resultados dos testes foram salvos no" << endl;
	cout << "        arquivo \"saida.txt\" dentro do path informado." << endl;
	cout << "\n----------------------- ALGORITMO FINALIZADO -------------------" << endl;
	FileUtils::pauseScreen(false);
	exit(-1);
}

void FileUtils::pauseScreen(bool continuar)
{
	int c;

	cout << endl << "Pressione <Enter> para " << (continuar ? "continuar" : "fechar");
	cout << " o algoritmo...." << endl;
	clearerr(stdin);
	while ((c = getchar()) != '\n' && c != EOF);//getchar();
}

void FileUtils::showTop()
{
    cout << "   --------------------------------------------" << endl;
    cout << "   -  -  Trabalho de Estrutura de Dados 2  -  -" << endl;
    cout << "   --------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "---------       ---   GRUPO 5   ---    -----------" << endl;
    cout << "---------          -> AUTORES <-         ---------" << endl;
    cout << "--------            Edson Lopes        -----------" << endl;
    cout << "--------         Humberto Sampaio          -------" << endl;
    cout << "------------       Luis Henrique     -------------" << endl;
    cout << "----------       Vinicius Oliveira      ----------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl << endl;
    //cout << "Tecle <Enter> para continuar o algoritmo...." << endl;
    //getchar();
    pauseScreen(true);
}