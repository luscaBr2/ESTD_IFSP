#include <iostream>

using namespace std;

const int NUMERO_VERTICES = 5;

struct No // lista encadeada
{
    int vertice;
    // int peso; para transformar em grafo ponderado
    No *proximo;
};

void inserirAresta(No **grafo, int origem, int destino)
{
    // aresta de origem para destino
    No *novoOrigem = new No{origem, nullptr}; // se tivesse peso precisaria mandar aqui tambem
    No *novoDestino = new No{destino, nullptr};

    // inserindo no começo da lista
    novoDestino->proximo = grafo[origem];
    grafo[origem] = novoDestino;

    // add essas 2 linhas transforma esse grafo em não direcional, se tirar, ele vira um grafo direcional
    // novoOrigem->proximo = grafo[destino];
    // grafo[destino] = novoOrigem;
}

// lista de adjacencias
void imprimirGrafo(No **grafo)
{
    for (int i = 0; i < NUMERO_VERTICES; i++)
    {
        No *atual = grafo[i];
        cout << "Vertice " << i << ": ";
        while (atual != nullptr)
        {
            cout << "->" << atual->vertice; // << "[" << atual->peso << "]"; // se tivesse peso
            atual = atual->proximo;
        }

        cout << endl;
    }
}

// FILA PARA USAR NA EXIBIÇÃO POR LARGURA
//==========================================
int fila[100];
int inicio = 0;
int fim = 0;

void enfileirar(int valor)
{
    if (fim == 100)
        return;

    fila[fim] = valor;

    fim++;
}

void desenfileirar()
{
    if (inicio == fim)
    {
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}
// ====================================
// buscar o caminho de um ponto A para o ponto B
void buscaLargura(No **grafo, int origem, int destino)
{
    bool *processados = new bool[NUMERO_VERTICES];

    for (int i = 0; i < NUMERO_VERTICES; i++)
        processados[i] = false;

    processados[origem] = true;
    enfileirar(origem);

    while (inicio != fim)
    {
        // sendo processado agora
        int verticeAtual = fila[inicio];
        desenfileirar();

        if (verticeAtual == destino) // caso de encontrar o destino
        {
            cout << "Caminho existe" << endl;
            return;
        }

        No *cabecaFilaVizinhos = grafo[verticeAtual];

        while (cabecaFilaVizinhos != nullptr)
        {
            if (!processados[cabecaFilaVizinhos->vertice])
            {
                // talvez se colocar o vertice aqui mostra o caminho usado
                processados[cabecaFilaVizinhos->vertice] = true; // registra que o vertice foi processado
                enfileirar(cabecaFilaVizinhos->vertice);
            }
            cabecaFilaVizinhos = cabecaFilaVizinhos->proximo;
        }
    }

    cout << "Caminho nao existe" << endl;
}

int main()
{
    No **grafo = new No *[NUMERO_VERTICES]; // caso de grafo com 5 arestas

    // limpa o grafo antes de usar
    for (int i = 0; i < NUMERO_VERTICES; i++)
        grafo[i] = nullptr;

    inserirAresta(grafo, 0, 1);
    inserirAresta(grafo, 0, 2);

    inserirAresta(grafo, 1, 2);
    inserirAresta(grafo, 1, 3);

    inserirAresta(grafo, 2, 0);
    inserirAresta(grafo, 3, 2);

    inserirAresta(grafo, 4, 1);
    inserirAresta(grafo, 4, 3);

    imprimirGrafo(grafo);
    buscaLargura(grafo, 4, 3);
    buscaLargura(grafo, 4, 9);
    return 0;
}