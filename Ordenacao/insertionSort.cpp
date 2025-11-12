#include <iostream>

using namespace std;

int TAM_VETOR;

void mostrarVetor(int *vetor)
{
    for (int i = 0; i < TAM_VETOR; i++)
        cout << vetor[i] << " ";

    cout << endl;
}

void insertionSort(int vetor[])
{
    int atual, cont;

    for (int i = 1; i < TAM_VETOR; i++)
    {
        atual = vetor[i];
        cont = i - 1;

        while (cont >= 0 && vetor[cont] > atual)
        {
            vetor[cont + 1] = vetor[cont];
            cont--;
        }

        vetor[cont + 1] = atual;
    }
}

int main()
{
    int vetor[] = {5, 2, 8, 1, 9, -1};
    TAM_VETOR = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor inserido: ";
    mostrarVetor(vetor);

    return 0;
}