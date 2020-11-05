#include "DetaliiPersonale.h"
#include "Angajat.h"
#include "Programator.h"
#include "Manager.h"
#include "Firma.h"
#include <fstream>

int main()
{
	ifstream FisierCitire;
	FisierCitire.open("Citire.txt");
	ofstream FisierAfisare;
	FisierAfisare.open("Afisare.txt");

	Angajat** firma = new Angajat * [4];
	for (int i = 0; i <4; i++)
	{
		if (i % 2 == 0)
		{
			firma[i] = Firma::CreareAngajat(TipAngajat::PROGRAMATOR);
		}
		else
		{
			firma[i] = Firma::CreareAngajat(TipAngajat::MANAGER);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		firma[i]->Citire(FisierCitire);
	}
	for (int i = 0; i < 4; i++)
	{
		firma[i]->Afisare(cout);
	}
	return 0;
}