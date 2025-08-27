#include <iostream>

using namespace std;

int fila[4];
int inicio = 0;
int fim = 0;

void enfileirar(int valor)
{
    if (fim == 4)
    {
        cout << "Fila cheia (tentou inserir o " << valor << ")" << endl;
        return;
    }

    fila[fim] = valor;
    fim++;
}

void exibirFila()
{
    for (int i = 0; i < 4; i++)
        if (i >= inicio)
            cout << fila[i] << " ";

    cout << endl;
}

void remover()
{
    inicio++;
}

int main()
{
    enfileirar(3);
    exibirFila();

    enfileirar(4);
    exibirFila();

    enfileirar(5);
    exibirFila();

    enfileirar(6);
    exibirFila();

    enfileirar(7); // deve estar cheia
    exibirFila();

    remover();
    exibirFila();

    remover();
    exibirFila();

    remover();
    exibirFila();

    remover();
    exibirFila();

    remover(); // deve estar vazia
    exibirFila();

    return 0;
}