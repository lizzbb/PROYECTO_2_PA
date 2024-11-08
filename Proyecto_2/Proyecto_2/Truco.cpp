#include "Truco.h"
#include "colors.h"

#include <iostream>

Truco::Truco(std::string tt)
{
	color = "Gris"; 
	tipo = "Truco"; 
	tipoTruco = tt; 
}

std::string Truco::GetTipoTruco()
{
	return tipoTruco; 
}

void Truco::PrintInfo()
{
	std::cout << GRAY << ". " << tipoTruco << WHITE << std::endl;

}


