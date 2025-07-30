#include <iostream>
#include <stdlib.h> // para limpar a tela

using namespace std;

void inserirNotas(float notas[]){ 
    cout << "Quantas notas deseja cadastrar (max 10)? ";
    
    
    uint16_t qtdMax = 0;

    do{
        cin >> qtdMax;
        if(qtdMax > 10) cout << "Insira um valor menor que 10" << endl;
    } while (qtdMax > 10);

    for (uint16_t i = 0; i < qtdMax; i++)
    {
       cout << "Insira a " << (i+1) << "o nota:";
       cin >> notas[i];
       cin.ignore(80, '\n');

       cout << endl;
    }

    cout << endl;
    
    return;
}

void exibirNotas(float notas[]) {

    for (uint16_t i = 0; i < 10; i++)
        cout << "Nota[" << (i+1) << "] = " << notas[i] << endl;
    
    cout << endl << endl;
    
    return;
}

void calcularMedia(float notas[]) {
    float somatorio = 0, quantidade = 0;

    for (uint16_t i = 0; i < 10; i++){
        somatorio += notas[i];
        quantidade += 1;
    }

    float media = somatorio / quantidade;

    cout << "Media de notas dos alunos = " << media;
    cout << endl << endl;
    return;
}

void maiorEmenorNota(float notas[]) {
    // inicializa maior e menor com o primeiro elemento
    float maior = notas[0];
    float menor = notas[0];

    // percorre o array a partir do segundo elemento
    for (int i = 1; i < 10; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    cout << "Maior nota: " << maior << endl;
    cout << "Menor nota: " << menor << endl;
    cout << endl << endl;
    return;
}

void limparTela(){
    cout << endl << "Pressione qualquer tecla para continuar";
    cin.get();
    system("cls");
}

int main() {
    float notas[10] = {0,0,0,0,0,0,0,0,0,0};

    int opcao;

    do{
        cout << "===== MENU ===== " << endl;
        cout << "1 - Inserir notas" << endl;
        cout << "2 - Exibir todas as notas" << endl;
        cout << "3 - Calcular e exibir a media geral da turma" << endl;
        cout << "4 - Mostrar a maior e a menor nota" << endl;
        cout << "5 - Sair" << endl;

        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(80, '\n'); // limpa o buffer 

        switch (opcao)
        {
        case 1:
            inserirNotas(notas);
            limparTela();
            break;
        case 2: 
            exibirNotas(notas);
            limparTela();
            break;
        case 3:
            calcularMedia(notas);
            limparTela();
            break;
        case 4:
            maiorEmenorNota(notas);
            limparTela();
            break;

        default:
            break;
        }

    } while (opcao != 5);

    cout << "Saindo do programa...";
    cout << endl << endl;
    return 0;
}