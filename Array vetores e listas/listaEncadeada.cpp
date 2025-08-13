#include <iostream>

using namespace std;

struct Node
{
    int valor;
    Node *prox;
};

void inserirFim(Node *cabeca, int valor)
{
    // inicia com nullptr para que seja sinalizado que esse é o ultimo elemento da lista, e pq não sabemos o próximo elemento
    Node *novoNode = new Node{valor, nullptr};

    if (cabeca == nullptr)
    {
        cabeca = novoNode;
    }
    else
    {
        Node *aux = cabeca;
        while (aux->prox != nullptr)
        {
            aux = aux->prox;
        }
        aux->prox = novoNode;
    }
}

int main()
{
    int novoValor;
    cin >> novoValor;

    Node *cabeca = nullptr;

    inserirFim(cabeca, novoValor);

    return 0;
}