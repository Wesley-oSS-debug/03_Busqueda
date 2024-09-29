/*Se pide leer un monomio y buscar si forma parte del polinomio. Usa busqueda secuencial*/
#include <iostream>
#include <windows.h>
using namespace std;
struct monomio{
	float exp;
	float coef;
};
int secuencialDes(monomio[],int,monomio);
int main() {
	SetConsoleOutputCP(CP_UTF8);
	int n;
	const int tam=50;
	monomio ter[tam],dato;
	cout<<"Ingrese la cantidad de términos del polinomio: "; cin>>n;
	
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"Ingrese el coeficiente "<<i+1<<" : "; cin>>ter[i].coef;
		cout<<"Ingrese el exponente "<<i+1<<" : "; cin>>ter[i].exp;
	}
	
	cout<<endl;
	cout<<"POLINOMIO: "<<endl;
	for (int i=0;i<n;i++) {
		cout<<ter[i].coef<<"x^"<<ter[i].exp;
		if (i!=n-1) {
			cout<<" + ";
		}
	}
	
	cout<<endl;
	cout<<"\nIngrese el monomio que quiere buscar "<<endl;
	cout<<"Ingrese el coeficiente: "; cin>>dato.coef;
	cout<<"Ingrese el exponente: "; cin>>dato.exp;
	cout<<endl;
	
	if (secuencialDes(ter,n,dato)!=-1) {
		cout<<"Monomio encontrado en el índice: "<<secuencialDes(ter,n,dato);
	} else {
		cout<<"El monomio no ha sido encontrado"<<endl;
	}
	
}
//Busqueda secuencial desordenada
int secuencialDes(monomio A[],int n,monomio dato) {
	int pos=-1;
	int i=0;
	while (i<n && (A[i].coef!=dato.coef && A[i].exp!=dato.exp)) {
		i++;
	}
	if (i<n) {
		pos=i;
	}
	return pos;
}