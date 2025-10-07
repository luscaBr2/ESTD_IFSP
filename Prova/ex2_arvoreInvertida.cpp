#include <iostream>

using namespace std;

struct No
{
    char valor;
    No *direita;
    No *esquerda;
};

bool letraExiste = false;

void buscar(char valorProcurado, No *raiz) // edita a var global letraExiste
{
    if (raiz == nullptr)                    // condição de parada, ja que não há o que pesquisar se a raiz é nula
        letraExiste = false;                // cout << "Valor NAO encontrado" << endl;
    else if (valorProcurado == raiz->valor) // condição de parada, não precisa continuar quando achar o elemento
        letraExiste = true;                 // cout << "Valor encontrado" << endl;
    else if (valorProcurado > raiz->valor)
        buscar(valorProcurado, raiz->esquerda);
    else
        buscar(valorProcurado, raiz->direita);
}

void inserir(char novoValor, No *&raiz)
{
    letraExiste = false;     // reseta
    buscar(novoValor, raiz); // vai editar a var global pra ser usada depois

    if (raiz == nullptr)
    {
        raiz = new No();

        // verifica se ja existe
        //  se a letra não estiver presente, insira
        if (!letraExiste)
        {
            raiz->valor = novoValor;
            raiz->direita = nullptr;
            raiz->esquerda = nullptr;
        }
    }
    else if (novoValor < raiz->valor)
        inserir(novoValor, raiz->direita);
    else
        inserir(novoValor, raiz->esquerda);
}

void EmOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esquerda);
        cout << raiz->valor << " - ";
        EmOrdem(raiz->direita);
    }
}

// FILA PARA USAR NA EXIBIÇÃO POR LARGURA
//==========================================
No *fila[26];
int inicio = 0;
int fim = 0;

void enfileirar(No *no)
{
    if (fim == 100)
        return;

    fila[fim] = no;

    fim++;
}

void desenfileirar()
{
    if (inicio == fim)
    {
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}

// ====================================

void exibirPorLargura(No *raiz)
{
    enfileirar(raiz);

    for (int i = 0; i < 26; i++)
    {
        cout << fila[i]->valor << " - ";
        if (fila[i]->esquerda != nullptr)
            enfileirar(fila[i]->esquerda);

        if (fila[i]->direita != nullptr)
            enfileirar(fila[i]->direita);

        desenfileirar();
    }
}

int main()
{
    No *raiz = new No();

    for (char letra : "lucas aparecido dos santos")
        inserir(letra, raiz);

    EmOrdem(raiz);
    cout << endl;

    exibirPorLargura(raiz);
    cout << endl;

    cout << "Entre com uma palavra" << endl;
    string palavra;

    for (char letra : palavra)
        inserir(letra, raiz);

    EmOrdem(raiz);
    cout << endl;

    exibirPorLargura(raiz);
    cout << endl;

    return 0;
}