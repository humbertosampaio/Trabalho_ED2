#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Headers/FileUtils.h"
#include "Headers/InsertionSort.h"
#include "Headers/MergeSort.h"
#include "../Source/InsertionSort.cpp"
#include "../Source/MergeSort.cpp"


using namespace std;

vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n);



int main(int argc, char** argv)
{
    //string path = "/home/edson/pythonquestions/Questions.csv"; //edson
    //string path = "/media/viniman/Files/Google Drive/UFJF/2018/1/ED2/Trabalho/pythonquestions/Questions.csv";
    string path = "../../pythonquestions/Questions.csv";
    vector<Question> listQuestions;
    FileUtils::readFileQuestion(path, listQuestions);

    cout << "Tam: " << listQuestions.size() << endl << endl;
    cout << "Ordenacao ListQuestions" << endl;
    random_shuffle ( listQuestions.begin(), listQuestions.end() );

    for(const auto &it : listQuestions)
        cout << it.getQuestionId() << " ";
    cout << endl << endl;

    //InsertionSort::insertionSort(listQuestions);
    MergeSort::mergeSort(listQuestions, 0, listQuestions.size());


    cout << "Ordenado\n";
    for(const auto &it : listQuestions)
        cout << it.getQuestionId() << " ";
    cout << endl << endl;


    cout << "Ordenando Inteiros" << endl;
    vector<int> vetQuestionId = getVetQuestionIdAleatorios(listQuestions, 10);
    random_shuffle ( vetQuestionId.begin(), vetQuestionId.end() );

    for(const auto it : vetQuestionId)
        cout << it << " ";
    cout << endl << endl;

    //InsertionSort::insertionSort(vetQuestionId);
    MergeSort::mergeSort(vetQuestionId, 0, listQuestions.size()-1);

    cout << "Ordenado\n";
    for(const auto it : vetQuestionId)
        cout << it << " ";
    cout << endl << endl;


    return 0;
}

vector<int> getVetQuestionIdAleatorios(const vector<Question> &listQuestions, const int &n)
{
    vector<int> vetQuestionId;// = new vector<int>;
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 eng(seed);    ///mersenne twister engine
    uniform_int_distribution<unsigned long> distAleatoria(0,listQuestions.size()-1);

    //srand(static_cast<unsigned int>(time(nullptr)));

    for(int i = 0; i < n; i++)
    {
        vetQuestionId.emplace_back(listQuestions[distAleatoria(eng)].getQuestionId());
        //vetQuestionId[i] = listQuestions->at(rand()%(listQuestions->size()-1))->getQuestionId();
    }

    return vetQuestionId;
}
