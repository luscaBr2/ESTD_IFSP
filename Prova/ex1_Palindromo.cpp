#include <iostream>
#include <string>

using namespace std;

struct No
{
    char valor;
    No *proximo;
    No *anterior;
};

void InserirFim(No *&cabeca, char valor)
{
    No *novoNo = new No{valor, nullptr, nullptr};

    if (cabeca == nullptr)
        cabeca = novoNo;
    else
    {
        No *aux = cabeca;
        while (aux->proximo != nullptr)
        {
            aux = aux->proximo;
        }
        novoNo->anterior = aux;
        aux->proximo = novoNo;
    }
}

void ExibirLista(const No *cabeca)
{
    const No *aux = cabeca;
    while (aux != nullptr)
    {
        cout << aux->valor << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

bool ePalindromo(No *cabeca)
{
    if (cabeca == nullptr)
        return false;

    No *fim = cabeca;
    while (fim->proximo != nullptr)
    {
        fim = fim->proximo;
    }

    No *inicio = cabeca;
    while (inicio != fim)
    {
        if (inicio->valor != fim->valor)
        {
            return false;
        }
        inicio = inicio->proximo;
        fim = fim->anterior;
    }
    return true;
}

int main()
{
    No *cabeca = nullptr;

    string palavra;
    cin >> palavra;

    for (char c : palavra)
    {
        InserirFim(cabeca, c);
    }

    if (ePalindromo(cabeca))
    {
        cout << "A palavra e um palindromo." << endl;
    }
    else
    {
        cout << "A palavra nao e um palindromo." << endl;
    }

    return 0;
}
