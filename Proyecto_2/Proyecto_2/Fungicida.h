#pragma once
#include "Carta.h"
#include <string>

class Fungicida : public Carta
{

public:
	Fungicida(std::string c); 
	void PrintInfo() override; 
};

