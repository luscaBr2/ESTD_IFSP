#include <iostream>
using namespace std;

// Estrutura de um nó da árvore AVL
struct NoAVL
{
    int chave;  // Valor armazenado no nó
    int fb;     // Fator de balanceamento do nó
    NoAVL *dir; // Ponteiro para o filho direito
    NoAVL *esq; // Ponteiro para o filho esquerdo
};

// Função para criar um novo nó AVL
NoAVL *CriarNo(int chave)
{
    NoAVL *novoNo = new NoAVL;
    novoNo->chave = chave;
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
    novoNo->fb = 0; // Inicialmente balanceado
    return novoNo;
}

NoAVL *RotacaoL(NoAVL *p)
{
    NoAVL *u = p->esq;

    if (u->fb == -1)
    {
        // Caso LR (Left-Right)
        NoAVL *v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        // Ajusta fatores de balanceamento após rotação LR
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

        cout << "Feita rotação LR";

        return v; // Novo nó raiz após rotação
    }

    // Caso LL (Left-Left)
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    cout << "Feita rotação LL";
    return u; // Novo nó raiz após rotação
}

// Rotação à direita para balancear a árvore (casos RR e RL)
NoAVL *RotacaoR(NoAVL *p)
{
    NoAVL *u = p->dir;

    if (u->fb == 1)
    {
        // Caso RL (Right-Left)
        NoAVL *v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        // Ajusta fatores de balanceamento após rotação RL
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

        cout << "Feita rotação RL";
        return v; // Novo nó raiz após rotação
    }

    // Caso RR (Right-Right)
    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    cout << "Feita rotação RR";
    return u; // Novo nó raiz após rotação
}

// Função para inserir um valor na árvore AVL
NoAVL *Inserir(NoAVL *&raiz, int chave, bool &cresceu)
{

    if (raiz == nullptr)
    {
        // Se a árvore está vazia, cria novo nó
        cresceu = true;
        raiz = CriarNo(chave);
    }

    else if (chave < raiz->chave)
    {
        // Insere no filho esquerdo
        Inserir(raiz->esq, chave, cresceu);
        if (cresceu)
        {
            // Atualiza fator de balanceamento
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == 1)
            {
                // Desbalanceamento à esquerda, faz rotação
                raiz = RotacaoL(raiz);
                cresceu = false;
            }
        }
    }
    else
    {
        // Insere no filho direito
        Inserir(raiz->dir, chave, cresceu);
        if (cresceu)
        {
            // Atualiza fator de balanceamento
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == -1)
            {
                // Desbalanceamento à direita, faz rotação
                raiz = RotacaoR(raiz);
                cresceu = false;
            }
        }
    }

    return raiz; // Retorna raiz (pode ser nova após rotação)
}

// Função para buscar um valor na árvore AVL
void Buscar(int chave, NoAVL *raiz)
{
    if (raiz == nullptr)
    {
        cout << "Valor não encontrado!" << endl;
    }
    else if (raiz->chave == chave)
    {
        cout << "Valor encotrado!" << endl;
    }
    else if (chave < raiz->chave)
        Buscar(chave, raiz->esq); // Busca no filho esquerdo
    else
        Buscar(chave, raiz->dir); // Busca no filho direito
}

// Percurso em ordem (esquerda, raiz, direita)
void EmOrdem(NoAVL *raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave << " - ";
        EmOrdem(raiz->dir);
    }
}

int main()
{
    NoAVL *raiz = nullptr; // Ponteiro para raiz da árvore

    bool cresceu = false; // Indica se a árvore cresceu após inserção

    // prontuario 3032116
    Inserir(raiz, 30, cresceu);
    Inserir(raiz, 32, cresceu);
    Inserir(raiz, 11, cresceu);

    // dia nascimento
    Inserir(raiz, 2, cresceu);

    // mes nascimento
    Inserir(raiz, 6, cresceu);

    // ano nascimento
    Inserir(raiz, 20, cresceu);
    Inserir(raiz, 04, cresceu);

    cout << "Inserções iniciais: ";
    EmOrdem(raiz);

    int novoValor;
    do
    {
        cout << "Insira um novo valor inteiro(-1 para encerrar): ";
        cin >> novoValor;
        cout << endl;
        if (novoValor != -1)
            Inserir(raiz, novoValor, cresceu);

    } while (novoValor != -1);

    return 0;
}