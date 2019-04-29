#include <iostream>
#include <string.h>
using namespace std;
 
void moves(int num,char A,char C,char B){
    if(num==1){
            cout << "Mueva el bloque " << num << " desde " << A << " hasta  " << C << endl;
             
    }
    else{
        moves(num-1,A,B,C);
        cout << "Mueva el bloque " << num << " desde " << A << " hasta  " << C << endl;
        moves(num-1,B,C,A);
    }
}
 
int main(){
        int n;
        char A,B,C;
        string resp;
        do{
        	cout<<"Los pivotes son A B C\n";
        	cout << "Desea comenzar a jugar?[s/n]" << endl;
			cin >> resp;
			system("cls");
		}while(resp=="n");
		moves(4,'A','C','B');
}
