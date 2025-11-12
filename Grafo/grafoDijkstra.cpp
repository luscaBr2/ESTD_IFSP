#include <iostream>
using namespace std;

struct No
{
    int vertice;
    int peso;
    No *proximo;
};

void imprimirGrafo(No **grafo, int numVertices)
{
    for (int i = 0; i < numVertices; i++) // percorre todos os vértices do grafo
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

void inserirAresta(No **&grafo, int origem, int destino, int peso)
{
    // Aresta de Origem para Destino
    No *novoDestino = new No{destino, peso, nullptr};
    novoDestino->proximo = grafo[origem];
    grafo[origem] = novoDestino;
}

const int INFINITO = 9999999; // pode ser um valor simbolico inalcançável pelo grafo, mas tem que ser possível comparar com os valores do grafo

void imprimirDijkstra(int *distancias, int *predecessores, int numVertices, int raiz)
{
    cout << "Origem: vertice " << raiz << endl
         << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << "Do vertice " << raiz << " para " << i << ": distancia = " << distancias[i] << " e predecessor = " << predecessores[i] << endl;
    }
}

// auxilia o dijkistra
int encontrarMinimaDistancia(int *&distancias, bool *&processados, int *&predecessores, int numVertices)
{
    int menorDistancia = INFINITO;
    int indiceMenor = -1; // ainda não existe

    for (int i = 0; i < numVertices; i++)
    {
        // pode ser < (pega o primeiro menor) ou <= (pega o ultimo menor) ex: tem 3 vertices com o mesmo peso, o igual pega o vertice 3, o menor pega o vertice 1
        if (distancias[i] <= menorDistancia && processados[i] == false)
        {
            menorDistancia = distancias[i];
            indiceMenor = i;
        }
    }
}

void dijkstra(No **grafo, int raiz, int numVertices)
{
    int *distancias = new int[numVertices];

    // predecessores começa com -1 (tem que ser o valor de um vertice que não existe)
    // menos o da raiz, que é predecessor de si mesmo
    int *predecessores = new int[numVertices];

    // processados, todos começam com como falso
    bool *processados = new bool[numVertices](); // ja são inicializados como false por conta do () no final

    for (int i = 0; i < numVertices; i++)
    {
        distancias[i] = INFINITO;
        predecessores[i] = -1;
    }

    // a distancia da raiz (origem) para ela mesma é sempre zero
    distancias[raiz] = 0;

    for (int i = 0; i < numVertices; i++)
    {
        // se o grafo for desconexo, vai retornar infinito pois esse grafo não tem acesso ao vertice desconexo
        int verticeAtual = encontrarMinimaDistancia(distancias, processados, predecessores, numVertices);

        if (verticeAtual == -1)
            break;

        if (distancias[verticeAtual] == INFINITO)
            break;

        // para percorrer todos os vizinhos, no pior dos casos teremos que ver todos
        for (int j = 0; j < numVertices; j++)
        {
            // condições para atualizar a distancia e predecessores:
            // o vertice nn pode ter sido processado
            // o vertice precisa ter conexão com o vertice atual
            if (processados[j] == false && <se existe aresta entre verticeAtual e grafo[j]>)
            {
            }
        }
    }

    imprimirDijkstra(distancias, predecessores, numVertices, raiz);
}

// Imprime a matriz de adjacência (numVertices x numVertices)
void imprimirMatrizAdjacencia(No **grafo, int numVertices)
{
    cout << "Matriz de Adjacencia:" << endl;

    // escreve o vertice antes dos valores da tabela, cabeçalho da tabela
    cout << "   "; // 3 espaços
    for (int i = 0; i < numVertices; i++)
        cout << "v" << i << " ";

    cout << endl;

    for (int i = 0; i < numVertices; ++i) // percorre as linhas (vértices de origem)
    {
        cout << "v" << i << " "; // mostra o v linha por linha

        for (int j = 0; j < numVertices; ++j) // percorre as colunas (vértices de destino)
        {
            int valor = -1; // ausência de aresta i -> j

            // percorre a lista de adjacência do vértice i
            for (No *atual = grafo[i]; atual != nullptr; atual = atual->proximo)
            {
                // se há aresta de i para j, salva o peso e interrompe a busca
                if (atual->vertice == j)
                {
                    valor = atual->peso;
                    break;
                }
            }
            if (valor >= 0 && valor <= 9)
                cout << "0" << valor;
            else
                cout << valor;

            // coloca espaço entre colunas ou nova linha no fim da linha
            cout << (j < numVertices - 1 ? ' ' : '\n');
        }
    }
}

int main()
{
    cout << "Insira o numero de vertices do grafo: ";
    int numVertices;
    cin >> numVertices;

    cout << endl;
    cout << "====================================" << endl;

    No **grafo = new No *[numVertices];

    for (int i = 0; i < numVertices; i++) // inicializa cada lista como vazia (nullptr)
        grafo[i] = nullptr;

    for (int i = 0; i < numVertices; i++)
    {
        cout << "Insira para qual vertice o v" << i << " deve ser direcionado: ";
        int verticeDestino;
        cin >> verticeDestino;

        cout << "Insira o peso entre v" << i << " e v" << verticeDestino << ": ";
        int pesoEntreVertices;
        cin >> pesoEntreVertices;

        inserirAresta(grafo, i, verticeDestino, pesoEntreVertices);

        cout << "====================================" << endl;
    }

    imprimirMatrizAdjacencia(grafo, numVertices);

    cout << "Insira o vertice de origem: ";
    int verticeOrigem;
    cin >> verticeOrigem;
}