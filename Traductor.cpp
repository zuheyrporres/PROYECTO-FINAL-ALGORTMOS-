#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const char *nombre_archivo = "traductor.txt";

struct Traductor{
	int correlativo;
	string palabra;
	string Npalabra;
	string traduccion;
	string funcionalidad;
	int bclave;
	string linea;
	string linea2;
	string linea3;
	int res;
};

void ingresar();
void abrir();
void buscar_palabra();
void eliminar_palabra();

main(){
	int opcion;
	
	while(true){
		cout<<"1 - Agregar"<<endl;
		cout<<"2 - Leer"<<endl;
		cout<<"3 - Buscar"<<endl;
		cout<<"4 - Modificar"<<endl;
		cout<<"5 - Eliminar"<<endl;
		cout<<"6 - Salir"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		
		system("cls");
		switch(opcion){
			case 1:
				{
					ingresar();
					break;
				}
			case 2:
				{
					abrir();
					break;
				}
			case 3:
				{
					buscar_palabra();
					break;
				}
			case 4:
				{
					eliminar_palabra();
					break;
				}
			case 6:
				{
					return 0;
					break;
				}
			
		}
	}
	return 0;
}

void abrir (){
	ifstream archivo;
	archivo.open(nombre_archivo, ios::app); 
	string fila;
	
	if(archivo.fail()){
		cout<<"No es posible abrir el archivo"<<endl;
		exit(1);
	}else{
		do{
			getline(archivo, fila);
			cout<<fila<<endl;
		}while(archivo.eof()==false);
		
	}
	archivo.close();
}

void ingresar(){
	ofstream guardar;
	guardar.open(nombre_archivo, ios::app);

	char s;
	Traductor traductor;
	
	if(guardar.fail()){
		cout<<"No es posible abrir el archivo"<<endl;
		exit(1);
	}else{
		do{
			cout<<"Ingrese correlativo: ";
			cin>>traductor.correlativo;
			cout<<"Ingrese palabra: ";
			cin>>traductor.palabra;
			cout<<"Ingrese traduccion: ";
			cin>>traductor.traduccion;
			cout<<"Ingrese funcionalidad: ";
			cin.ignore();
			getline(cin, traductor.funcionalidad);
			
			guardar<<traductor.correlativo<<", "<<traductor.palabra<<", "<<traductor.traduccion<<", "<<traductor.funcionalidad<<endl;
			
			cout<<"Desea agregar mas datos (s/n)";
			cin>>s;
			system("cls");
		}while(s=='s');
	}
	
	guardar.close();
	//abrir();
}

void buscar_palabra(){
	fstream buscar;
	
	Traductor traductor;
	traductor.res = 0;
	
	cout<<"Ingrese el correlativo a buscar (formato: -#.): ";
	cin>>traductor.Npalabra;
	
	if(!buscar.is_open()){
		buscar.open(nombre_archivo, ios::in);
	}
	
	while(getline(buscar, traductor.linea))
	{
		if(traductor.linea.find(traductor.Npalabra) != string::npos)
		{
			cout<<traductor.linea<<endl;
			traductor.res = 1;
		}
	}
	
	if (traductor.res == 0){
		cout<<traductor.Npalabra<<" no se encuentra"<<endl;
	}
}

void eliminar_palabra(){
	fstream buscar;
	ofstream temp;
	temp.open("Temp.txt");
	
	Traductor traductor;
	traductor.res = 0;
	
	cout<<"Ingrese el correlativo a buscar (formato: -#.): ";
	cin>>traductor.Npalabra;
	
	if(!buscar.is_open()){
		buscar.open(nombre_archivo, ios::in);
	}
	
	while(getline(buscar, traductor.linea))
	{
		if(traductor.linea.find(traductor.Npalabra) != string::npos)
		{
			cout<<traductor.linea<<endl;
			cout<<"Palabra a eliminar"<<endl;
			traductor.res = 1;
		} else {
			temp<<traductor.correlativo<<", "<<traductor.palabra<<", "<<traductor.traduccion<<", "<<traductor.funcionalidad<<endl;
		}
	}
	
	if (traductor.res == 0){
		cout<<traductor.Npalabra<<" no se encuentra"<<endl;
	}
}
