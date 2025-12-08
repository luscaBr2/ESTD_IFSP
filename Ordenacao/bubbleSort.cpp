#include <iostream>

using namespace std;

int TAM_VETOR;

void bubbleSortRaiz(int vetor[])
{
    for (int j = 0; j < TAM_VETOR - 1; j++)
    {
        for (int i = 0; i < TAM_VETOR - 1 - j; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                int aux = vetor[i];      // faz backup do menor
                vetor[i] = vetor[i + 1]; // troca o menor pelo maior
                vetor[i + 1] = aux;      // coloca o menor na posição anterior
            }
        }
    }
}

void bubbleSortNutella(int vetor[])
{
    for (int i = 0; i < TAM_VETOR; i++)
    {
        for (int j = i; j < TAM_VETOR; j++)
        {
            if (vetor[i] > vetor[j]) // se anterior for maior que o proximo, troca
            {
                int aux = vetor[j];  // faz backup do menor
                vetor[j] = vetor[i]; // troca o menor pelo maior
                vetor[i] = aux;      // coloca o menor na posição anterior
            }
        }
    }
}

void mostrarVetor(int *vetor)
{
    for (int i = 0; i < TAM_VETOR; i++)
        cout << vetor[i] << " ";

    cout << endl;
}

int main()
{
    int vetor[] = {5, 2, 8, 1, 9};
    TAM_VETOR = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor inserido: ";
    mostrarVetor(vetor);

    /*
    bubbleSortNutella(vetor);

    cout << "Vetor ordenado pelo bubble Sort Nutella: ";
    mostrarVetor(vetor);
    */

    // ordena
    bubbleSortRaiz(vetor);

    cout << "Vetor ordenado pelo bubble Sort Raiz: ";
    mostrarVetor(vetor);

    return 0;
}