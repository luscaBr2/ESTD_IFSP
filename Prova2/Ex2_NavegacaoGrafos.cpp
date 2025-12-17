#include <iostream>

using namespace std;

const int NUMERO_VERTICES = 6;

struct No // lista encadeada
{
    int vertice;
    No *proximo;
    int peso;
};

void inserirAresta(No **grafo, int origem, int destino, int peso)
{
    // aresta de origem para destino
    No *novoOrigem = new No{origem, nullptr, peso}; // se tivesse peso precisaria mandar aqui tambem
    No *novoDestino = new No{destino, nullptr, peso};

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
            cout << "->" << atual->vertice << "[" << atual->peso << "]"; // se tivesse peso
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

const int INFINITO = 9999999;

int dijkstra(bool *processados)
{
    int distancias[100];
    int menorDistancia = INFINITO;

    // predecessores começa com -1 (tem que ser o valor de um vertice que não existe)
    // menos o da raiz, que é predecessor de si mesmo
    int *predecessores = new int[NUMERO_VERTICES];

    for (int i = 0; i < NUMERO_VERTICES; i++)
    {
        distancias[i] = INFINITO;
        predecessores[i] = -1;
    }

    for (int i = 0; i < NUMERO_VERTICES; i++)
    {
        // pode ser < (pega o primeiro menor) ou <= (pega o ultimo menor) ex: tem 3 vertices com o mesmo peso, o igual pega o vertice 3, o menor pega o vertice 1
        if (distancias[i] <= menorDistancia && processados[i] == false)
        {
            menorDistancia = distancias[i];
        }
    }

    return menorDistancia;
}

int buscaLargura(No **grafo, int origem, int destino)
{
    bool *processados = new bool[NUMERO_VERTICES];

    for (int i = 0; i < NUMERO_VERTICES; i++)
        processados[i] = false;

    int menorDistancia = 0;

    processados[origem] = true;
    enfileirar(origem);

    while (inicio != fim)
    {
        // sendo processado agora
        int verticeAtual = fila[inicio];
        desenfileirar();

        menorDistancia = dijkstra(processados);

        if (verticeAtual == destino) // caso de encontrar o destino
        {
            cout << "Caminho existe, soma dos pesos no caminho:" << menorDistancia;
            return menorDistancia;
        }

        No *cabecaFilaVizinhos = grafo[verticeAtual];

        while (cabecaFilaVizinhos != nullptr)
        {
            if (!processados[cabecaFilaVizinhos->vertice])
            {
                // talvez se colocar o vertice aqui mostra o caminho usado
                cout << cabecaFilaVizinhos->vertice << " - ";
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

    inserirAresta(grafo, 0, 1, 11);
    inserirAresta(grafo, 0, 2, 11);

    inserirAresta(grafo, 1, 2, 12);
    inserirAresta(grafo, 1, 3, 13);

    inserirAresta(grafo, 3, 2, 15);

    inserirAresta(grafo, 4, 1, 17);
    inserirAresta(grafo, 4, 3, 18);

    inserirAresta(grafo, 5, 3, 19);

    imprimirGrafo(grafo);

    buscaLargura(grafo, 0, 4); // buscar do zero para o quatro
    return 0;

    /*
    Por que a Busca em Profundidade (DFS) não garante encontrar o
    caminho mais curto em um grafo não ponderado, diferentemente da BFS?

    o DFS não garante encontrar o caminho mais curto em um grafo não ponderado pois nesse estilo de
    busca não é considerada quantas arestas foram percorridas, apenas as percorre até não ter
    mais arestas não vizitadas

    Já o BFS considera todos os vertices que possuem ligação direta com algum vertice exibido,
    garantindo que o proximo vertice a ser exibido sempre será ligado ao vertice de origem,
    evitando dar "saltos" desnecessários para chegar ao objetivo

    */
}