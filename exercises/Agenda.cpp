#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define N 1000

struct agenda{
    string nome, email;
    int dia, mes, ano;
};

int menu(){
    int op;

    system ("cls");
    cout << "\t# MENU #\n\n";
    cout << "[1] \t CADASTRAR CONTATO\n";
    cout << "[2] \t EXCLUIR CONTATO\n";
    cout << "[3] \t ALTERAR CONTATO\n";
    cout << "[4] \t CONSULTAR DATA\n";
    cout << "[5] \t CONSULTAR MES\n";
    cout << "[6] \t BUSCAR CONTATO POR LETRA\n";
    cout << "[7] \t CLASSIFICAR DE A-Z\n";
    cout << "[8] \t CLASSIFICAR POR MES\n";
    cout << "[9] \t SAIR\n\n";
    cout << "Digite a opcao que deseja: ";
    cin >> op;

    return op;
}

int main(){
    int op1, qtdd=0, data1, mes1, aux;
    string nome1;
    agenda contatos[N];    

    do{
        op1 = menu();
        switch (op1){
            case 1: /*Cadastrar pessoa na agenda de aniversariante*/
                system("cls");
                if (qtdd < N){
                    cout << "Digite o nome do contato: ";
                    cin >> contatos[qtdd].nome;
                    cout << "Digite o e-mail de " << contatos[qtdd].nome << ": ";
                    cin >> contatos[qtdd].email;
                    cout << "Digite o dia de Nascimento de " << contatos[qtdd].nome << ": ";
                    cin >> contatos[qtdd].dia;
                    cout << "Digite o mes de Nascimento de " << contatos[qtdd].nome << ": ";
                    cin >> contatos[qtdd].mes;
                    cout << "Digite o ano de Nascimento de " << contatos[qtdd].nome << ": ";
                    cin >> contatos[qtdd].ano;
                    cout << "\n\nContato registrado com sucesso!!!\n";
                    system ("pause");
                    qtdd++;
                }
                else
                    cout << "AGENDA CHEIA!!!";
            break;

            case 2: system("cls");/*Excluir pessoa a partir do nome*/
                if(qtdd == 0)cout << "\n\nAgenda vazia!!!\n\n";
                else{
                    cout << "Digite o nome para excluir dos contatos: ";
                    cin >> nome1;
                    for(int i=0; i<N; i++){
                        if(contatos[i].nome == nome1){
                            for(int t=i; t<N-1; t++)
                                contatos[t] = contatos[t+1];
                            cout << "\n\nContato removido com sucesso!!\n\n";
                            qtdd--;   
                        }
                    }
                }
                system("pause");
            break;

            case 3: system("cls");/*Alterar dia, mes e ano a partir do nome*/
                if(qtdd == 0)cout << "\n\nAgenda vazia!!!\n\n";
                else{
                    cout << "Digite o nome do contato para alterar a data: ";
                    cin >> nome1;
                    for(int i=0; i<N; i++){
                        if(contatos[i].nome == nome1){
                            cout << "Digite o dia de Nascimento de " << nome1 << ": ";
                            cin >> contatos[i].dia;
                            cout << "Digite o mes de Nascimento de " << nome1 << ": ";
                            cin >> contatos[i].mes;
                            cout << "Digite o ano de Nascimento de " << nome1 << ": ";
                            cin >> contatos[i].ano;
                            cout << "\n\nData atualizada com sucesso!!!\n";
                        }
                    }
                }
                system("pause");
            break;           
            
            case 4: system("cls");/*Consultar aniversariantes do dia*/
                if(qtdd == 0)cout << "\n\nAgenda vazia!!!\n\n";
                else{
                    cout << "Digite um dia para consultar: ";
                    cin >> data1;
                    for(int i=0; i<N; i++){
                        if(contatos[i].dia == data1){
                            cout << contatos[i].nome << "\t" << contatos[i].email << "\t" <<
                            contatos[i].dia << "/" << contatos[i].mes << "/" << contatos[i].ano << "\n";
                        }
                    }
                }
                system("pause");
            break;
            
            case 5: system("cls");/*Consultar aniversariantes do mes*/
                if(qtdd == 0)cout << "\n\nAgenda vazia!!!\n\n";
                else{
                    cout << "Digite um mes para consultar: ";
                    cin >> mes1;
                    for(int i=0; i<N; i++){
                        if(contatos[i].mes == mes1){
                            cout << contatos[i].nome << "\t" << contatos[i].email << "\t" <<
                            contatos[i].dia << "/" << contatos[i].mes << "/" << contatos[i].ano << "\n";
                        }
                    }
                }
                system("pause");
            break;

            case 6: system("cls");/*Consultar aniversariantes pela letra*/
                
                system("pause");
            break;

            case 7: system ("cls");/*Mostrar agenda ordenada por nome*/
                for (int t=0; t<qtdd; t++){
                    cout << contatos[t].nome << "\t" << contatos[t].email << "\t" <<
                    contatos[t].dia << "/" << contatos[t].mes << "/" << contatos[t].ano << "\n";
                }
                cout << endl;
                system ("pause");
            break;

            case 8: system("cls");/*Mostrar agenda ordenada por mes*/
                for (int i = 0; i < qtdd; i++){
                    for (int j = 0; j < qtdd; j++){
                        if (contatos[i].mes < contatos[j].mes){
                            aux = contatos[i].mes;
                            contatos[i].mes = contatos[j].mes;
                            contatos[j].mes = aux;
                        }
                    }
                }
                system("pause");
            break;

            case 9: system ("cls");/*Sair*/
                cout << "Programa finalizado!!!";
                system ("pause");
            break;

            default: system ("cls");/*Opcao invalida*/ 
                cout << "OPCAO INVALIDA!!!";
                system ("pause");  
            break;
        }
    }while (op1 != 9);
    
return 0;
}