#include "Carta.h"
#include <iostream>

Carta::Carta() {}

void Carta::PrintInfo()
{
	std::cout <<  "Carta de color " << color << std::endl;
}

std::string Carta::GetTipo()
{
	return tipo;
}

std::string Carta::GetColor()
{
	return color; 
}