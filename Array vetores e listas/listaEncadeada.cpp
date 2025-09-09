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
        cabeca = novoNode;
    else
    {
        Node *aux = cabeca;
        while (aux->prox != nullptr)
            aux = aux->prox;

        aux->prox = novoNode;
    }
}

void ExibirLista(const Node *cabeca)
{
    const Node *aux = cabeca;
    while (aux != nullptr)
    {
        cout << aux->valor << " ";
        aux = aux->prox;
    }

    cout << endl;
}

int main()
{
    Node *cabeca = nullptr;
    int novoValor;
    do
    {
        cin >> novoValor;

        if (cabeca == nullptr)
        {
            Node *novoNode = new Node{novoValor, nullptr};
            cabeca = novoNode;
        }
        else
            inserirFim(cabeca, novoValor);

        ExibirLista(cabeca);
    } while (novoValor != -1);

    return 0;
}