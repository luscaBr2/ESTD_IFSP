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
    novoOrigem->proximo = grafo[destino];
    grafo[destino] = novoOrigem;
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

int main()
{
    No **grafo = new No *[NUMERO_VERTICES]; // caso de grafo com 5 arestas

    // limpa o grafo antes de usar
    for (int i = 0; i < NUMERO_VERTICES; i++)
        grafo[i] = nullptr;

    inserirAresta(grafo, 0, 1);
    inserirAresta(grafo, 0, 2);

    imprimirGrafo(grafo);

    return 0;
}