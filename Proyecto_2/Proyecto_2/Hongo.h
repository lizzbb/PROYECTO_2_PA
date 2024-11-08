#pragma once
#include <string>
#include "Carta.h"

class Hongo : public Carta
{
private: 
	std::string grado;
	int gradoI;

public: 
	Hongo(int g);
	int GetGradoI();
	void PrintInfo() override; 
};

