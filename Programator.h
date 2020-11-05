#pragma once
#include "Angajat.h"
class Programator:public Angajat
{
	private:
		char* LimbajProgramare;
	public:
		Programator();
		Programator(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie, const char* LimbajProgramare);
		Programator(const Programator& sursa);
		~Programator();
		char* retunrLimbajProgramare();

		Programator& operator=(const Programator& angajat);
		friend ostream& operator<<(ostream& os, Programator& programator);
		friend istream& operator>>(istream& is, Programator& programator);

	
		void Citire(istream& is);
		void Afisare(ostream& os);
};

