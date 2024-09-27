/* secuencial */
#include <iostream>
#include <windows.h>
using namespace std;

int secuencialDes(int[], int, int);
int secuencialOrd(int[], int ,int);
void imprimir(int[],int);
void ordenar(int [], int);
int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	int tam;
	cout<<"\n--------BÚSQUEDA SECUENCIAL---------\n";
	cout<<"\n";
	cout<<"Ingrese el tamaño del ARRAY: "; cin>>tam;
	int array[tam];
	for(int i;i<tam;i++){
		cout<<"Ingrese el elemento ["<<i+1<<"] :"; cin>>array[i];
	}
	cout<<"\n\n";
	int dato;
	cout<<"Ingrese el elemento a encontrar :"; cin>>dato;
	//copia del array 
	int arrayCopia[tam];
	for(int i=0;i<tam;i++){
		arrayCopia[i]=array[i];
	}
	int op;
	do{
	cout<<"\n\n\t-------MENU-------\n\n";
	cout<<"1.- Busqueda secuencial de ARRAY desordenada\n";
	cout<<"2.- Busqueda secuencial de ARRAY ordenada\n";
	cout<<"3.- Salir del programa\n\n";
	cout<<"\nIngrese la opción: "; cin>>op;
	
	switch(op){
		case 1:
		if(secuencialDes(array,tam,dato)==-1){
			cout<<"\n--Elemento no encontrado--\n"<<endl;
		}else{
			cout<<"DATO ENCONTRADO:\n ";
			cout<<"POSICIÓN DEL DATO :"<<secuencialDes(array,tam,dato);
		}
	
			break;
		case 2:
			
			ordenar(arrayCopia,tam);
			cout<<"ARRAY ORDENADO:\n ";
			imprimir(arrayCopia,tam);
			cout<<"\n";
			cout<<"Posición del DATO :"<<secuencialOrd(arrayCopia,tam, dato);
	
			break;
		case 3:
			cout<<"Saliendo del programa....";
			return 0;
			break;
		default	:
			cout<<"\nERROR\n";
		
	}
}while(op<4);
	
	return 0;
}
void imprimir(int A[],int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}

int secuencialDes(int A[], int n, int x){
	 int pos=-1;
	 int i=0;
	 while(i<=n && A[i] != x){
	 	i++;
	 } 
	 if(i<=n){
	 	pos=i;
	 }
	 return pos;
	
}

int secuencialOrd(int A[], int n, int x){
	 int pos;
	 int i=0;
	 while(i<=n && A[i] < x){
	 	i++;
	 } 
	 if(i>n || A[i] > x ){
	 	pos=-i;
	 }else{
	 	pos=i;
	 }
	 return pos;	
}
// por método de intercambio por la izquierda
void ordenar( int A[], int n){
	int aux;
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(A[j]<A[j-1]){
				aux=A[j];
				A[j]=A[j-1];
				A[j-1]=aux;
			}
		}
	}	
}