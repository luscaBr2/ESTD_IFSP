#include <iostream>

using namespace std;

struct NoAVL
{
    int valor;
    int balanceamento; // fator de balanceamento (-1, 0, 1)
    NoAVL *direita;
    NoAVL *esquerda;
};

void buscar(int valorProcurado, NoAVL *raiz) // mesmo lógica da inserção, porém com a condição de parada
{
    if (raiz == nullptr) // condição de parada, ja que não há o que pesquisar se a raiz é nula
        cout << "Valor NAO encontrado" << endl;
    else if (valorProcurado == raiz->valor) // condição de parada, não precisa continuar quando achar o elemento
        cout << "Valor encontrado" << endl;
    else if (valorProcurado > raiz->valor)
        buscar(valorProcurado, raiz->direita);
    else
        buscar(valorProcurado, raiz->esquerda); // se não é igual nem maior, então o valor é menor
}

int contagem(NoAVL *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
    {
        return contagem(raiz->esquerda) + 1 + contagem(raiz->direita); // o 1 fixo é para contar a raiz atual + a sua esquerda + a sua direita
    }
}

// Exibir em ordem (In-Order)
// mesma lógica da contagem
void EmOrdem(NoAVL *raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esquerda);
        cout << raiz->valor << " - ";
        EmOrdem(raiz->direita);
    }
}

// Pré-ordem (pre-order): raiz → esquerda → direita
void PreOrdem(NoAVL *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->valor << " - ";
        PreOrdem(raiz->esquerda);
        PreOrdem(raiz->direita);
    }
}

// Pós-ordem (post-order): esquerda → direita → raiz
void PosOrdem(NoAVL *raiz)
{
    if (raiz != nullptr)
    {
        PosOrdem(raiz->esquerda);
        PosOrdem(raiz->direita);
        cout << raiz->valor << " - ";
    }
}

// p é de nó problema
NoAVL *rotacaoLL(NoAVL *p)
{
    NoAVL *u = p->esquerda;
    // NoAVL *v = u->esquerda; // não é usado nesse algoritmo

    p->esquerda = u->direita;
    u->direita = p;
    p->balanceamento = 0;
    u->balanceamento = 0;

    return u; // retorna a nova raiz
}

NoAVL *rotacaoRR(NoAVL *p)
{
    NoAVL *u = p->direita;
    // NoAVL *v = u->direita; // não é usado nesse algoritmo

    p->direita = u->esquerda;
    u->esquerda = p;
    p->balanceamento = 0;
    u->balanceamento = 0;

    return u; // retorna a nova raiz
}

NoAVL *rotacaoL(NoAVL *p)
{
    NoAVL *u = p->esquerda;
    // NoAVL *v = u->esquerda; // não é usado nesse algoritmo

    if ()

        p->esquerda = u->direita;
    u->direita = p;
    p->balanceamento = 0;
    u->balanceamento = 0;

    return u; // retorna a nova raiz
}

int main()
{
    NoAVL *raiz = nullptr;

    cout << "Quantidade total de elementos: " << contagem(raiz);

    cout << "\nElementos em ordem: ";
    EmOrdem(raiz);

    cout << "\nElementos em pre-ordem: ";
    PreOrdem(raiz);

    cout << "\nElementos em pos-ordem: ";
    PosOrdem(raiz);

    cout << "\nInsira o valor a ser buscado: ";
    int valorProcurado;
    cin >> valorProcurado;
    buscar(valorProcurado, raiz);

    return 0;
}