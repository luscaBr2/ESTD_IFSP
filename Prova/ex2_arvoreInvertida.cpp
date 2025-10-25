#include <iostream>
using namespace std;

struct No
{
    char chave;
    No *dir;
    No *esq;
};

No *fila[100];
int inicio = 0;
int fim = 0;

void Enfileirar(No *valor)
{
    if (fim == 100)
    {
        cout << "Fila cheia!!" << endl;
        return;
    }

    fila[fim] = valor;
    fim++;
}

void Desenfileirar()
{
    if (inicio == fim)
    {
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}

void Inserir(char chave, No *&raiz)
{
    if (raiz == nullptr)
    {
        raiz = new No;
        raiz->chave = chave;
        raiz->dir = nullptr;
        raiz->esq = nullptr;
    }
    else if (chave > raiz->chave)
        Inserir(chave, raiz->esq);
    else
        Inserir(chave, raiz->dir);
}

bool Buscar(char chave, No *raiz)
{
    if (raiz == nullptr)
    {
        return false;
    }
    else if (raiz->chave == chave)
    {
        return true;
    }
    else if (chave > raiz->chave)
        Buscar(chave, raiz->esq);
    else
        Buscar(chave, raiz->dir);
}

void EmOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave << " - ";
        EmOrdem(raiz->dir);
    }
}

int Contagem(No *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
    {
        return Contagem(raiz->esq) + 1 + Contagem(raiz->dir);
    }
}

void Largura(No *raiz)
{
    Enfileirar(raiz);

    for (int i = 0; i < Contagem(raiz); i++)
    {
        cout << fila[i]->chave << " - ";
        if (fila[i]->esq != nullptr)
            Enfileirar(fila[i]->esq);
        if (fila[i]->dir != nullptr)
            Enfileirar(fila[i]->dir);
        Desenfileirar();
    }
}

int main(int argc, char const *argv[])
{
    No *raiz = nullptr;
    Inserir('I', raiz);
    Inserir('G', raiz);
    Inserir('O', raiz);
    Inserir('R', raiz);

    string palavra;
    cin >> palavra;

    for (char c : palavra)
    {
        if (!Buscar(c, raiz))
            Inserir(c, raiz);
    }

    Largura(raiz);
    cout << endl;

    EmOrdem(raiz);
    cout << endl;

    return 0;
}
