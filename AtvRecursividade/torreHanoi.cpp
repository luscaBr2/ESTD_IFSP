// enunciado: https://judge.beecrowd.com/pt/problems/view/1166

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool quadrado(int x) // verifica se um numero é quad perfeito
{
    int r = sqrt(x);
    return r * r == x; // retorna true se x for quad perfeito
}

int jogar(vector<int> &hastes, int bola)
{
    // Percorre todas as hastes para tentar encaixar a bola
    for (int i = 0; i < hastes.size(); i++)
    {
        // se a haste estiver vazia (0) ou a soma da bola atual com o topo da haste for quadrado perfeito
        if (hastes[i] == 0 || quadrado(hastes[i] + bola))
        {
            hastes[i] = bola; // coloca a bola nessa haste
            return jogar(hastes, bola + 1);
        }
    }

    // só chega aqui se não for possível colocar a bola em nenhuma haste, retornando -1 e assim acabando o jogo
    return bola - 1;
}

int main()
{
    int t, n;
    cin >> t;   // numero de casos de teste
    while (t--) // vai decrementando até ficar zero, deu zero saiu do while
    {
        cin >> n;                 // numero de hastes
        vector<int> hastes(n, 0); // hastes ja iniciam com zero

        cout << jogar(hastes, 1) << "\n"; // inicia com 1 para começar a jogar do 1 pra frente
    }
}
