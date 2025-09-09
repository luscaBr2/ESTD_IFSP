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

// Exibir em ordem (In-Order)
// mesma lógica da contagem
void EmOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esquerda);
        cout << raiz->valor << " - ";
        EmOrdem(raiz->direita);
    }
}

// Pré-ordem (pre-order): raiz → esquerda → direita
void PreOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->valor << " - ";
        PreOrdem(raiz->esquerda);
        PreOrdem(raiz->direita);
    }
}

// Pós-ordem (post-order): esquerda → direita → raiz
void PosOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        PosOrdem(raiz->esquerda);
        PosOrdem(raiz->direita);
        cout << raiz->valor << " - ";
    }
}

// FILA PARA USAR NA EXIBIÇÃO POR LARGURA
//==========================================
No *fila[6];
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

    for (int i = 0; i < 6; i++)
    {
        cout << fila[i]->valor << " - ";
        if (fila[i]->esquerda != nullptr)
            enfileirar(fila[i]->esquerda);

        if (fila[i]->direita != nullptr)
            enfileirar(fila[i]->direita);

        desenfileirar();
    }
}

void RemoverRecursivo(No *&raiz, int valor)
{
    if (raiz == nullptr)
    {
        cout << "Valor não encontrado!" << endl;
        return;
    }
    if (valor < raiz->valor)
        RemoverRecursivo(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        RemoverRecursivo(raiz->direita, valor);
    else
    {
        No *aux = raiz;
        if (raiz->direita == nullptr && raiz->esquerda == nullptr)
        {
            delete aux;
        }
        else if (raiz->esquerda == nullptr)
        {
            raiz = raiz->direita;
        }
        else if (raiz->direita == nullptr)
        {
            raiz = raiz->esquerda;
        }
        else
        {
            No *sucessor = raiz->direita;
            while (sucessor->esquerda != nullptr)
            {
                sucessor = sucessor->esquerda;
            }
            raiz->valor = sucessor->valor;
            RemoverRecursivo(raiz->direita, sucessor->valor);
        }
    }
}

// Busca o nó na árvore e armazena o nó e seu pai, caso não encontrar armazena nulo.
void BuscaAuxiliar(int valorProcurado, No *&noPai, No *&noProcurado, No *raiz)
{
    No *atual = raiz; // Começa a busca pela raiz da árvore.
    noPai = nullptr;
    bool valorEncontrado = false;

    // Percorre a árvore enquanto não encontrar o valor ou chegar ao final.
    // chegar no final -> atual = nullptr
    while (atual != nullptr && valorEncontrado == false)
    {
        noPai = atual; // Atualiza o ponteiro do pai para o nó atual.

        if (valorProcurado == atual->valor)
            valorEncontrado = true;
        else
        {
            // Decide para qual lado da árvore ir, conforme o valor procurado.
            if (valorProcurado < atual->valor)
                atual = atual->esquerda; // Vai para a subárvore esquerda.
            else
                atual = atual->direita; // Vai para a subárvore direita.
        }
    }

    if (valorEncontrado)
        noProcurado = atual;
    else
        noProcurado = nullptr;
}

// Remove um nó da árvore binária de busca de forma iterativa.
void RemoverIterativo(No *&raiz, int valor)
{
    No *noPai = nullptr;
    No *noProcurado = nullptr;
    BuscaAuxiliar(valor, noPai, noProcurado, raiz); // Busca o nó e seu pai.

    // Se o nó não foi encontrado, informa ao usuário e retorna.
    if (noProcurado == nullptr)
    {
        cout << "Valor não encontrado!" << endl;
        return;
    }

    // Caso 1: Nó folha (sem filhos).
    if (noProcurado->esquerda == nullptr && noProcurado->direita == nullptr)
    {
        if (noPai == nullptr) // Se o nó é a raiz, atualiza a raiz para nullptr.
            raiz = nullptr;
        else if (noPai->esquerda == noProcurado) // Se o nó é filho à esquerda do pai.
            noPai->esquerda = nullptr;
        else // Se o nó é filho à direita do pai.
            noPai->direita = nullptr;

        delete noProcurado; // Libera a memória do nó removido.
    }
    // Caso 2: Nó com apenas um filho.
    else if (noProcurado->esquerda == nullptr || noProcurado->direita == nullptr)
    {
        // Seleciona o filho existente (esquerda ou direita).
        No *filho = (noProcurado->esquerda != nullptr) ? noProcurado->esquerda : noProcurado->direita;

        if (noPai == nullptr) // Se o nó é a raiz, atualiza a raiz para o filho.
            raiz = filho;
        else if (noPai->esquerda == noProcurado) // Se o nó é filho à esquerda do pai.
            noPai->esquerda = filho;
        else // Se o nó é filho à direita do pai.
            noPai->direita = filho;

        delete noProcurado; // Libera a memória do nó removido.
    }
    // Caso 3: Nó com dois filhos.
    else
    {
        // Encontrar o sucessor (menor valor à direita).
        No *sucessorPai = noProcurado;
        No *sucessor = noProcurado->direita;
        while (sucessor->esquerda != nullptr)
        {
            sucessorPai = sucessor;
            sucessor = sucessor->esquerda;
        }
        // Copia o valor do sucessor para o nó a ser removido
        noProcurado->valor = sucessor->valor;
        // Ajusta o ponteiro do pai do sucessor para pular o sucessor
        if (sucessorPai == noProcurado)
            sucessorPai->direita = sucessor->direita;
        else
            sucessorPai->esquerda = sucessor->direita;
        delete sucessor;
    }
}

int main()
{
    No *raiz = nullptr;

    inserir(5, raiz);
    inserir(3, raiz);
    inserir(4, raiz);
    inserir(9, raiz);
    inserir(8, raiz);
    inserir(10, raiz);

    cout << "Quantidade total de elementos: " << contagem(raiz);

    cout << "\nElementos em ordem: ";
    EmOrdem(raiz);

    cout << "\nElementos em pre-ordem: ";
    PreOrdem(raiz);

    cout << "\nElementos em pos-ordem: ";
    PosOrdem(raiz);

    cout << "\nElementos em Largura: ";
    exibirPorLargura(raiz);

    cout << "\nInsira o valor a ser removido: ";
    int valorRemovido;
    cin >> valorRemovido;
    RemoverIterativo(raiz, valorRemovido);

    cout << "\nElementos em Largura: ";
    exibirPorLargura(raiz);

    cout << "\nInsira o valor a ser removido: ";
    cin >> valorRemovido;
    RemoverIterativo(raiz, valorRemovido);

    cout << "\nElementos em Largura: ";
    exibirPorLargura(raiz);

    cout << "\nInsira o valor a ser buscado: ";
    int valorProcurado;
    cin >> valorProcurado;
    buscar(valorProcurado, raiz);

    return 0;
}