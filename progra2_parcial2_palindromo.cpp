#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main(){
	char cadena[20];
	int i;
	char aux[20];
	cout << "Escribe un palindromo: ";
	cin.getline(cadena,20);
//	strcpy(cadenaChar, cadena.c_str());
	int longitud = sizeof(cadena);
	for(i=0;i<=longitud;i++){
		if(cadena[i] != 32 ){
			cout << cadena[i];
		}
	}
	cout << aux;
//	for (i = 0; i <= longitud-1; i++) {
//		aux[1] = cadenaChar[i];
//		cadenaCharInv[longitud-(i+1)] = aux[1];
//		cout << "Valor de i: " << i << endl;
//		cout << "Valor del auxiliar: " << aux[1] << endl;
//		cout << "valor de caracter: " << cadenaCharInv[longitud-(i+1)] << "\n\n\n";
//	}
//	cout << "Cadena original: " << cadenaChar << " Cadena invertida: " << cadenaCharInv << endl;
}
