#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função auxiliar que intercala (funde) dois subvetores ordenados
void merge(int vetor[], int inicio, int meio, int fim)
{

    // Passo 1: Calcular o tamanho dos subvetores
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Passo 2: Alocação Dinâmica dos vetores temporários
    // Usamos 'new' para evitar Stack Overflow em vetores grandes
    int *Esquerda = new int[n1];
    int *Direita = new int[n2];

    // Copiando os dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        Esquerda[i] = vetor[inicio + i];

    for (int j = 0; j < n2; j++)
        Direita[j] = vetor[meio + 1 + j];

    // Passo 3: Intercalação (Merge) dos vetores de volta ao vetor original
    int i = 0;      // Índice inicial do subvetor da esquerda
    int j = 0;      // Índice inicial do subvetor da direita
    int k = inicio; // Índice inicial do vetor fundido

    while (i < n1 && j < n2)
    {
        if (Esquerda[i] <= Direita[j])
        {
            vetor[k] = Esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = Direita[j];
            j++;
        }
        k++;
    }

    // Passo 4: Copiar os elementos restantes (se houver)
    // Copia o resto da Esquerda, se sobrou
    while (i < n1)
    {
        vetor[k] = Esquerda[i];
        i++;
        k++;
    }

    // Copia o resto da Direita, se sobrou
    while (j < n2)
    {
        vetor[k] = Direita[j];
        j++;
        k++;
    }

    // Passo 5: Liberar memória (Fundamental em C++)
    delete[] Esquerda;
    delete[] Direita;
}

// Função recursiva interna (Núcleo do algoritmo)
void mergeSortRecursivo(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Encontra o meio (evita overflow em relação a (inicio+fim)/2)
        int meio = inicio + (fim - inicio) / 2;

        // Dividir: Chama recursivamente para as duas metades
        mergeSortRecursivo(vetor, inicio, meio);
        mergeSortRecursivo(vetor, meio + 1, fim);

        // Conquistar: Junta as partes ordenadas
        merge(vetor, inicio, meio, fim);
    }
}

// Função Principal (Interface "nos mesmos moldes" do Counting Sort)
void mergeSort(int vetor[], int tamanho)
{
    // Verifica se o vetor é válido
    if (tamanho <= 0)
        return;

    // Chama a função recursiva passando os índices corretos
    mergeSortRecursivo(vetor, 0, tamanho - 1);
}

void insertionSort(int vetor[], int tamanho)
{
    int atual, cont;

    for (int i = 1; i < tamanho; i++)
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

void mostrarVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (i + 1 == tamanho)
            cout << vetor[i] << endl;
        else
            cout << vetor[i] << " - ";
    }
}

int main()
{
    srand(time(NULL));
    const int TAMANHO = 1000;
    int vetor[TAMANHO]; // orginal
    int vetor2[TAMANHO];
    int vetor3[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        int aleatorio = rand() % 100; // gera entre 0-99
        vetor[i] = aleatorio;
        vetor2[i] = aleatorio;
        vetor3[i] = aleatorio;
    }

    cout << "Vetor desordenado: ";
    mostrarVetor(vetor, 10);

    // ========================================
    insertionSort(vetor2, TAMANHO);

    cout << "Vetor ordenado pelo insertionSort: ";
    mostrarVetor(vetor2, 10);
    // ========================================
    mergeSort(vetor3, TAMANHO);

    cout << "Vetor ordenado pelo mergeSort: ";
    mostrarVetor(vetor3, 10);

    /*
        o insertion sort faz menos trocas se os valores ja vierem ordenados ou
        pelo menos proximos, ou seja se caso na seleção aleatória os valores ja
        foram inseridos ordenados lado a lado já otimiza o algoritmo pois não
        foi feito troca, apenas verificação, ou se pelo menos os valores não
        estiverem lado a lado mas estiverem proximos, o numero de trocas
        tambem se reduz.

        por exemplo: vetor[0,1,2,3,...] o insertion sort irá apenas verificar
        pois a lista ja está uma parte ordenada

        nessa ocasião, se os valores inseridos ja vierem totalmente ordenados
        nenhuma troca é feita, apenas verificações, fazendo com que o insertion
        sort tenha um desempenho melhor, igual ou ao menos proximo do mergeSort.
    */
}