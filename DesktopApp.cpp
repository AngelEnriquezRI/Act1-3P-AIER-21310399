#include <iostream>

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
};

Nodo* addNodo(int);

void insertNodo(Nodo*&, int);
void seethree(Nodo*, int);

Nodo* arbol = NULL;

int main()
{
    std::cout << "";
}

Nodo* addNodo(int x) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = x;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void insertNodo(Nodo*& arbol, int x) {
    if (arbol == NULL) {
        Nodo* nuevo_nodo = addNodo(x);
        arbol = nuevo_nodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (x < valorRaiz) {
            insertNodo(arbol->izq, x);
        }
        else {
            insertNodo(arbol->der, x);
        }
    }
}

void seethree(Nodo* arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        seethree(arbol->der, cont + 1);
        for (int i = 0;i < cont;i++) {
            std::cout << "   ";
        }
        std::cout << arbol->dato << std::endl;
        seethree(arbol->izq, cont + 1);
    }
}