#include "Fungicida.h"
#include "colors.h"

#include <iostream>

Fungicida::Fungicida(std::string c) : Carta()
{
	tipo = "Fungicida"; 
	color = c; 
}

void Fungicida::PrintInfo()
{
	std::cout << ". Fungicida color "; 

	if (color == "azul")
	{
		std::cout << BLUE << color << WHITE;
	}
	else if (color == "amarillo")
	{
		std::cout << YELLOW << color << WHITE;
	}
	else
	{
		std::cout << RED << color << WHITE;
	}

	std::cout << " " << std::endl; 
}