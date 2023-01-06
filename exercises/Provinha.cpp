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

int main(){
    char expressao[MAX];
    char parenteses = '(', parentese_invertido = ')';
    char colchetes = '[', colchete_invertido = ']';
    int i, tamanho, topo=0;
    int pilha[MAX];
    int cont_col=0, cont_paren=0;
    
    system ("cls");
    cout << "* * * * * VALIDACAO DE FUNCAO * * * * *\n\n\n";
    cout << "Digite uma expressao: ";
    gets (expressao);
    tamanho = strlen(expressao);

    for (i=0; i<tamanho; i++){
        if (expressao[i] == parenteses){
            inserir (pilha, &topo, parenteses);
            cont_paren ++;
        }
        if (expressao[i] == parentese_invertido){
            retirar (pilha, &topo);
            cont_paren --;
        }
    }

    for (i=0; i<tamanho; i++){
        if (expressao[i] == colchetes){
            inserir (pilha, &topo, colchetes);
            cont_col++;
        }
        if (expressao[i] == colchete_invertido){
            retirar (pilha, &topo);
            cont_col--;
        }
    }

    system ("cls");
    cout << "* * * * * * * * * * * * * * * * *\n\n\n";
    if (topo==0 && cont_paren==0 && cont_col==0)
        for (i=0; i<tamanho; i++)
            cout << expressao[i];       
    else
        cout << "Expressao invalida!...";
    cout << "\n\n\n* * * * * * * * * * * * * * * * *\n\n";
    system ("pause");
return 0;
}