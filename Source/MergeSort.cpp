//
// Created by viniman on 11/04/18.
//

#include "../Headers/MergeSort.h"


void MergeSort::intercala(int *vet, int inicio, int meio, int fim)
{
    int indInicio = inicio;
    int indMeio = meio+1;
    int indAux = 0;
    auto *vetAux = new int[inicio+fim+1];
    for(int i=0; i<inicio+fim+1; i++)
        vetAux[i] = vet[i];

    while (indInicio < meio+1 || indMeio < fim+1)
    {
        if(indInicio == meio+1)
        {
            vetAux[indAux] = vet[indMeio];
            indMeio++;
            indAux++;
        }
        else if(indMeio == fim+1)
        {
            vetAux[indAux] = vet[indInicio];
            indInicio++;
            indAux++;
        }
        else if(vet[indInicio] <= vet[indMeio])
        {
            vetAux[indAux] = vet[indInicio];
            indInicio++;
            indAux++;
        }
        else
        {
            vetAux[indAux] = vet[indMeio];
            indMeio++;
            indAux++;
        }
    }

    for(indInicio = inicio; indInicio <= fim; indInicio++)
        vet[indInicio] = vetAux[indInicio-inicio];
}

void MergeSort::mergeSort(int *vet, int inicio, int fim)
{

    if(inicio < fim)
    {
        int meio = (inicio+fim)/2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio+1, fim);
        intercala(vet, inicio, meio, fim);
    }
}