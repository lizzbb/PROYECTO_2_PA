#pragma once
#include "Carta.h"
#include <string>
#include "Lista.h"

class Planta : public Carta
{
private: 
	//string tipo = "Planta";
	int fungicida; 
	int hongo; 
	//bool Abono; 

public: 
	Planta(std::string c);
	int GetHongo(); 
	void AsignarEfectoF(Carta* carta); 
	void AsignarEfectoH(Carta* carta); 
	void PrintInfo() override;
};

