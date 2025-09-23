
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

int main()
{
    NoAVL *raiz = nullptr;

    return 0;
}
