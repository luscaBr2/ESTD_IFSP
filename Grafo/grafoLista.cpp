#include <iostream>
using namespace std;

int fila[100];
int inicio = 0;
int fim = 0;

void Enfileirar(int valor)
{
    if (fim == 100)
    {
        cout << "Fila cheia!!" << endl;
        return;
    }

    fila[fim] = valor; // coloca valor na posição fim da fila
    fim++;
}

void Desenfileirar()
{
    if (inicio == fim) // verifica se a fila está vazia // não há elementos para remover
    {
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}

struct No
{
    int vertice;
    int peso; // peso da aresta (para grafos ponderados)
    No *proximo;
};

void inserirAresta(No **&grafo, int origem, int destino, int peso)
{
    // Aresta de Origem para Destino
    No *novoDestino = new No{destino, peso, nullptr}; // aloca novo nó para destino com peso e próximo nulo
    novoDestino->proximo = grafo[origem];             // aponta o próximo do novo nó para a cabeça da lista de origem
    grafo[origem] = novoDestino;                      // torna o novo nó a nova cabeça da lista de adjacência da origem

    // Aresta de Destino para Origem
    // No* novoOrigem = new No {origem, peso, nullptr}; //  para grafos não direcionados, criar também origem->destino
    // novoOrigem->proximo = grafo[destino]; //  ligar novo nó na lista do destino
    // grafo[destino] = novoOrigem; // definir cabeça da lista do destino
} // fecha função inserirAresta

void imprimirGrafo(No **grafo, int NUMERO_VERTICES)
{
    for (int i = 0; i < NUMERO_VERTICES; i++) // percorre todos os vértices do grafo
    {
        No *atual = grafo[i];
        cout << "Vertice " << i << ": ";
        while (atual != nullptr) // percorre todos os nós na lista de adjacência do vértice i
        {
            cout << "->" << atual->vertice << "[" << atual->peso << "]";
            atual = atual->proximo; // avança para o próximo nó na lista
        }
        cout << endl;
    }
}

void buscaLargura(No **grafo, int origem, int destino, int NUMERO_VERTICES) // implementação da busca em largura (BFS) // verifica existência de caminho origem->destino
{
    bool *processados = new bool[NUMERO_VERTICES]; // aloca vetor dinâmico para marcar vértices visitados na BFS
    for (int i = 0; i < NUMERO_VERTICES; i++)      // inicializa todos os vértices como não processados
        processados[i] = false;

    processados[origem] = true; // marca o vértice origem como processado (visitado)
    Enfileirar(origem);         // enfileira o vértice origem para iniciar a BFS

    while (inicio != fim) // enquanto a fila não estiver vazia, continua processando
    {
        int verticeAtual = fila[inicio]; // obtém o vértice no início da fila
        Desenfileirar();                 // remove o elemento do início da fila

        if (verticeAtual == destino) // se o vértice atual é o destino, caminho existe
        {
            cout << "Caminho Existe!";
            return;
        }

        No *cabecaFilaVizinho = grafo[verticeAtual]; // obtém cabeça da lista de adjacência do vértice atual
        while (cabecaFilaVizinho != nullptr)         // percorre todos os vizinhos do vértice atual
        {
            if (!processados[cabecaFilaVizinho->vertice]) // se o vizinho ainda não foi processado
            {
                processados[cabecaFilaVizinho->vertice] = true; // marca o vizinho como processado
                Enfileirar(cabecaFilaVizinho->vertice);         // enfileira o vizinho para processar depois
            }

            cabecaFilaVizinho = cabecaFilaVizinho->proximo; // avança para o próximo vizinho
        }
    }

    cout << "Caminho Nao Existe!";
}

bool buscaProfundidadeRec(No **grafo, int atual, int destino, bool *visitado) // retorna true se caminho encontrado
{
    visitado[atual] = true; // marca o vértice atual como visitado
    if (atual == destino)   // verifica se o vértice atual é o destino // caso base da recursão
        return true;        // retorna true imediatamente se destino alcançado

    No *vizinho = grafo[atual]; // obtém a cabeça da lista de adjacência do vértice atual
    while (vizinho != nullptr)  // percorre cada vizinho do vértice atual
    {
        if (!visitado[vizinho->vertice]) // se o vizinho ainda não foi visitado
        {
            if (buscaProfundidadeRec(grafo, vizinho->vertice, destino, visitado)) // chamada recursiva para o vizinho
                return true;                                                      // se a chamada recursiva encontrar o destino, propaga true para cima
        }
        vizinho = vizinho->proximo; // avança para o próximo vizinho na lista
    }

    return false; // se nenhum vizinho levou ao destino, retorna false
}

// (Depth-First Search - DFS)
void buscaProfundidade(No **grafo, int origem, int destino, int NUMERO_VERTICES) // imprime se caminho existe
{
    bool *visitado = new bool[NUMERO_VERTICES]; // aloca vetor dinâmico para marcar vértices visitados na DFS
    for (int i = 0; i < NUMERO_VERTICES; i++)   // inicializa todos os vértices como não visitados
        visitado[i] = false;                    // marca posição i como não visitada

    bool existe = buscaProfundidadeRec(grafo, origem, destino, visitado); // chama a função recursiva a partir da origem
    if (existe)
        cout << "Caminho Existe!";
    else
        cout << "Caminho Nao Existe!";
}

int main()
{
    const int NUMERO_VERTICES = 6;
    No **grafo = new No *[NUMERO_VERTICES];

    for (int i = 0; i < NUMERO_VERTICES; i++) // inicializa cada lista como vazia (nullptr)
        grafo[i] = nullptr;

    inserirAresta(grafo, 0, 1, 0);
    inserirAresta(grafo, 0, 2, 0);

    inserirAresta(grafo, 1, 2, 0);
    inserirAresta(grafo, 1, 3, 0);

    inserirAresta(grafo, 2, 0, 0);
    inserirAresta(grafo, 2, 3, 0);

    inserirAresta(grafo, 3, 2, 0);
    inserirAresta(grafo, 3, 4, 0);
    inserirAresta(grafo, 3, 5, 0);

    inserirAresta(grafo, 4, 1, 0);
    inserirAresta(grafo, 4, 3, 0);

    inserirAresta(grafo, 5, 2, 0);
    inserirAresta(grafo, 5, 3, 0);

    // impressão do grafo para visualização
    imprimirGrafo(grafo, NUMERO_VERTICES); // imprime as listas de adjacência do grafo

    cout << endl;
    buscaLargura(grafo, 0, 4, NUMERO_VERTICES); // executa busca em largura do vértice 0 até 4
    cout << endl;

    // tem que retornar true, pois
    buscaProfundidade(grafo, 0, 4, NUMERO_VERTICES); // executa busca em profundidade do vértice 0 até 4
    cout << endl;

    return 0;
}
