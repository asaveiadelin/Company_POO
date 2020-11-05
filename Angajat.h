#pragma once
#include "DetaliiPersonale.h"

enum class Pozitie {
	UNKNOWN = 0,
	JUNIOR = 1,
	ENTRY_LEVEL = 2,
	TEAM_LEADER = 3,
	CEO = 4
};
class Angajat
{
	protected:
		char* NumeAngajat;
		double salariuAngajat;
		DetaliiPersonale detaliiAngajat;
		int id_UnicAngajat;
		Pozitie id_Pozitie;

	public:
		Angajat();
		Angajat(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie);
		Angajat(const Angajat& sursa);
		~Angajat();

		Angajat& operator=(const Angajat& angajat);
	
		char* returnNumeAngajat();
		char* returnAdresa();
		char* returnEmail();
		double returnSalariu();
		int returnid_UnicAngajat();

		virtual void Citire(istream& is);
		virtual void Afisare(ostream& os);
};

