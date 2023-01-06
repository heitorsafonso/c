#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 30

using namespace std;

void inserir (int p[], int *t, int e){
    *t = *t+1;
    p[*t] = e;
}

void retirar (int p[], int *t){
    *t = *t-1; 
}

void imprimir (int p[], int t){
    for (int i=t; i>=0; i--)
        cout << "\n" << p[i];
    cout << "\n\n\n";
}

int main(){
    char expressao[MAX], parenteses = '(', parentese_invertido = ')';
    int i, tamanho, op, topo, cont=0;
    int pilha[MAX];

    do{
        system ("cls");
        cout << "* * * * * VALIDACAO DE FUNCAO * * * * *\n\n\n";
        cout << "\n1 - Inserir expressao";
        cout << "\n0 - Finalizar programa";
        cout << "\n\nDigite a opcao: ";
        cin >> op;

        if (op == 1){
            system ("cls");
            cout << "* * * * * Funcao * * * * *\n\n\n";
            cout << "Digite uma expressao: ";
            cin >> (expressao);
            tamanho = strlen(expressao);

            for (i=0; i<tamanho; i++){
                if (expressao[i] == parenteses)
                    inserir (pilha, &topo, parenteses);
                if (expressao[i] == parentese_invertido && topo != 0)
                    retirar (pilha, &topo);
                if (expressao[i] == parentese_invertido && topo == 0)
                    cont++;
            }

            system ("cls");
            cout << "* * * * * * * * * * * * * * * * *\n\n\n";
            if (topo==0 && cont == 0)
                for (i=0; i<tamanho; i++)
                    cout << expressao[i];
            else
                cout << "Expressao invalida!\n";
            cout << topo;
            cout << "\n\n\n";
            cout << "* * * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        }
    }while(op!=0);
    return 0;
}