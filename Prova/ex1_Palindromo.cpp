#include <iostream>

using namespace std;

struct No
{
    char letra;
    No *prox;
    No *anterior;
};

void inserirFim(No *cabeca, char valor)
{
    No *novoNo = new No{valor, nullptr, nullptr};

    if (cabeca == nullptr)
        cabeca = novoNo;
    else
    {
        No *aux = cabeca;
        while (aux->prox != nullptr)
            aux = aux->prox;

        aux->prox = novoNo;
    }
}

void inserirInicio(No *calda, char valor)
{
    No *novoNo = new No{valor, nullptr, nullptr};

    if (calda == nullptr)
        calda = novoNo;
    else
    {
        No *aux = calda;
        while (aux->anterior != nullptr)
            aux = aux->anterior;

        aux->anterior = novoNo;
    }
}

void ExibirLista(const No *comeco)
{
    const No *aux = comeco;
    while (aux != nullptr)
    {
        cout << aux->letra << " ";
        aux = aux->prox;
    }

    cout << endl;
}

string FormaPalavraFrente(No *cabeca)
{
    string palavraFormada = "";

    No *atual = cabeca;
    while (atual)
    {
        palavraFormada += atual->letra;
        atual = atual->prox;
    }

    return palavraFormada;
}

string FormaPalavraCostas(No *calda)
{
    No *atual = calda;
    string palavraFormada = "";

    while (atual)
    {
        palavraFormada += atual->letra;
        atual = atual->anterior;
    }

    return palavraFormada;
}

int main()
{
    cout << "Insira uma palavra com um total de letras impares: ";
    string palavra;
    cin >> palavra;

    No *cabeca = nullptr;
    No *calda = nullptr;

    // insere normalmente
    for (char letra : palavra)
        inserirFim(cabeca, letra);

    cout << cabeca->letra;

    // insere de traz pra frente
    for (char letra : palavra)
        inserirInicio(calda, letra);

    if (FormaPalavraCostas(calda) == FormaPalavraFrente(cabeca))
        cout << "é um palindromo";
    else
        cout << "Não é um palindromo";

    return 0;
}