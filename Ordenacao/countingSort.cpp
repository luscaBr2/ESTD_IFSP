#include <iostream>

using namespace std;

void mostrarVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        cout << vetor[i] << " - ";

    cout << endl;
}

void countingSort(int vetor[], int tamanho)
{
    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++) // pega o maior VALOR
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }

    // passo 1: realizar contagem
    int contagem[maior + 1];

    for (int i = 0; i <= maior; i++) // zera tudo antes de usar
        contagem[i] = 0;

    for (int i = 0; i < tamanho; i++)
    {
        contagem[vetor[i]]++;
    }

    // para ver a contagem sem acumular
    // for (int i = 0; i <= maior; i++)
    // {
    //     cout << contagem[i] << ", ";
    // }

    // Passo 2: Acumular
    for (int i = 1; i <= maior; i++) // pula o 1 para ja começar somando o segundo elemento com o primeiro
    {
        contagem[i] = contagem[i] + contagem[i - 1];
    }

    // Passo 3: posicionamento
    int vetorSaida[tamanho];

    for (int i = tamanho - 1; i >= 0; i++) // de tras para frente para garanatir a estabilidade dos dados
    {
        vetorSaida[contagem[vetor[i]] - 1] = vetor[i];
        contagem[vetor[i]]--;
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = vetorSaida[i];
    }
}

int main()
{

    int vetor[] = {5, 2, 8, 1, 9, 7};
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor original: ";
    mostrarVetor(vetor, tamanhoVetor);

    countingSort(vetor, tamanhoVetor);

    cout << "Vetor ordenado: ";
    mostrarVetor(vetor, tamanhoVetor);

    return 0;
}