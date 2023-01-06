#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

using namespace std;

int inserir (int p[], int *t, int e){
    if (*t > (MAX-2))
        return 1;
    
    else{
        *t = *t+1;
        p[*t] = e;
        return 0;
    }
}

int retirar (int p[], int *t){
    if (*t < 0)
        return 1;
    
    else{
        *t = *t-1;
        return 0;
    }
}

void imprimir (int p[], int t){
    for (int i=t; i>=0; i--)
        cout << "\n" << p[i];
    cout << "\n\n\n";
}

int main(){
    int pilha[MAX];
    int topo, op, elemento, flag;

    topo = -1;

    do{
        system("cls");
        cout << "* * * * * M E N U * * * * *\n\n\n";
        cout << "\n1 - Inserir";
        cout << "\n2 - Retirar";
        cout << "\n3 - Imprimir";
        cout << "\n9 - Sair";
        cout << "\n\nDigite a sua opcao: ";
        cin >> op;

        switch (op){
            case 1: system("cls");
                cout << "* * * * * Inserir * * * * *\n\n\n";
                cout << "Digite um numero inteiro: ";
                cin >> elemento;

                flag = inserir (pilha, &topo, elemento);

                if (flag == 0)
                    cout << "\n\nElemento inserido com sucesso!\n\n";
                
                else
                    cout << "\n\nImpossivel inserir...\nPilha cheia!\n\n";
                
                system("pause");
                break;
            
            case 2: system("cls");
                cout << "* * * * * Retirar * * * * *\n\n\n";

                flag = retirar (pilha, &topo);

                if (flag==0)
                    cout << "\nElemento removido com sucesso!\n\n";
                
                else
                    cout << "\nImpossivel remover...\nPilha vazia\n\n";
                
                system("pause");
                break;

            case 3: system("cls");
                cout << "* * * * * PILHA * * * * *\n\n\n";

                if (topo < 0)
                    cout << "\n\nPilha vazia\n\n";
                
                else
                    imprimir(pilha, topo);
                
                system("pause");
                break;
        }
    }while(op!=9);
}