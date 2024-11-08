#pragma once
#include <string> 
//#include "Lista.h"
//#include "Jugador.h"

class Carta
{
protected: 
	std::string color; 
	std::string tipo;  

public:
	Carta(); 
	virtual void PrintInfo();
	std::string GetTipo(); 
	std::string GetColor(); 
};

