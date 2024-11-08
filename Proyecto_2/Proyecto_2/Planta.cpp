#include "Hongo.h"
#include "Planta.h"
#include <iostream>
#include "colors.h"

Planta::Planta(std::string c) : Carta()
{
	tipo = "Planta"; 
	color = c; 
	fungicida = 0; 
	hongo = 0;
}

int Planta::GetHongo()
{
	return hongo; 
}

//Asignar efecto de fungicida a la planta
void Planta::AsignarEfectoF(Carta* carta)
{
	if (carta->GetTipo() == "Fungicida")
	{
		//SI YA HAY DOS FUNGICIDAS EN LA PLANTA
		if (fungicida > 3)
		{
			std::cout << MAGENTA << "Oh no! Solo se pueden colocar maximo 2 fungicidas sobre la misma planta. " << WHITE << std::endl; 
		}
		//SI LA FUNGICIDA NO ES DEL MISMO COLOR
		if (carta->GetColor() != color)
		{
			std::cout << MAGENTA << "Oh no! No se puede colocar una fungicida sobre una planta de diferente color. " << WHITE << std::endl; 
		}
		//CONDICIONES APTAS PARA ASIGNAR FUNGICIDA
		if (fungicida < 3 && carta->GetColor() == color)
		{
			fungicida++; //Se asigna el efecto
			std::cout << MAGENTA << "Perfecto! Ahora tu planta esta protegida. " << WHITE << std::endl; 
		}
		//SI LA PLANTA TIENE UN EFECTO DE HONGO DE GRADO 1
		if (hongo == 1)
		{
			hongo = 0; //Se elimina el efecto
			fungicida = 0; //Se elimina la fungicida porque se uso para curar la planta
			std::cout << MAGENTA << "Los efectos de la fungicida han curado a su planta!" << WHITE << std::endl;
		}
	}
}

//Asignar efecto de hongo a la planta
void Planta::AsignarEfectoH(Carta* carta)
{
	Hongo* h = dynamic_cast<Hongo*>(carta); //Convertir la carta en objeto de tipo hongo para acceder a sus metodos
		
		//HONGO DE GRADO 1
		if (h->GetGradoI() == 1)
		{
			//SI NO TIENE NINGUN EFECTO DE FUNGICIDA
			if (fungicida == 0)
			{
				hongo += 1; //Se asigna el efecto

				//Si el efecto actual de hongo es menor o igual a 2
				if (hongo <= 2)
				{
					std::cout << MAGENTA << "Se ha contaminado la planta con el hongo exitosamente." << WHITE << std::endl;
				}

				//Si el efecto actual de hongo es igual a 2
				if (hongo == 2)
				{
					std::cout << MAGENTA << "La planta ha sido eliminada!" << WHITE << std::endl;
				}
			}
			//SI SE TIENE UNA FUNGICIDA SOBRE LA PLANTA
			else if (fungicida == 1)
			{
				fungicida = 0; //Se elimina el efecto porque se utilizo para proteger la planta
				std::cout << MAGENTA << "Oh! La planta ha sido protegida por una fungicida." << WHITE << std::endl;
			}
			//SI LA PLANTA TIENE LA MAXIMA PROTECCION (2 FUNGICIDAS)
			else
			{
				std::cout << MAGENTA << "No se puede infectar la planta porque esta protegida por dos fungicidas." << WHITE << std::endl;
			}
		}
		//HONGO GRADO 2
		else if (h->GetGradoI() == 2)
		{
			//SI LA PLANTA TIENE LA MAXIMA PROTECCION (2 FUNGICIDAS)
			if (fungicida == 2)
			{
				std::cout << MAGENTA << "No se puede infectar la planta porque esta protegida por dos fungicidas. " << WHITE << std::endl;
			}

			//SI LA PLANTA TIENE LA MINIMA PROTECCION O NINGUNA PROTECCION
			else
			{
				hongo = 2; 
				std::cout << MAGENTA << "La planta ha sido eliminada!" << WHITE << std::endl;
			}
		}
		//HONGO GRADO 3
		else
		{
			hongo = 3;
			std::cout << MAGENTA << "La planta ha sido eliminada!" << WHITE << std::endl;
		}	
}

	


void Planta::PrintInfo()
{
	std::cout << ". Planta color ";
	
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

	if (fungicida != 0)
	{
		std::cout << ", " << fungicida << " fungicidas ";
	}
	if (hongo == 1)
	{
		std::cout << ", hongo grado 1";
	}
	std::cout << " " << std::endl; 
}
