#pragma once
#include <string> 
#include "colors.h"
#include "Carta.h"
#include "Lista.h"
#include "Planta.h"
#include "Hongo.h"

using namespace std; 
class Jugador
{
private: 
	string nombre; 
	Lista pool;
	Lista garden; 

public: 
	Jugador(string n); 
	void SetPool(Carta* carta); 
	void EliminarCartaPool(int index); 
	void PrintPool(); 
	void SetGarden(Carta* planta); 
	void SetGarden(Lista g);  
	void InsertInGarden(Carta* carta, int index); 
	void EliminarPlantaGarden(int index); 
	Carta* AsignarEfectosPlanta(Carta* carta, int index);
	string GetNombre(); 
	Lista GetGarden(); 
	Lista GetPool();
	void PrintInfo(); 
};

