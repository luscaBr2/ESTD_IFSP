#include <iostream>

using namespace std;

int TAM_VETOR;

void mostrarVetor(int *vetor)
{
    for (int i = 0; i < TAM_VETOR; i++)
        cout << vetor[i] << " ";

    cout << endl;
}

void selectionSort(int vetor[]) // REVISAR POIS ESTÁ DANDO ERRO :(
{

    for (int j = 0; j < TAM_VETOR - 1; j++)
    {
        //===================================================================
        int posicaoDoMenor = j;

        for (int i = j + 1; i < TAM_VETOR; i++) // começa em 1 pois o zero ja é o menor no inicio
        {
            if (vetor[i] < vetor[posicaoDoMenor]) // se o valor atual é menor que o proximo, então menor = atual
                posicaoDoMenor = i;
            else // se não, então o proximo é o menor entre os 2, logo menor = proximo
                posicaoDoMenor = i + 1;
        }
        //===================================================================

        if (posicaoDoMenor != j)
        {
            int aux = vetor[j];
            vetor[j] = vetor[posicaoDoMenor];
            vetor[posicaoDoMenor] = aux;
        }
    }
}

int main()
{
    int vetor[] = {5, 2, 8, 1, 9, -1};
    TAM_VETOR = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor inserido: ";
    mostrarVetor(vetor);

    selectionSort(vetor);

    cout << "Vetor ordenado pelo Selection sort: ";
    mostrarVetor(vetor);

    return 0;
}