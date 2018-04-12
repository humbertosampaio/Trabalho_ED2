//
// Created by edson on 28/03/18.
//

#include "../Headers/FileUtils.h"

vector<Question*>* FileUtils::readFileQuestion(string path)
{
fstream file;
    file.open(path.c_str());
    string str;
    vector<Question*>* questionList = new vector<Question*>();
    if (file.is_open())
    {
        //variavel para calcular tempo de execucao
        clock_t tStart = clock();
        //pegando o numero de bytes do arquivo
        file.seekg(0, file.end);
        //int length = file.tellg();
        unsigned int length = 1024*2014;
        file.seekg(0, file.beg);
        //criando e inicializando buffer
        char* buffer = new char[length];
        file.read(buffer,length);
        //variaveis auxiliares
        string tempString;
        string* obj = new string[6];
        int objPosition = 0;
        int quotationMarksCount = 0;
        long registriesCount = 0;
        int i = -1;

        //ignorando cabecalho
        for (; buffer[i] != '\n'; ++i);
        //iteracao principal

        while (!file.eof())
        {
            for (; ++i < length && buffer[i] != char_traits<char>::eof();)
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
                if (objPosition > 5) {
                    questionList->push_back(new Question(obj));
                    registriesCount++;

                    if (registriesCount % 50000 == 0)
                        cout << "Registros lidos: " << registriesCount << endl;

                    objPosition = 0;
                    quotationMarksCount = 0;
                    delete[]obj;
                    obj = new string[6];
                }
            }
            file.read(buffer,length);
            i = -1;
        }
        cout << "tempo de execucao " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
        delete []buffer;
        delete []obj;
        return questionList;
    }
return nullptr;
}


