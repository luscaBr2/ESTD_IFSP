// Exercício 1 – Árvore AVL de Letras

// Implemente um programa que trabalhe com árvores AVL da seguinte forma:
    
    // A árvore deve ser inicializada contendo, em ordem de inserção, as letras do seu primeiro nome.
    // O programa deve receber como entrada uma palavra digitada pelo usuário.
    // As letras dessa palavra devem ser inseridas na árvore, considerando apenas as letras não repetidas.
    // Após todas as inserções, a árvore resultante deve ser exibida em percurso em largura (nível a nível).

// Primeiro peguei o código base de uma árvore AVL, disponível no classroom, depois adaptei para fazer o que o exercício pede.
#include <iostream>
using namespace std;

struct NoAVL
{
    // Altere o tipo da chave para char
    char chave;
    int fb;
    NoAVL* dir;
    NoAVL* esq;
};

// Peguei o código base de uma ABB, disponível no classroom, para usar a função de percurso em largura.
NoAVL* fila[100]; // Aumentei o tamanho da fila para 100, para evitar problemas com muitas letras.
int inicio = 0;
int fim = 0;

void Enfileirar(NoAVL* valor){
    if (fim == 100)
    {
        cout << "Fila cheia!!" << endl;
        return;
    }
    
    fila[fim] = valor;
    fim++; 
}

void Desenfileirar(){
    if (inicio == fim){
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}

// Ajustei a função Largura para percorrer a lista maior
void Largura(NoAVL* raiz){
    if (!raiz) return;

    inicio = 0;
    fim = 0;
    Enfileirar(raiz);

    while (inicio < fim){
        NoAVL* atual = fila[inicio];
        inicio++;

        cout << atual->chave << " - ";

        if (atual->esq) Enfileirar(atual->esq);
        if (atual->dir) Enfileirar(atual->dir);
    }
}

// Ajustei a função CriarNo para o tipo char
NoAVL* CriarNo(char chave){
    NoAVL* novoNo = new NoAVL;
    novoNo->chave = chave;
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
    novoNo->fb = 0;
    return novoNo;
}

NoAVL* RotacaoL(NoAVL* p){
    NoAVL* u = p->esq;

    if (u->fb == -1)
    {
        /* Rotação LR */
        NoAVL* v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if (v->fb == 1) {
            u->fb = 0;
            p->fb = -1;
        } else if (v->fb == -1) {
            u->fb = 1;
            p->fb = 0;
        } else {
            u->fb = 0;
            p->fb = 0;
        }

        v->fb = 0;

        return v;
    }

    /* Rotação LL */
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;

    return u;
}

NoAVL* RotacaoR(NoAVL* p){
    NoAVL* u = p->dir;

    if (u->fb == 1)
    {
        /* Rotação RL */
        NoAVL* v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->fb == 1) {
            p->fb = 0;
            u->fb = -1;
        } else if (v->fb == -1) {
            p->fb = 1;
            u->fb = 0;
        } else {
            p->fb = 0;
            u->fb = 0;
        }

        v->fb = 0;

        return v;
    }

    /* Rotação RR */
    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;

    return u;
}

// Ajustei a função Inserir para o tipo char
NoAVL* Inserir (NoAVL*& raiz, char chave, bool& cresceu){

    if(raiz == nullptr){
        raiz = CriarNo(chave);
        cresceu = true;
        return raiz;
    }

    else if(chave < raiz->chave){
        Inserir (raiz->esq, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == 1) {
                raiz = RotacaoL (raiz);
                cresceu = false;
            }
        }
    }
    else {
        Inserir (raiz->dir, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == -1){
                raiz = RotacaoR (raiz);
                cresceu = false;
            }
        }
    }

    return raiz;
}

// Alterei a função Buscar para rerotnar um bool e usar char
bool Buscar (char chave, NoAVL* raiz){
    if (raiz == nullptr){
        return false;
    } 
    else if (raiz->chave == chave){
        return true;
    }   
    else if(chave < raiz->chave)
        return Buscar (chave, raiz->esq);
    else
        return Buscar (chave, raiz->dir);
}

int main()
{
    NoAVL* raiz = nullptr;
    bool cresceu = false;

    // Inicializa a árvore com as letras do nome "IGOR"
    Inserir (raiz, 'I', cresceu);
    Inserir (raiz, 'G', cresceu);
    Inserir (raiz, 'O', cresceu);
    Inserir (raiz, 'R', cresceu);

    // Recebe uma palavra do usuário
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;
    
    // Insere as letras da palavra na árvore, ignorando letras repetidas
    for (char letra : palavra) {
        if (!Buscar(toupper(letra), raiz)) // Verifica se a letra já está na árvore
        {
            // toupper para garantir que todas as letras sejam maiúsculas, como as do nome (opcional)
            Inserir(raiz, toupper(letra), cresceu);
        }
    }

    // Exibe a árvore em percurso em largura
    cout << "Árvore em percurso em largura: ";
    Largura(raiz);
    cout << endl;

    return 0;
}
