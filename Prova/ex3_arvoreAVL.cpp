#include <iostream>
#include <string>
using namespace std;

struct NoAVL
{
    int chave;
    int fb;
    NoAVL *dir;
    NoAVL *esq;
};

string rotacoes = "";
bool mostrarInserir = false;
bool mostrarBuscar = false;

NoAVL *CriarNo(int chave)
{
    NoAVL *novoNo = new NoAVL;
    novoNo->chave = chave;
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
    novoNo->fb = 0;
    return novoNo;
}

bool Buscar(int chave, NoAVL *raiz)
{
    if (mostrarBuscar)
        cout << raiz->chave << " - ";

    if (raiz == nullptr)
    {
        return false;
    }
    else if (raiz->chave == chave)
    {
        return true;
    }
    else if (chave < raiz->chave)
        Buscar(chave, raiz->esq);
    else
        Buscar(chave, raiz->dir);
}

int Contagem(NoAVL *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
    {
        return Contagem(raiz->esq) + 1 + Contagem(raiz->dir);
    }
}

NoAVL *fila[100];
int inicio = 0;
int fim = 0;

void Enfileirar(NoAVL *valor)
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

void Largura(NoAVL *raiz)
{
    Enfileirar(raiz);

    for (int i = 0; i < Contagem(raiz); i++)
    {
        cout << fila[i]->chave << " - " << "(fb: " << fila[i]->fb << ") ";
        if (fila[i]->esq != nullptr)
            Enfileirar(fila[i]->esq);
        if (fila[i]->dir != nullptr)
            Enfileirar(fila[i]->dir);
        Desenfileirar();
    }
}

bool FilaVazia()
{
    return inicio == fim;
}

NoAVL *PrimeiroFila()
{
    if (!FilaVazia())
        return fila[inicio];
    return nullptr;
}

void LarguraNivel(NoAVL *raiz)
{
    if (raiz == nullptr)
        return;

    int nivel = 0;
    cout << "Nível " << nivel << ": ";

    Enfileirar(raiz);
    Enfileirar(nullptr); // marcador de fim de nível

    while (!FilaVazia())
    {
        NoAVL *no = PrimeiroFila(); // obtém o nó da frente
        Desenfileirar();

        if (no == nullptr) // fim de um nível
        {
            if (!FilaVazia()) // ainda há nós
            {
                nivel++;
                cout << "\nNível " << nivel << ": ";
                Enfileirar(nullptr); // marca o fim do próximo nível
            }
        }
        else
        {
            cout << no->chave << " (FB=" << no->fb << ")";

            // coloca vírgula se o próximo não for nulo (ainda no mesmo nível)
            if (!FilaVazia() && PrimeiroFila() != nullptr)
                cout << ", ";

            if (no->esq != nullptr)
                Enfileirar(no->esq);
            if (no->dir != nullptr)
                Enfileirar(no->dir);
        }
    }

    cout << endl;
}

NoAVL *RotacaoL(NoAVL *p)
{
    NoAVL *u = p->esq;

    if (u->fb == -1)
    {
        /* Rotação LR */
        NoAVL *v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if (v->fb == 1)
        {
            u->fb = 0;
            p->fb = -1;
        }
        else if (v->fb == -1)
        {
            u->fb = 1;
            p->fb = 0;
        }
        else
        {
            u->fb = 0;
            p->fb = 0;
        }

        v->fb = 0;
        rotacoes += "LR ";
        return v;
    }

    /* Rotação LL */
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    rotacoes += "LL ";
    return u;
}

NoAVL *RotacaoR(NoAVL *p)
{
    NoAVL *u = p->dir;

    if (u->fb == 1)
    {
        /* Rotação RL */
        NoAVL *v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->fb == 1)
        {
            p->fb = 0;
            u->fb = -1;
        }
        else if (v->fb == -1)
        {
            p->fb = 1;
            u->fb = 0;
        }
        else
        {
            p->fb = 0;
            u->fb = 0;
        }

        v->fb = 0;
        rotacoes += "RL ";
        return v;
    }

    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    rotacoes += "RR ";
    return u;
}

NoAVL *Inserir(NoAVL *&raiz, int chave, bool &cresceu)
{
    if (mostrarInserir && raiz != nullptr)
        cout << raiz->chave << " - ";

    if (raiz == nullptr)
    {
        cresceu = true;
        raiz = CriarNo(chave);
    }

    else if (chave < raiz->chave)
    {
        Inserir(raiz->esq, chave, cresceu);
        if (cresceu)
        {
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == 1)
            {
                raiz = RotacaoL(raiz);
                cresceu = false;
            }
        }
    }
    else
    {
        Inserir(raiz->dir, chave, cresceu);
        if (cresceu)
        {
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == -1)
            {
                raiz = RotacaoR(raiz);
                cresceu = false;
            }
        }
    }

    return raiz;
}

int main()
{
    NoAVL *raiz = nullptr;

    bool cresceu = false;
    Inserir(raiz, 26, cresceu);
    Inserir(raiz, 73, cresceu);
    Inserir(raiz, 98, cresceu);
    Inserir(raiz, 25, cresceu);
    Inserir(raiz, 11, cresceu);
    Inserir(raiz, 19, cresceu);
    // Inserir (raiz, 98, cresceu);

    mostrarInserir = true;

    int valor;
    while (true)
    {
        cin >> valor;

        rotacoes = "";
        if (!Buscar(valor, raiz))
        {
            cout << "Inserindo " << valor << endl;
            cout << "Caminho antes da inserção: " << endl;
            Inserir(raiz, valor, cresceu);
            cout << endl;
            cout << "Rotações: " << rotacoes << endl;
            cout << "Caminho após a inserção: " << endl;
            mostrarBuscar = true;
            Buscar(valor, raiz);
            mostrarBuscar = false;
            cout << endl;
            cout << "Árvore em largura:" << endl;
            inicio = 0;
            fim = 0;
            LarguraNivel(raiz);
            cout << endl;
        }
    }

    return 0;
}
