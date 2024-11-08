#include "Jugador.h"
#include <iostream>

Jugador::Jugador(string n)
{
	nombre = n; ; 
}
string Jugador::GetNombre()
{
	return nombre; 
}

//Agregar una carta al pool del jugador
void Jugador::SetPool(Carta* carta)
{
	pool.Agregar(carta); 
}

//Eliminar una carta del pool del jugador
void Jugador::EliminarCartaPool(int index)
{
	pool.Eliminar(index); 
}

//Agregar una planta al jardin del jugador
void Jugador::SetGarden(Carta* planta)
{
	//Verificar que no exceda el maximo del jardin (5)
	if (garden.Size() < 6)
	{
		garden.Agregar(planta); //Se agrega la planta
	}
	else
	{
		cout << "Jardin lleno, solo puede plantar un maximo de 5 plantas." << endl;
	}
}

//Cambiar el jardin completo del jugador (por intercambio)
void Jugador::SetGarden(Lista g)
{
	garden = g;
}

//Insertar una planta con efectos actualizados al jardin 
void Jugador::InsertInGarden(Carta* carta, int index)
{
	garden.Insertar(carta, index);
}

//Eliminar una planta del jardin del jugador
void Jugador::EliminarPlantaGarden(int index)
{
	garden.Eliminar(index); 
}

Lista Jugador::GetPool()
{
	return pool; 
}

void Jugador::PrintPool()
{
	pool.PrintLista(); 
}

Lista Jugador::GetGarden()
{
	return garden; 
}

//Asignar efectos a una de las plantas del jardin del jugador
Carta* Jugador::AsignarEfectosPlanta(Carta* carta, int index)
{
	Planta* planta = dynamic_cast<Planta*>(garden.GetElemento(index)); //Obtencion de la carta en el jardin y conversion de la carta a un objeto de tipo planta para acceder a sus metodos

	//CARTA DE TIPO FUNGICIDA
	if (carta->GetTipo() == "Fungicida")
	{
		planta->AsignarEfectoF(carta); 
	}

	//CARTA DE TIPO HONGO
	else if (carta->GetTipo() == "Hongo")
	{
		planta->AsignarEfectoH(carta); 
	}

	return planta;
}

void Jugador::PrintInfo()
{
	cout << "Jugador: " << nombre << endl; 
	garden.PrintLista(); 
}