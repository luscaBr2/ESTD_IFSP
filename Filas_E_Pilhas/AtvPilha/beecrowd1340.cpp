#include <iostream>

using namespace std;

int tamanho;

int inicioFila = 0;
int fimFila = 0;
bool provavelFila = true;

int inicioPilha = 0;
int fimPilha = 0;
bool provavelPilha = true;

int inicioFilaPrioridade = 0;
int fimFilaPrioridade = 0;
bool provavelFilaPrioridade = true;

void inserirFila(int valor, int *fila)
{
    fila[fimFila] = valor;
    fimFila++;
}

void removerFila()
{
    inicioFila++;
}

void inserirPilha(int valor, int *pilha)
{
    pilha[fimPilha] = valor;
    fimPilha++;
}

void removerPilha()
{
    fimPilha--;
}

void inserirFilaPrioridade(int valor, int *filaPrioridade)
{
    filaPrioridade[fimFilaPrioridade] = valor;
    fimFilaPrioridade++;
}

void removerFilaPrioridade(int *filaPrioridade)
{
    int maior = 0;

    for (int i = inicioFilaPrioridade; i < fimFilaPrioridade; i++) {
        if (filaPrioridade[i] > filaPrioridade[maior]) {
            maior = i;
        }
    }
    filaPrioridade[maior] = -1;
}

void compararVetores(int *fila, int *pilha, int *filaPrioridade)
{
}

int main()
{
    cin >> tamanho;

    int *fila = new int[tamanho];
    int *pilha = new int[tamanho];
    int *filaPrioridade = new int[tamanho];

    int tentativas;
    cin >> tentativas;

    for (int i = 0; i < tentativas; i++)
    {
        int operacao;
        int parametro;
        cin >> operacao >> parametro;

        switch (operacao)
        {
        case 1:
            // insere em todos os 3 passando os parametros

            break;
        case 2:
            // remove em todos os 3

            break;
        }
    }

    return 0;
}