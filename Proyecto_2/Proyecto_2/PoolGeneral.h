#pragma once
#include <vector>
#include "Carta.h"

class PoolGeneral
{
private:
	std::vector<Carta*> poolGeneral;

public:
	~PoolGeneral() {};
	void GenerarPool();
	void Barajar();
	void Pop();
	Carta* Repartir();
	void PrintPool();
	std::vector<Carta*> GetPoolGeneral(); 
};

