//
// Created by edson on 28/03/18.
//

#include "../Headers/FileUtils.h"

void FileUtils::readFileQuestion(string path, vector<Question> &questionList)
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
				} else if (quotationMarksCount % 2 == 0)
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
						cout << "Registros lidos: " << registriesCount << endl;

					objPosition = 0;
					quotationMarksCount = 0;
					delete[] obj;
					obj = new string[6];

					if (registriesCount > 100)
						break;
				}
			}
			file.read(buffer, length);
			i = -1;

			if (registriesCount > 100)
				break;
		}
		cout << "Quantidade de registros lidos: " << registriesCount << endl;
		cout << "Tempo gasto na leitura: " << (double) (clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;
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
		file >> tag >> tag;
        file >> questionId >> tag;
        atualId = questionId;
        list<string> atualList;
        atualList.push_back(tag);
        int i = 0;
		while (file >> questionId >> tag)
		{
			tag.erase(0, 1);
            if (atualId != questionId) {
                tagList.emplace_back(atualId, atualList);
                atualList.clear();
            }
            atualList.push_back(tag);
            atualId = questionId;
            //cout <<atualId << endl;
		}
        for (vector<Tag>::iterator it = tagList.begin(); it != tagList.end(); ++it)
            (*it).printTags();
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
                } else if (quotationMarksCount % 2 == 0)
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
        cout << "Tempo gasto na leitura: " << (double) (clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;
        file.close();
        delete[] buffer;
        delete[] obj;
        return;
    }
    cout << "falha na leitura do arquivo!" << endl;
}

void FileUtils::writeToOutputFile(string text)
{
	ofstream writer;
	writer.open("saida.txt");
	writer << text;
}
