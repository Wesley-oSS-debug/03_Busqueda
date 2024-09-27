/*busqueda binaria*/
#include <iostream>
#include <windows.h>
using namespace std;
int Binaria(int[],int,int);
void interDirDer(int[],int);
void imprimirArreglo(int[],int);
int main() {
	SetConsoleOutputCP(CP_UTF8);
	int n,dato;
	cout<<"\t---------METODO DE BUSQUEDA BINARIA----------\n"<<endl;
	cout<<"Ingrese el tamaño del ARRAY: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento ""["<<i+1<<"] : "; cin>>arreglo[i];
	}
	cout<<endl;
	interDirDer(arreglo,n-1); 
	imprimirArreglo(arreglo,n);
	cout<<endl;
	cout<<"Ingrese el dato a buscar: "; cin>>dato;
	cout<<endl;
	cout<<"\nPosición del dato: ";
	cout<<Binaria(arreglo,n-1,dato);
	
}
//Intercambio Directo Derecha
void interDirDer(int arr[],int n) {
	int aux;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n-i;j++) {
			if(arr[j]>arr[j+1]) {
				aux=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=aux;
			}	
		}
	}
}
//Imprimir los elementos del arreglo ordenado
void imprimirArreglo(int arr[],int n) {
	cout<<"ARRAY ORDENADO:\n";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//Metodo de busqueda binaria
int Binaria(int A[],int n,int dato) {
	int izq=0;
	int der=n;
	int cen=0;
	int m,pos;
	while (izq<=der && cen==0) {
		m=(izq+der)/2;
		if (A[m]==dato) {
			cen=1;
		} else {
			if (dato>A[m]) {
				izq=m+1;
			} else {
				der=m-1;
			}
		}
	}
	if (cen==1) {
		pos=m;
	} else {
		pos=-izq;
	}
	return pos;
}


