#include "Hongo.h"
#include "colors.h"

#include <iostream>

Hongo::Hongo(int g) : Carta()
{
	color = "Gris";
	tipo = "Hongo"; 

	gradoI = g; 
	if (gradoI == 1)
	{
		grado = "1";
	}
	else if (gradoI == 2)
	{
		grado = "2";
	}
	else
	{
		grado = "fatal";
	}
}

int Hongo::GetGradoI()
{
	return gradoI; 
}

void Hongo::PrintInfo()
{
	std::cout << GRAY << ". Hongo de grado " << grado << GRAY << std::endl; 
}
