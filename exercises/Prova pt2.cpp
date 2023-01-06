#include <iostream>
#define M 10
using namespace std;

int main(){
    int vet[M];
    int i, j, menor;

    
    for(i=0; i<M; i++){
        system ("cls");
        cout << "* * * * * * * * * * * * * * * * * * * *";
        cout << "\n\n\tINSERIR VETOR " << i+1;
        cout << "\n\n* * * * * * * * * * * * * * * * * * * *\n\n\n";
        cout << "Digite um valor: ";
        cin >> vet[i];
    }

    for(i=0; i<(M-1); i++){
        menor = vet[i];
        for(j=i+1; j<(M); j++){
            if(vet[j] < vet[i]){
                menor = vet[j];
                vet[j] = vet[i];
                vet[i] = menor;
            }
        }
    }
    
    system ("cls");
    cout << "* * * * * * * * * * * * * * * * * * * * * * *";
    cout << "\n\n\t\tVETOR ORDENADO\n\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * *\n\n\n";
    for(i=0; i<M; i++)
        cout << vet[i] << "   ";
    cout << "\n\n\n* * * * * * * * * * * * * * * * * * * * * * *\n\n\n";
    system ("pause");
return 0;
}