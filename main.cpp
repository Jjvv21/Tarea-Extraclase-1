#include <iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
        int dato;
        Nodo *siguiente;

};
void menu();
void insertarLista_Final(Nodo *&, int);
void insertarLista_Inicio(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);

Nodo *lista = NULL;

int main() {

    menu();
    getch();
    return 0;

}

void menu() {
    int opcion, dato;

    do{
        cout<<"\t. Menu: \n";
        cout<<"1. Insertar elementos a la lista Final\n";
        cout<<"2. Insertar elementos a la lista Inicio\n";
        cout<<"3. Mostrar elementos de la lista\n";
        cout<<"4. Buscar elemento de la lista\n";
        cout<<"5. Salir\n";
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
            case 3:mostrarLista(lista);
                cout<<"\n";
                system("pause");
                break;
            case 4:cout<<" Digite un numero: ";
                cin>>dato;
                buscarLista(lista,dato);
                cout<<"\n";
                system("pause");
                break;
        }
        
        
        system("cls");
    }while(opcion != 5);

}


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
    cout<<"\tElemento \t"<<n<<"\tinsertado a lista correctamente\n";
}


void insertarLista_Inicio(Nodo *&lista, int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato =n;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
    cout<<"\tElemento \t"<<n<<"\tinsertado a lista correctamente\n";
}



void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual=lista;
    while(actual != NULL){
        cout<<actual->dato<<"-->";
        actual = actual->siguiente;
    }
    cout<<"La lista esta vacia";
}

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
