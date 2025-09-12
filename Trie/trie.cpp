#include <iostream>

using namespace std;

struct No
{
    No *filhos[26];
    string significado;
};

/*
Forma dinamica de fazer
struct No
{
    No *filho;
    No *irmao;
    char letra;
    string significado; // onde houver significado, é uma palavra
};
*/

No *criarNo()
{
    No *novoNo = new No();
    novoNo->significado = nullptr;
    for (No *filho : novoNo->filhos)
    {
        filho = nullptr;
    }

    return novoNo;
}

int main()
{
    No *raiz = criarNo();
    return 0;
}
