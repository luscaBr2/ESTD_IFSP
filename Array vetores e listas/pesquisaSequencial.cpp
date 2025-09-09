#include <iostream>

using namespace std;

int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int pesquisaFor(int n)
{
    for (size_t i = 0; i < 10; i++)
        if (n == vetor[i])
            return i;

    return -1;
}

int pesquisaForeach(int n)
{
    int i = 0;
    for (int elemento : vetor)
    {
        if (n == elemento)
            return i;

        i++;
    }

    return -1;
}

int main()
{

    int n;

    cout << "Entre um numero de 0 a 10: ";
    cin >> n;

    int buscaFor = pesquisaFor(n);

    if (buscaFor >= 0)
        cout << "O numero foi encontrado na posicao " << buscaFor << endl;
    else
        cout << "O numero nao foi encontrado" << endl;

    int buscaForeach = pesquisaForeach(n);

    if (buscaForeach >= 0)
        cout << "O numero foi encontrado na posicao " << buscaForeach << endl;
    else
        cout << "O numero nao foi encontrado" << endl;

    return 0;
}