/*Se tienen los siguientes atributos de personal : DNI, nombres, dia, mes y anio de nacimiento. 
Se pide realizar una busqueda binaria por fecha de nacimiento. Sugerencia: Use dos registros
(personal y fecha) y tres funciones (uno para ordenar el arreglo por cada insercion, otro para 
la busqueda y el ultimo para comparar fechas). Asuma que nadie comparte la misma 
fecha de nacimiento*/
#include <iostream> 
#include <windows.h>
using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Personal{
	string dni;
	string nombres;
	Fecha nacim;
};

void ordenaPos(int,Personal[]);
bool comparar(Personal,Personal);
int Binaria(Personal[],int,Personal);

int main() {
	SetConsoleOutputCP(CP_UTF8);
	const int tam=100;
	Personal per[tam],dato;
	int n;
	
	cout<<"Ingrese la cantidad de personal: "; cin>>n;
	
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"PERSONAL ["<<i+1<<"] :\n";
		cin.ignore();
		cout<<"Ingrese nombre completo: "; getline(cin,per[i].nombres);
		cout<<"Ingrese DNI: "; cin>>per[i].dni;
		cout<<"Ingrese Fecha de nacimiento\nDia: "; cin>>per[i].nacim.dia;
		cout<<"Mes: "; cin>>per[i].nacim.mes;
		cout<<"Año: "; cin>>per[i].nacim.anio;
	}
	
	ordenaPos(n,per);
	cout<<"\n----------PERSONAL ORDENADO POR FECHA DE NACIMIENTO-----------\n";
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"Indice "<<i<<":"<<endl;
		cout<<"Nombre completo: "<<per[i].nombres<<endl;
		cout<<"DNI: "<<per[i].dni<<endl;
		cout<<"Fecha de nacimiento\nDia: "<<per[i].nacim.dia<<endl;
		cout<<"Mes: "<<per[i].nacim.mes<<endl;
		cout<<"Año: "<<per[i].nacim.anio<<endl;
	}
	
	cout<<endl;
	cout<<"Ingrese la fecha de nacimiento del personal a buscar:\n";
	cout<<"Ingrese el día: "; cin>>dato.nacim.dia;
	cout<<"Ingrese el mes: "; cin>>dato.nacim.mes;
	cout<<"Ingrese el año: "; cin>>dato.nacim.anio;
	cout<<endl;
	cout<<"Indice del personal encontrado: "<<Binaria(per,n-1,dato); 
}
void ordenaPos(int n,Personal p[]) {
	Personal aux;
	int k;
	for (int i=0;i<n;i++) {
		aux=p[i];
		k=i-1;
		while (k>=0 && comparar(aux,p[k]))  {
			p[k+1]=p[k];
			k--;
		}
		p[k+1]=aux;
	}
}
bool comparar(Personal aux,Personal p) {
	if (aux.nacim.anio<p.nacim.anio ||
    	(aux.nacim.anio==p.nacim.anio && aux.nacim.mes<p.nacim.mes) ||
        (aux.nacim.anio==p.nacim.anio && aux.nacim.mes==p.nacim.mes && aux.nacim.dia<p.nacim.dia)){
        	return true;
		} else {
			return false;
		}
}

int Binaria(Personal A[],int n,Personal dato) {
	int izq=0;
	int der=n;
	int cen=0;
	int m,pos;
	while (izq<=der && cen==0) {
		m=(izq+der)/2;
		if ((A[m].nacim.anio==dato.nacim.anio) && (A[m].nacim.mes==dato.nacim.mes) 
			&& (A[m].nacim.dia==dato.nacim.dia) ) {
			cen=1;
		} else {
			if ((dato.nacim.anio>A[m].nacim.anio) || (dato.nacim.mes>A[m].nacim.mes) 
			|| (dato.nacim.dia>A[m].nacim.dia)) {
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