/*
A árvore deve ser inicializada contendo, em ordem de inserção, as letras do seu primeiro nome.
O programa deve receber como entrada uma palavra digitada pelo usuário.
As letras dessa palavra devem ser inseridas na árvore, considerando apenas as letras não repetidas.
Após todas as inserções, a árvore resultante deve ser exibida em percurso em largura (nível a nível).
*/

#include <iostream>
#include <string>

using namespace std;

struct No
{
    char valor;
    No *esquerda;
    No *direita;
    int balanceamento;
};

// retorna a altura de um nó
int altura(No *n)
{
    if (!n)
        return 0;
    int ae = altura(n->esquerda);
    int ad = altura(n->direita);
    return 1 + (ae > ad ? ae : ad);
}

// retorna o fator de balanceamento de um nó
int calculaBalanceamento(No *n)
{
    if (!n)
        return 0;
    int ae = altura(n->esquerda);
    int ad = altura(n->direita);
    return ae - ad;
}

No *rotacaoDireita(No *y)
{
    No *x = y->esquerda;
    No *T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    y->balanceamento = calculaBalanceamento(y);
    x->balanceamento = calculaBalanceamento(x);
    return x;
}

No *rotacaoEsquerda(No *x)
{
    No *y = x->direita;
    No *T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    x->balanceamento = calculaBalanceamento(x);
    y->balanceamento = calculaBalanceamento(y);
    return y;
}

// verifica se um valor ja existe
bool contem(No *raiz, char valor)
{
    if (!raiz) // se a raiz for nula, a arvore não existe, então retorna falso
        return false;
    if (valor == raiz->valor)
        return true;
    if (valor < raiz->valor)
        return contem(raiz->esquerda, valor);
    return contem(raiz->direita, valor);
}

No *novoNo(char valor)
{
    No *n = new No;
    n->valor = valor;
    n->esquerda = nullptr;
    n->direita = nullptr;
    n->balanceamento = 0;
    return n;
}

No *inserir(No *raiz, char valor)
{
    if (!raiz) // se a raiz for nula, insere o novo nó aqui e retorna para ser a nova raiz
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    else
        return raiz; // Valor já existe, não insere

    raiz->balanceamento = calculaBalanceamento(raiz);

    // casos de balanceamento

    // Rotação Esquerda
    if (raiz->balanceamento < -1 && valor > raiz->direita->valor)
        return rotacaoEsquerda(raiz);

    // Rotação Direita
    if (raiz->balanceamento > 1 && valor < raiz->esquerda->valor)
        return rotacaoDireita(raiz);

    // Rotação Esquerda-Direita
    if (raiz->balanceamento > 1 && valor > raiz->esquerda->valor)
    {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Rotação Direita-Esquerda
    if (raiz->balanceamento < -1 && valor < raiz->direita->valor)
    {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void imprimeNivel(No *raiz, int nivel)
{
    if (!raiz)
        return;
    if (nivel == 0)
        cout << raiz->valor << " ";
    else
    {
        imprimeNivel(raiz->esquerda, nivel - 1);
        imprimeNivel(raiz->direita, nivel - 1);
    }
}

// retorna a altura máxima da árvore
int alturaMax(No *raiz)
{
    if (!raiz)
        return 0;
    int ae = alturaMax(raiz->esquerda);
    int ad = alturaMax(raiz->direita);
    return 1 + (ae > ad ? ae : ad);
}

// Percorre a árvore em largura
void percursoLargura(No *raiz)
{
    int h = alturaMax(raiz);
    for (int i = 0; i < h; ++i)
        imprimeNivel(raiz, i);
    cout << endl;
}

int main()
{
    string nome = "lucas";
    No *raiz = nullptr;

    for (char c : nome)
    {
        if (!contem(raiz, c))
            raiz = inserir(raiz, c);
    }

    cout << "Digite uma palavra: ";
    string palavra;
    cin >> palavra;

    for (char c : palavra)
    {
        if (!contem(raiz, c))
            raiz = inserir(raiz, c);
    }

    cout << "Percurso em largura: ";
    percursoLargura(raiz);

    return 0;
}