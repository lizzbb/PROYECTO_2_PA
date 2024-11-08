#include <algorithm>
#include <iostream>

#include "PoolGeneral.h"
#include "Carta.h"
#include "Planta.h"
#include "Hongo.h"
#include "Fungicida.h"
#include "Truco.h"

using namespace std;

//Creacion de pool principal
void PoolGeneral::GenerarPool()
{
	poolGeneral.push_back(new Planta("azul"));
	poolGeneral.push_back(new Planta("azul"));
	poolGeneral.push_back(new Planta("azul")); 
	poolGeneral.push_back(new Planta("azul"));

	poolGeneral.push_back(new Planta("amarillo"));
	poolGeneral.push_back(new Planta("amarillo"));
	poolGeneral.push_back(new Planta("amarillo")); 
	poolGeneral.push_back(new Planta("amarillo"));

	poolGeneral.push_back(new Planta("rojo"));
	poolGeneral.push_back(new Planta("rojo"));
	poolGeneral.push_back(new Planta("rojo")); 
	poolGeneral.push_back(new Planta("rojo")); 

	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));
	poolGeneral.push_back(new Hongo(1));

	poolGeneral.push_back(new Hongo(2));
	poolGeneral.push_back(new Hongo(2));
	poolGeneral.push_back(new Hongo(2));
	poolGeneral.push_back(new Hongo(2));
	poolGeneral.push_back(new Hongo(2));

	poolGeneral.push_back(new Hongo(3));
	poolGeneral.push_back(new Hongo(3));
	poolGeneral.push_back(new Hongo(3));

	poolGeneral.push_back(new Fungicida("azul"));
	poolGeneral.push_back(new Fungicida("azul"));
	poolGeneral.push_back(new Fungicida("azul"));

	poolGeneral.push_back(new Fungicida("amarillo"));
	poolGeneral.push_back(new Fungicida("amarillo"));
	poolGeneral.push_back(new Fungicida("amarillo"));

	poolGeneral.push_back(new Fungicida("rojo"));
	poolGeneral.push_back(new Fungicida("rojo"));
	poolGeneral.push_back(new Fungicida("rojo"));

	poolGeneral.push_back(new Truco("Trasplantar"));
	poolGeneral.push_back(new Truco("Trasplantar"));
	poolGeneral.push_back(new Truco("Trasplantar"));
	poolGeneral.push_back(new Truco("Trasplantar"));
	poolGeneral.push_back(new Truco("Trasplantar"));
	poolGeneral.push_back(new Truco("Trasplantar"));

	poolGeneral.push_back(new Truco("Intercambio"));
	poolGeneral.push_back(new Truco("Intercambio"));
	poolGeneral.push_back(new Truco("Intercambio"));

}

//Para desordenar el pool que se crea
void PoolGeneral::Barajar()
{
	int n = poolGeneral.size();

	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1); 
		swap(poolGeneral[i], poolGeneral[j]);
	}
}

//Eliminar la ultima carta de la pila del pool
void PoolGeneral::Pop()
{
	poolGeneral.pop_back(); 
}

//Repartir la utlima carta de la pila del pool
Carta* PoolGeneral::Repartir()
{
	return poolGeneral.back();
}

void PoolGeneral::PrintPool()
{
	int n = poolGeneral.size(); 

	for (int i = n - 1; i > 0; i--)
	{
		poolGeneral[i]->PrintInfo(); 
	}
}

std::vector<Carta*> PoolGeneral::GetPoolGeneral()
{
	return poolGeneral; 
}
