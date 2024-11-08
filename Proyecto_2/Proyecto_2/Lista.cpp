#include "Lista.h"
#include <iostream>

//Estructura de nodos que se usara en las listas
struct Lista::Nodo
{
	Carta* objeto;
	Nodo* anterior;
	Nodo* siguiente;
	Nodo(Carta* o) : objeto(o), anterior(nullptr), siguiente(nullptr) {}

};

Lista::Lista() : inicio(nullptr), final(nullptr) {}

//Agregar un elemento a la lista
void Lista::Agregar(Carta* elemento)
{
	Nodo* nuevoNodo = new Nodo(elemento);

	if (inicio == nullptr)
	{
		inicio = nuevoNodo;
		final = nuevoNodo; 
	}
	else
	{
		final->siguiente = nuevoNodo;
		nuevoNodo->anterior = final;
		final = nuevoNodo;
	}
}

//Insertar un elemento a la lista para actualizar su informacion de efectos
void Lista::Insertar(Carta* carta, int index)
{
	Nodo* nuevoNodo = new Nodo(carta);

	// Si la lista está vacía, el nuevo nodo será el único elemento
	if (inicio == nullptr) {
		inicio = nuevoNodo;
		final = nuevoNodo;
		return;
	}

	// Insertar al inicio de la lista
	if (index == 0) {
		nuevoNodo->siguiente = inicio;
		inicio->anterior = nuevoNodo;
		inicio = nuevoNodo;
		return;
	}

	// Recorrer la lista hasta encontrar la posición de inserción
	Nodo* nodoActual = inicio;
	int contador = 0;

	while (nodoActual != nullptr && contador < index) {
		nodoActual = nodoActual->siguiente;
		contador++;
	}

	// Si el índice es mayor que el tamaño de la lista, se inserta al final
	if (nodoActual == final) {
		final->siguiente = nuevoNodo;
		nuevoNodo->anterior = final;
		final = nuevoNodo;
	}
	// Insertar en una posición intermedia
	else if (nodoActual != nullptr) {
		nuevoNodo->siguiente = nodoActual->siguiente;
		nuevoNodo->anterior = nodoActual;

		if (nodoActual->siguiente != nullptr) {
			nodoActual->siguiente->anterior = nuevoNodo;
		}
		nodoActual->siguiente = nuevoNodo;
	}
}

//Eliminar un elemento de la lista con su indice
void Lista::Eliminar(int index)
{
	if (inicio == nullptr) { return; }

	Nodo* nodoActual = inicio;
	int contador = 0;

	while (nodoActual != nullptr && contador < index)
	{
		nodoActual = nodoActual->siguiente;
		contador++;
	}

	if (nodoActual == nullptr) { return; }

	if (nodoActual == inicio)
	{
		inicio = inicio->siguiente;
		if (inicio != nullptr)
		{
			inicio->anterior = nullptr;
		}
		else
		{
			final = nullptr;
		}
	}
	else if (nodoActual == final)
	{
		final = final->anterior;
		final->siguiente = nullptr;
	}
	else
	{
		nodoActual->anterior->siguiente = nodoActual->siguiente;
		nodoActual->siguiente->anterior = nodoActual->anterior;
	}

	delete nodoActual;
}

//Obtener un elemento de la lista con su indice
Carta* Lista::GetElemento(int index)
{
	if (inicio == nullptr) { return nullptr; }

	Nodo* nodoActual = inicio;
	int contador = 0;

	while (nodoActual != nullptr && contador < index)
	{
		nodoActual = nodoActual->siguiente;
		contador++;
	}

	if (nodoActual == nullptr) { return nullptr; }

	return nodoActual->objeto;
}

//Imprimir la lista
void Lista::PrintLista()
{
	if (inicio == nullptr)
	{
		return; 
	}
	else
	{
		Nodo* nodoActual = inicio;
		int contador = 1;

		while (nodoActual != nullptr) {
			std::cout << contador; 
			nodoActual->objeto->PrintInfo(); 
			nodoActual = nodoActual->siguiente; 
			contador++; 
		}
	}
}

//Obtener el tamanio de la lista
int Lista::Size()
{
	Nodo* nodoActual = inicio; 
	int contador = 0; 

	while (nodoActual != nullptr)
	{
		contador++; 
		nodoActual = nodoActual->siguiente; 
	}

	return contador; 
}


