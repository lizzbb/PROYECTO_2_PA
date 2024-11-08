#pragma once
#include "Carta.h"
 
class Lista
{
private: 
	struct Nodo; 
	Nodo* inicio; 
	Nodo* final; 

public: 
	Lista(); 
	void Agregar(Carta* elemento); 
	void Insertar(Carta* elemento, int index);
	void Eliminar(int index); 
	void PrintLista(); 
	Carta* GetElemento(int index); 
	int Size(); 
};

