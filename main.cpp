#include <iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;

//Estructura Nodo
struct Nodo{
        int dato;
        Nodo *direccion;
        Nodo *siguiente;
        
        
};

//Referencia a los  metodos que se utilizan y las listas globales
void menu();
void insertarLista_Final(Nodo *&, int);
void insertarLista_Inicio(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarNodo(Nodo *&, int);
void guardarMemoria(Nodo *&);

Nodo *lista = NULL;
Nodo *listaCollector = NULL;



int main() {
	
	
    menu();
    getch();
    return 0;

}

//Menu para seleccionar la operacion a realizar
void menu() {
    int opcion, dato;

    do{
        cout<<"\t. Menu: \n";
        cout<<"1. Insertar elementos a la lista Final\n";
        cout<<"2. Insertar elementos a la lista Inicio\n";
        cout<<"3. Eliminar elemento de la lista\n";
        cout<<"4. Mostrar elementos de la lista\n";
        cout<<"5. Buscar elemento de la lista\n";
        cout<<"6. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;
        
        switch (opcion) {
            case 1:cout<<" Digite un numero: ";
                cin>>dato;
                insertarLista_Final(lista,dato);
                cout<<"\n";
                system("pause");
                break;
            case 2:cout<<" Digite un numero: ";
                cin>>dato;
                insertarLista_Inicio(lista,dato);
                cout<<"\n";
                system("pause");
                break;    
            case 3:cout<<" Digite el elemento que quiera eliminar: ";
                cin>>dato;
                eliminarNodo(lista,dato);
                cout<<"\n";
                system("pause");
                break;
            case 4:mostrarLista(lista);
                cout<<"\n";
                system("pause");
                break;
            case 5:cout<<" Digite un numero: ";
                cin>>dato;
                buscarLista(lista,dato);
                cout<<"\n";
                system("pause");
                break;
            
        }
        
        
        system("cls");
    }while(opcion != 6);

}
//Clase colector que almacena el espacio en memoria
class Collector{
	private:
		Nodo *direccion;
	public:
		Collector(Nodo *&);//constructor
		void insertarDir();

		
};

//Constructor, nos sirve para inicializar los atributos 
Collector::Collector(Nodo *&_direccion){
	direccion = _direccion;
	
}

//Metodo que inserta en una lista las posiciones en memoria 
void Collector::insertarDir(){
	Nodo *nuevoNodo = new Nodo();
    nuevoNodo = direccion;
    nuevoNodo->siguiente = listaCollector;
    listaCollector = nuevoNodo;
    cout<<"\tElemento \t"<<direccion<<"\tinsertado a lista correctamente\n";
	 
}


//Metodo para insertar al final de la lista
void insertarLista_Final(Nodo *&lista, int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato =n;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato<n)){
        aux2 = aux1;
        aux1=aux1->siguiente;

    }
    if(lista == aux1){
        lista= nuevoNodo;
    }
    else{
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;
    Collector c1(nuevoNodo);
    c1.insertarDir();
    cout<<"\tElemento \t"<<n<<"\tinsertado a lista correctamente\n";
}

//Metodo para insertar al principio de la lista
void insertarLista_Inicio(Nodo *&lista, int n){
    Nodo *nuevoNodo = new Nodo();
    Nodo *nuevoNodoC = new Nodo();
    nuevoNodo->dato =n;
    nuevoNodoC->direccion = nuevoNodo;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
    Collector c1(nuevoNodo);
    c1.insertarDir();
    cout<<"\tElemento \t"<<n<<"\tinsertado a lista correctamente\n";
}

//Metodo para mostrar la lista con numeros
void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual=lista;
    while(actual != NULL){
        cout<<actual->dato<<"-->";
        actual = actual->siguiente;
    }
    cout<<"NULL";
}

//Metodo para buscar un elemento dentro de la lista
void buscarLista(Nodo *lista, int n){
	bool bandera = false; 
	
	Nodo *actual = new Nodo();
	actual = lista; 
	
	while((actual!= NULL) && (actual->dato<=n)){
		if(actual->dato ==n ){
			bandera = true; 
		}
		actual = actual->siguiente;
	}
	if(bandera== true){
		cout<<"El elemento ("<<n<<") ha sido encontrado en la lista\n";
	}
	else{
		cout<<"El elemento no ha sido encontrado en la lista\n";
	}
}


void eliminarNodo(Nodo *&lista , int n){
	//Preguntar si la lista esta vacia 
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista; 
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar; 
		}
		//El elemento esta en la lista, pero no es el primer nodo	
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}
