#include <iostream>
#include<stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
        int dato;
        Nodo *siguiente;

};
void insertarLista_Final(Nodo *&, int);
void insertarLista_Inicio(Nodo *&, int);
void mostrarLista(Nodo *);
void menu();
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
        cout<<"4. Salir\n";
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
        }
        system("cls");
    }while(opcion != 4);

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
