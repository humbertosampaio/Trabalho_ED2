//
// Created by edson on 28/03/18.
//

#include "../Headers/FileUtils.h"

void FileUtils::readFileQuestion(string path, vector<Question> &questionList)
{
    fstream file;
    file.open(path.c_str());

    if (file.is_open()) {
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
        for (; buffer[i] != '\n'; ++i);

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
                } else if (quotationMarksCount % 2 == 0) {
                    obj[objPosition] = tempString;
                    tempString.clear();
                    ++objPosition;
                }
                if (objPosition > 5) {
                    questionList.emplace_back(obj);
                    registriesCount++;

                    if (registriesCount % 50000 == 0)
                        cout << "Registros lidos: " << registriesCount << endl;

                    objPosition = 0;
                    quotationMarksCount = 0;
                    delete[]obj;
                    obj = new string[6];
                    if(registriesCount >= 20)
                        break;
                }
            }
            file.read(buffer, length);
            i = -1;

            if(registriesCount >= 20)
                break;
        }
        cout << "Quantidade de registros lidos: " << registriesCount << endl;
        cout << "Tempo gasto na leitura: " << (double) (clock() - tStart) / CLOCKS_PER_SEC << "s" << endl << endl;
        file.close();
        delete[]buffer;
        delete[]obj;
        return;
    }
    cout << "falha na leitura do arquivo!" << endl;
}

vector<Tag*>* FileUtils::readFileTag(string path)
{
    fstream file;
    file.open(path.c_str());

    if (file.is_open())
    {
        vector<Tag*>* tagList = new vector<Tag*>();
        string tag;
        int questionId;
        file >> tag >> tag;

        while (file >> questionId >> tag) {
            tag.erase(0,1);
            tagList->push_back(new Tag(questionId, tag));
        }
        return tagList;
    }
    cout << "falha na leitura do arquivo!" << endl;
    return nullptr;
}
