#include <iostream> // Inclui a biblioteca iostream para entrada e saída padrão (cin e cout)

using namespace std; // Permite usar elementos do namespace std sem prefixo, como cout e cin

// Função para mesclar duas sublistas ordenadas em uma única lista ordenada
// Recebe o array, o índice esquerdo, o meio e o direito
void merge(int arr[], int left, int mid, int right)
{
    // Calcula o tamanho das duas sublistas
    int n1 = mid - left + 1; // Tamanho da primeira metade (esquerda)
    int n2 = right - mid;    // Tamanho da segunda metade (direita)

    // Cria arrays temporários para armazenar as sublistas
    int *L = new int[n1]; // Array temporário para a metade esquerda
    int *R = new int[n2]; // Array temporário para a metade direita

    // Copia os elementos da metade esquerda para o array temporário L
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i]; // Copia arr[left] até arr[mid]
    }

    // Copia os elementos da metade direita para o array temporário R
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j]; // Copia arr[mid+1] até arr[right]
    }

    // Índices para percorrer os arrays temporários e o array original
    int i = 0;    // Índice para L
    int j = 0;    // Índice para R
    int k = left; // Índice para o array original arr

    // Mescla os arrays temporários de volta no array original, comparando elementos
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {                  // Se o elemento de L for menor ou igual ao de R
            arr[k] = L[i]; // Coloca o elemento de L no array original
            i++;           // Avança no array L
        }
        else
        {
            arr[k] = R[j]; // Coloca o elemento de R no array original
            j++;           // Avança no array R
        }
        k++; // Avança no array original
    }

    // Copia os elementos restantes de L, se houver
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R, se houver
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória dos arrays temporários
    delete[] L;
    delete[] R;
}

// Função recursiva para implementar o Merge Sort
// Recebe o array, o índice esquerdo e o direito
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    { // Condição de parada: se há mais de um elemento
        // Calcula o meio do array
        int mid = left + (right - left) / 2; // Evita overflow em comparação com (left + right)/2

        // Chama recursivamente mergeSort para a metade esquerda
        mergeSort(arr, left, mid);

        // Chama recursivamente mergeSort para a metade direita
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
    // Se left >= right, a sublista tem 0 ou 1 elemento, já está ordenada
}

int main()
{
    // Exemplo de uso: cria um array desordenado
    int arr[] = {12, 11, 13, 5, 6, 7};    // Array de exemplo
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    // Imprime o array antes da ordenação
    cout << "Array antes da ordenacao: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Chama a função mergeSort para ordenar o array
    mergeSort(arr, 0, n - 1); // Índices de 0 a n-1

    // Imprime o array após a ordenação
    cout << "Array apos a ordenacao: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
