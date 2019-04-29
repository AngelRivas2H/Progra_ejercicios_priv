#include <iostream>
#include <stdint.h>
using namespace std;
uint_fast64_t factorial(int a);
int main(){
   int n,i;
    cout << "Introduzca numero: ";
    cin >> n;
    for(i=0;i<=n;i++){
    	cout << "factorial de " << i << " es :" << factorial(i) << endl;	
	}
}
uint_fast64_t factorial(int a){
    uint_fast64_t fact;
    if (a==0){
    	return 1;	
	}
    else{
    	fact = a*factorial(a-1);
    	return fact;	
	}
}
