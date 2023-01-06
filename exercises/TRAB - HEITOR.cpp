//PROGRAMA SIMPLES PARA SIMULAR O AGENDAMENTOS E ENCAMINHAMENTO DE CLIENTES PARA O ATENDIMENTO
//LINGUAGEM C++;
//FORAM USADAS A  MAIORIA DOS COMANDO APRENDIDOS NO PRIMEIRO SEMESTRE DO CURSO DE ADS(FATEC)
//NOME DO ALUNO: Heitor Santos Afonso
//RA: 2840482011011

#include <iostream>
#include <stdlib.h>
using namespace std;

struct registro{
  string nome = "";
  string cpf = "";
  string contato = "";
};

int total(int prior, int esp){
  return prior+esp;
} 

void limparegistro(struct registro *cliente){
  string limpo = "";
  cliente ->nome = limpo;
  cliente ->cpf = limpo;
  cliente ->contato = limpo;
}

void erro(){
  system ("clear");
  cout << "OPCAO INVALIDA !!!\n\n";
  cout << "PRESCIONE ENTER PARA VOLTAR...";
  cin.ignore();
  cin.get();
}
int main(){
  system ("clear");
  int op, op1, sair=1;
  int cont1=9;
  int cont_pr=0, cont_esp=0;
  registro cl[10];

  while (sair == 1){
    system ("clear");
    cout << "********** MENU PRINCIPAL **********" << "\n\n";
    cout << " [1] ATENDIMENTO\n [2] LISTA DE ESPERA\n [3] RELATORIO\n [0] SAIR\n";
    cout << "\n************************************\n";
    cout << "Digite a opcao: ";
    cin >> op;
    
    switch (op){
      case 1: system ("clear");
        cout << "********* ATENDIMENTO *********" << "\n\n";
        cout << " [1] PRIORITARIO\n [2] LISTA DE ESPERA\n";
        cout << "\n******************************\n";
        cout << "Digite a opcao: ";
        cin >> op1;
        cout << "******************************\n";

        if (op1 == 1){
          cout << "\nDigite o nome do cliente: ";
          cin >> cl[0].nome;
          cout << "Digite o numero de CPF: ";
          cin >> cl[0].cpf;
          cout << "Digite um numero para contato: ";
          cin >> cl[0].contato; 
          cout << "*********************************\n";
          cont_pr++;
        }
        else if (op1 == 2){
            for (int i=cont1; i>0; i--){
              if (cl[i].nome == ""){
                cout << "\nDigite o nome do cliente: ";
                cin >> cl[i].nome;
                cout << "Digite o numero de CPF: ";
                cin >> cl[i].cpf;
                cout << "Digite um numero para contato: ";
                cin >> cl[i].contato;
                cout << "\n*********************************\n";
                cont1--;
                cont_esp++;
              }
              break;
            }
          if (cont1 == 0)
            cout << "LISTA DE ESPERA CHEIA!!!"; 
          }
        else erro(); 
      break;

      case 2: system ("clear"); 
        if (cont1 < 9){
          cout << "********** LISTA DE ESPERA **********" << "\n\n";
          cout << " [1] VISUALIZAR\n [2] ATENDER PROXIMO\n";
          cout << "\n*********************************\n";
          cout << "Digite a opcao: ";
          cin >> op1;
          cout << "*********************************\n";
          
          if(op1 == 1){
            for(int i=9; i>0; i--){
              if(i<=cont1) break;
              cout << "\nCLIENTE " << 10-(i) << ":";
              cout << endl << cl[i].nome << endl << cl[i].cpf << endl << cl[i].contato << endl;
            }
            cout << "\n*********************************";
          }
          else if(op1 == 2){ 
            cout << "\nCLIENTE:\n";
            cout << cl[9].nome << endl << cl[9].cpf << endl << cl[9].contato;
            cout << "\n\n*********************************";
            limparegistro(&cl[9]);
            for (int i=9; i>0; i--){
              cl[i].nome = cl[i-1].nome;
              cl[i].cpf = cl[i-1].cpf;
              cl[i].contato = cl[i-1].contato;
            }
            cont1 ++;
          }
        }
        else cout << "LISTA VAZIA !!!";
        cin.ignore();
        cin.get();
      break;

      case 3: system ("clear"); 
        cout << "********** RELATORIO **********\n\n";
        cout << "TOTAL DE ATENDIMENTOS: " << total(cont_pr,cont_esp);
        cout << "\n\nATENDIMENTOS PRIORITARIOS: " << cont_pr;
        cout << "\n\nATENDIMENTOS EM ESPERA: " << (cont1-9)*-1;
        cout << "\n\n*********************************";
        cin.ignore();
        cin.get();

      break;
      case 0: system ("clear"); 
        cout << " tchau !!!";
        sair = 0;
      break;
      default: erro();
      break;
    }
  }
return 0;
}