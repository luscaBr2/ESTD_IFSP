#include <iostream>

using namespace std;

/*
não existe modo certo de remover, tudo depende do contexto
por exemplo, ao apagar uma pasta, todas as subpastas dentro dela serão apagadas (caso de apagar o nó e os seus filhos serem
apagados tambem)
*/

/*
outro exemplo, ao demitir um gerente que possui vários funcionarios atrelados a ele, os funcionarios
podem se manter, ser atrelados a outro gerente, um funcionario pode ser tornar um gerente, tudo depende do contexto
*/

struct No
{
    string valor;
    No *filho;
    No *irmao;
};

No *criarNo(string valor)
{
    No *novoNo = new No();
    novoNo->valor = valor;
    novoNo->filho = nullptr;
    novoNo->irmao = nullptr;

    return novoNo;
}

void exibirEmLinha(No *raiz)
{
    if (raiz == nullptr)
    {
        // cout << "";
        return;
    }

    // Em um delete onde ao excluir o pai excluisse os filhos, aqui entraria um delete deletando o nó que não possui filhos nem irmãos
    // if (raiz->filho->filho != nullptr && raiz->filho->irmao != nullptr) // esse if é só pro filho, tem que fazer pro irmao tbm
    //    delete raiz->filho;

    cout << raiz->valor << "(";

    if (raiz->filho != nullptr)
        exibirEmLinha(raiz->filho);

    cout << "), ";

    if (raiz->irmao != nullptr)
        exibirEmLinha(raiz->irmao);
}

No *buscar(No *raiz, string valor)
{
    if (raiz == nullptr)
        return nullptr;

    // valor encontrado
    if (raiz->valor == valor)
    {
        cout << "Valor encontrado" << endl;
        return raiz;
    }

    No *noEncontrado = buscar(raiz->filho, valor);

    if (noEncontrado != nullptr)
        return noEncontrado;

    return buscar(raiz->irmao, valor);
}

void inserir(No *raiz, string pai, string valor)
{
    No *noPai = buscar(raiz, pai);

    if (noPai == nullptr)
    {
        cout << "Pai inexistente" << endl;
    }

    No *novoNo = criarNo(valor);

    if (noPai->filho == nullptr)
    {
        noPai->filho = novoNo;
    }
    else
    {
        No *irmaoFinal = noPai->filho;
        while (irmaoFinal->irmao != nullptr)
        {
            irmaoFinal = irmaoFinal->irmao;
        }

        irmaoFinal->irmao = novoNo;
    }
}

int main()
{

    No *raiz = criarNo("8");

    exibirEmLinha(raiz);

    buscar(raiz, "Lucas");

    inserir(raiz, "8", "15");
    inserir(raiz, "8", "23");
    inserir(raiz, "8", "17");

    inserir(raiz, "15", "4");
    inserir(raiz, "15", "2");
    inserir(raiz, "15", "7");

    exibirEmLinha(raiz);

    return 0;
}