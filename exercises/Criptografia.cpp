#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Funcao menu para escolher uma opcão
int opcao(){
    int op;
    cout << "\n\n* * * * * * * MENU * * * * * * *\n\n";
    cout << "\n  [1] Ler arquivo de texto";
    cout << "\n  [2] - Criptografar";
    cout << "\n  [3] - Descriptografar";
    cout << "\n\n  [9] - SAIR\n";
    cout << "\n\n * * * * * * * * * * * * * * * *";
    cout << "\n\n RESPOSTA: ";
    cin >> op;
return op;
}

int main(){
    char msg[100];
    int i, tam, op, cont=0;

    //expressão que será usada para criptografia e leitura
    system ("cls");
    cout << "\n\nDigite uma expressao: ";
    gets (msg);
    tam = strlen(msg);


    do{
    system("cls");    
    op = opcao ();
    switch (op){ 
        case 1://funcao para leitura da expressao
            system ("cls");
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            cout << "\n\n" << msg << "\n\n";
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        break;

        case 2://funcao para criptografar a expressao
            system ("cls");
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            if (cont==0){
                for (i=0; i<tam; i++){
                    if (i%2 == 0)
                        msg[i]=msg[i]+5;
                    else
                    msg[i]=msg[i]-1;
                }
                cont++;
                cout << "\n\nMensagem criptografada com sucesso!\n\n";
            }
            else{
                cout << "\n\nA mensagem ja foi criptografada!!!\n\n";
            }
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        break;

        case 3://funcao para descriptografar a expressao
            system ("cls");
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            if (cont==1){
                for (i=0; i<tam; i++){
                    if (i%2 == 0)
                        msg[i]=msg[i]-5;
                    else
                        msg[i]=msg[i]+1;
                }
                cont--;
                cout << "\n\nMensagem descriptografada com sucesso!\n\n";
            }
            else{
                cout << "\n\nA mensagem nao esta criptografada!!!\n\n";
            }
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        break;

        case 9://sair do programa
            system ("cls");
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            cout << "\n\nPrograma finalizado!!!\n\n";
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        break;

        default:
            system ("cls");
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            cout << "\n\nOpcao invalida!!!\n\nDigite novamente...\n\n";
            cout << "\n\n* * * * * * * * * * * * * * * *\n\n";
            system ("pause");
        break;
        }
    }while(op!=9);
return 0;
}