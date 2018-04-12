#include <iostream>
#include <random>
#include <chrono>
#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"

using namespace std;

int *getVetQuestionIdAleatorios(vector<Question*>* listQuestions, const int &n);


int main(int argc, char** argv)
{
    string path = "/home/edson/pythonquestions/Questions.csv"; //edson
    //string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";
    //vector<Question*>* listQuestions = FileUtils::readFileQuestion(path);
    vector<Tag*>* listTag = FileUtils::readFileTag("/home/edson/pythonquestions/Tags.csv");
    //int *vetQuestionId = getVetQuestionIdAleatorios(listQuestions, 1000);
    int n = 10;

    /*
    for(int i = 0; i < n; i++)
        cout << vetQuestionId[i] << " ";
    cout << endl << endl;


    MergeSort::mergeSort(vetQuestionId, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << vetQuestionId[i] << " ";
    cout << endl;
*/
    return 0;
}

int *getVetQuestionIdAleatorios(vector<Question*>* listQuestions, const int &n)
{
    auto *vetQuestionId = new int[n];
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 eng(seed);    ///mersenne twister engine
    uniform_int_distribution<unsigned long> distAleatoria(0,listQuestions->size()-1);

    //srand(static_cast<unsigned int>(time(nullptr)));

    for(int i = 0; i < n; i++)
    {
        vetQuestionId[i] = listQuestions->at(distAleatoria(eng))->getQuestionId();
        //vetQuestionId[i] = listQuestions->at(rand()%(listQuestions->size()-1))->getQuestionId();
    }

    return vetQuestionId;
}
