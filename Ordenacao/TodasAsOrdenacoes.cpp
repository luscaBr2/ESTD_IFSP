#include <iostream>
using namespace std;

void mostrarVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        if (i + 1 == tamanho)
            cout << vetor[i] << endl;
        else 
            cout << vetor[i] << " - ";
    }
}

int cont = 0;

void bubbleSort(int vetor[], int tamanho){
    bool trocou;

    for (int j = 0; j < tamanho - 1; j++)
    {
        trocou = false;
        for (int i = 0; i < tamanho - 1 - j; i++)
        {
            cont++;
            if (vetor[i] > vetor[i + 1]) {
                int auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;
                trocou = true;
            }
        }
        if (!trocou)
            break;      
    }
}

void selectionSort(int vetor[], int tamanho){
    for (int j = 0; j < tamanho - 1; j++)
    {
        int indiceMenor = j;

        for (int i = j + 1; i < tamanho; i++)
        {
            if (vetor[i] < vetor[indiceMenor])
                indiceMenor = i;
        }

        if (indiceMenor != j){
            int auxiliar = vetor[j];
            vetor[j] = vetor[indiceMenor];
            vetor[indiceMenor] = auxiliar;
        }
    }
}

void insertionSort(int vetor[], int tamanho){
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

void countingSort(int vetor[], int tamanho) {
    if (tamanho <= 0) return;

    // Passo 0: Achar o maior elemento para definir o tamanho do vetor de contagem
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    // CORREÇÃO 1: Alocação Dinâmica para evitar Stack Overflow
    // Se 'maior' for 1 milhão, um vetor estático travaria o programa.
    int* contagem = new int[maior + 1];

    // Zerando o vetor de contagem
    for (int i = 0; i <= maior; i++)
        contagem[i] = 0;

    // Passo 1: Realizar a contagem de frequências
    for (int i = 0; i < tamanho; i++)
        contagem[vetor[i]]++;

    // (Opcional) Debug: mostrarVetor(contagem, maior + 1);

    // Passo 2: Acumular (Soma de prefixos)
    for (int i = 1; i <= maior; i++)
        contagem[i] = contagem[i] + contagem[i - 1];

    // (Opcional) Debug: mostrarVetor(contagem, maior + 1);

    // CORREÇÃO 2: Alocação Dinâmica para o vetor de saída
    int* vetorSaida = new int[tamanho];

    // Passo 3: Posicionamento (De trás para frente para manter estabilidade)
    for (int i = tamanho - 1; i >= 0; i--) {
        // O valor acumulado indica a posição final (1-based), então subtraímos 1
        vetorSaida[contagem[vetor[i]] - 1] = vetor[i];
        contagem[vetor[i]]--;
    }

    // Passo 4: Copiar de volta para o vetor original
    for (int i = 0; i < tamanho; i++)
        vetor[i] = vetorSaida[i];

    // CORREÇÃO 3: Liberar a memória (Essencial em C++)
    delete[] contagem;
    delete[] vetorSaida;
}

// Função auxiliar que intercala (funde) dois subvetores ordenados
void merge(int vetor[], int inicio, int meio, int fim) {
    
    // Passo 1: Calcular o tamanho dos subvetores
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Passo 2: Alocação Dinâmica dos vetores temporários
    // Usamos 'new' para evitar Stack Overflow em vetores grandes
    int* Esquerda = new int[n1];
    int* Direita = new int[n2];

    // Copiando os dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        Esquerda[i] = vetor[inicio + i];
    
    for (int j = 0; j < n2; j++)
        Direita[j] = vetor[meio + 1 + j];

    // Passo 3: Intercalação (Merge) dos vetores de volta ao vetor original
    int i = 0; // Índice inicial do subvetor da esquerda
    int j = 0; // Índice inicial do subvetor da direita
    int k = inicio; // Índice inicial do vetor fundido

    while (i < n1 && j < n2) {
        if (Esquerda[i] <= Direita[j]) {
            vetor[k] = Esquerda[i];
            i++;
        } else {
            vetor[k] = Direita[j];
            j++;
        }
        k++;
    }

    // Passo 4: Copiar os elementos restantes (se houver)
    // Copia o resto da Esquerda, se sobrou
    while (i < n1) {
        vetor[k] = Esquerda[i];
        i++;
        k++;
    }

    // Copia o resto da Direita, se sobrou
    while (j < n2) {
        vetor[k] = Direita[j];
        j++;
        k++;
    }

    // Passo 5: Liberar memória (Fundamental em C++)
    delete[] Esquerda;
    delete[] Direita;
}

// Função recursiva interna (Núcleo do algoritmo)
void mergeSortRecursivo(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
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
void mergeSort(int vetor[], int tamanho) {
    // Verifica se o vetor é válido
    if (tamanho <= 0) return;

    // Chama a função recursiva passando os índices corretos
    mergeSortRecursivo(vetor, 0, tamanho - 1);
}

int main(int argc, char const *argv[])
{
    //int vetor[] = {5, 2, 8, 1, 9, 7};
    //int vetor[] = {9, 8, 7, 5, 2, 1};
    //int vetor[] = {1, 2, 6, 7, 8, 9};
    int vetor[] = {4, 2, 2, 8, 3, 3, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    mostrarVetor(vetor, tamanho);
    countingSort(vetor, tamanho);
    mostrarVetor(vetor, tamanho);
    //cout << cont;

    return 0;
}
