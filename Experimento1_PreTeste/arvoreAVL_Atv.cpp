
/*
Implemente um programa que realize a seguinte tarefa:

    Leia, de uma única vez, cinco números inteiro.
    Insira esses números, na ordem digitada, em uma árvore AVL inicialmente vazia.
    A cada inserção, verifique se houve necessidade de balanceamento da árvore.
    Exiba, na ordem em que ocorrerem, as rotações realizadas para manter a árvore balanceada.

Tipos de rotações a considerar:

    LL – rotação simples à direita
    RR – rotação simples à esquerda
    LR – rotação dupla (esquerda-direita)
    RL – rotação dupla (direita-esquerda)
    Nenhuma – caso a árvore já esteja balanceada

Exemplo de saída esperada:

      RL, LL, RL, LR.
*/

#include <iostream>

using namespace std;

struct NoAVL
{
    int valor;
    int balanceamento;
    NoAVL *direita;
    NoAVL *esquerda;
};

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

NoAVL *rotacaoLR(NoAVL *p)
{
    NoAVL *u = p->esquerda;
    NoAVL *v = u->direita; // nó problema

    u->direita = v->esquerda;
    p->esquerda = v->direita;
    v->esquerda = u;
    v->direita = p;

    if (v->balanceamento == 1)
        p->balanceamento = -1;
    else
        p->balanceamento = 0;

    if (v->balanceamento == -1)
        u->balanceamento = 1;
    else
        u->balanceamento = 0;

    v->balanceamento = 0;

    return v; // retorna a nova raiz
}

NoAVL *rotacaoRL(NoAVL *p)
{
    NoAVL *u = p->direita;
    NoAVL *v = u->esquerda; // nó problema

    u->esquerda = v->direita;
    p->direita = v->esquerda;
    v->direita = u;
    v->esquerda = p;

    if (v->balanceamento == 1)
        u->balanceamento = -1;
    else
        u->balanceamento = 0;

    if (v->balanceamento == -1)
        p->balanceamento = 1;
    else
        p->balanceamento = 0;

    v->balanceamento = 0;

    return v; // retorna a nova raiz
}

int main()
{
    NoAVL *raiz = nullptr;

    return 0;
}
