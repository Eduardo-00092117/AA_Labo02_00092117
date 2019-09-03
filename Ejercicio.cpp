
#include <cstdlib>
#include <iostream>
#include "string.h"

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *prev;
};

class Cola{
    private:
        Nodo *inicio;
        Nodo *fin;
    
    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n -> dato = valor;
            n -> sig = nullptr;
            n -> prev = nullptr;
            return n;
        }
        
        void push(int valor){
            Nodo *n = crearNodo(valor);
            if(!inicio){
                inicio = n;
                fin = n;
            } else{
                fin -> sig = n;
                n -> prev = fin;
                fin = n;
            }
        }
        
        void pop(){
            Nodo *temp = inicio;
            inicio = inicio -> sig;
            free(temp);
        }
        
        void mostrarCola(string mensaje){
            Nodo *temp = inicio;
            if(!inicio)
                cout << "Cola " << mensaje << " vacia" << endl;
            else{
                cout << "Cola " << mensaje << ": ";
                while(temp -> sig){
                    cout << temp -> dato << ", ";
                    temp = temp -> sig;
                }
                cout << temp -> dato << endl;
            }
        }
        
        void mostrarColaInversa(){
            Nodo *temp;
            cout << "Cola inversa: ";
            for(temp = inicio; temp -> sig != nullptr; temp = temp -> sig);
            while(temp -> prev){
                cout << temp -> dato << ", ";
                temp = temp -> prev;
            }
            cout << temp -> dato << endl;
        }
        
        int promedio(){
            Nodo *temp = inicio;
            if(!inicio){
                cout << "Cola vacia, no se puede sacar el promedio" << endl;
                return 0.0;
            } else{
                int suma = 0, cont = 0;
                while(temp){
                    suma = suma + temp -> dato;
                    ++cont;
                    temp = temp -> sig;
                }
                return (suma/cont);
            }
        }
        
        void colaMultiplos(int promedio){
            Cola c2;
            Nodo *temp = inicio;
            if(!inicio){
                cout << "Cola vacia" << endl;
            } else{
                while(temp){
                    if(temp -> dato%promedio == 0){
                        c2.push(temp -> dato);
                    }
                    temp = temp -> sig;
                }
                c2.mostrarCola("de promedios");
            }
        }
        
        Cola(){
            inicio = nullptr;
            fin = nullptr;
        }
};

int main(int argc, char** argv) {
    Cola c1;
    
    cout << "NOTA: Para mas facilidad si el promedio da decimal, se deja como un entero!!" << endl << endl;
    
    c1.push(1);
    c1.push(2);
    c1.push(3);
    c1.push(4);
    
    c1.mostrarCola("inicial");
    
    c1.mostrarColaInversa();
    
    cout << "El promedio es de " << c1.promedio() << endl;
    
    c1.colaMultiplos(c1.promedio());
    
    return 0;
}

