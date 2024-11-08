#pragma once
#include "Carta.h"
#include "Lista.h"
#include "Jugador.h"

class Truco : public Carta
{
private: 
	std::string tipoTruco;

public: 
	Truco(std::string tt);
	std::string GetTipoTruco(); 
	void PrintInfo() override; 
};


