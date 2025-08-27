#include <iostream>

using namespace std;

struct No
{
    int valor;
    No *direita;
    No *esquerda;
};

void inserir(int novoValor, No *&raiz) // se usa *& quando vai alterar o valor da variavel apontada no ponteiro
{
    if (raiz == nullptr)
    {
        raiz = new No();
        raiz->valor = novoValor;
        raiz->direita = nullptr;
        raiz->esquerda = nullptr;
    }
    else if (novoValor < raiz->valor)
        inserir(novoValor, raiz->esquerda);
    else
        inserir(novoValor, raiz->direita);
}

void buscar(int valorProcurado, No *raiz) // mesmo lógica da inserção, porém com a condição de parada
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

int contagem(No *raiz)
{
    if (raiz == nullptr)
        return 0;
    else
    {
        return contagem(raiz->esquerda) + 1 + contagem(raiz->direita); // o 1 fixo é para contar a raiz atual + a sua esquerda + a sua direita
    }
}

int main()
{
    No *raiz = nullptr;

    for (int i = 0; i < 5; i++)
    {
        int novoValor;
        cin >> novoValor;

        inserir(novoValor, raiz);
    }

    cout << "Insira o valor a ser buscado: ";
    int valorProcurado;
    cin >> valorProcurado;

    buscar(valorProcurado, raiz);

    cout << "Quantidade total de elementos: " << contagem(raiz);

    return 0;
}