#include "Programator.h"

Programator::Programator() :Angajat()
{
	LimbajProgramare = nullptr;
}

Programator::Programator(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie, const char* LimbajProgramare)
	: Angajat(NumeAngajat, salariuAngajat, detaliiAngajat, id_UnicAngajat, id_Pozitie)
{
	this->LimbajProgramare = new char[strlen(LimbajProgramare) + 1];
	strcpy_s(this->LimbajProgramare, strlen(LimbajProgramare) + 1, LimbajProgramare);
}
Programator::Programator(const Programator& sursa):Angajat(sursa)
{
	if (sursa.LimbajProgramare != nullptr)
	{
		LimbajProgramare = new char[strlen(sursa.LimbajProgramare) + 1];
		strcpy_s(LimbajProgramare, strlen(sursa.LimbajProgramare) + 1, sursa.LimbajProgramare);
	}
	else
	{
		LimbajProgramare = nullptr;
	}
}
Programator::~Programator()
{
	if (LimbajProgramare != nullptr)
	{
		delete[] LimbajProgramare;
	}
	
}
char* Programator::retunrLimbajProgramare()
{
	return LimbajProgramare;
}

//void Programator::Citire(void)
//{
//	char buffer[100];
//	cout << "=====================================================================" << endl;
//	cout << "                        >Introduceti Detalii<                        " << endl;
//	cout << "=====================================================================" << endl;
//	Angajat::Citire();
//	cout << ">>>>Introduceti limbajul de programare: ";
//	cin.getline(buffer, 100);
//	if (LimbajProgramare != nullptr)
//	{
//		delete[] LimbajProgramare;
//	}
//	LimbajProgramare = new char[strlen(buffer) + 1];
//	strcpy_s(LimbajProgramare, strlen(buffer) + 1, buffer);
//	cout << "=====================================================================" << endl << endl;
//
//}
//
//void Programator::Afisare(void)
//{
//	cout << "=====================================================================" << endl;
//	cout << "                        >Afisare Programator<                        " << endl;
//	cout << "=====================================================================" << endl;
//	Angajat::Afisare();
//	cout << "------->Detalii Programator." << endl;
//	if (LimbajProgramare != nullptr)
//	{
//		cout << "\tLimbajul de programare: " << this->retunrLimbajProgramare() <<"."<< endl;
//	}
//	else
//	{
//		cout << "\tLimbajul de programare: - " << endl;
//	}
//	
//	cout << "=====================================================================" << endl << endl;
//}

void Programator::Citire(istream& is)
{
	char buffer[100];
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl;
		cout << "                 >Introduceti Detalii Programator<                   " << endl;
		cout << "=====================================================================" << endl;

	}
	Angajat::Citire(is);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti limbajul de programare: ";
	}
	is.getline(buffer, 100);
	if (LimbajProgramare != nullptr)
	{
		delete[] LimbajProgramare;
	}
	LimbajProgramare = new char[strlen(buffer) + 1];
	strcpy_s(LimbajProgramare, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl << endl;
	}
}
void Programator::Afisare(ostream& os)
{
	os << "=====================================================================" << endl;
	os << "                        >Afisare Programator<                        " << endl;
	os << "=====================================================================" << endl;
	Angajat::Afisare(os);
	os << "--->Detalii Programator." << endl;
	if (this->LimbajProgramare != nullptr)
	{
		os << "\tLimbajul de programare: " << this->retunrLimbajProgramare() << "." << endl;
	}
	else
	{
		os << "\tLimbajul de programare: - " << endl;
	}
	os << "=====================================================================" << endl << endl;
}



Programator& Programator::operator=(const Programator& programator)
{
	if (programator.NumeAngajat != nullptr)
	{
		NumeAngajat = new char[strlen(programator.NumeAngajat) + 1];
		strcpy_s(NumeAngajat, strlen(programator.NumeAngajat) + 1, programator.NumeAngajat);
	}
	else
	{
		NumeAngajat = nullptr;
	}
	if (programator.detaliiAngajat.adresa != nullptr)
	{
		detaliiAngajat.adresa = new char[strlen(programator.detaliiAngajat.adresa) + 1];
		strcpy_s(detaliiAngajat.adresa, strlen(programator.detaliiAngajat.adresa) + 1, programator.detaliiAngajat.adresa);
	}
	else
	{
		detaliiAngajat.adresa = nullptr;
	}
	if (programator.detaliiAngajat.email != nullptr)
	{
		detaliiAngajat.email = new char[strlen(programator.detaliiAngajat.email) + 1];
		strcpy_s(detaliiAngajat.email, strlen(programator.detaliiAngajat.email) + 1, programator.detaliiAngajat.email);
	}
	else
	{
		detaliiAngajat.email = nullptr;
	}
	salariuAngajat = programator.salariuAngajat;
	id_UnicAngajat = programator.id_UnicAngajat;
	id_Pozitie = programator.id_Pozitie;
	if (programator.LimbajProgramare != nullptr)
	{
		LimbajProgramare = new char[strlen(programator.LimbajProgramare) + 1];
		strcpy_s(LimbajProgramare, strlen(programator.LimbajProgramare) + 1, programator.LimbajProgramare);
	}
	else
	{
		LimbajProgramare = nullptr;
	}
	return *this;
}

istream& operator>>(istream& is, Programator& programator)
{
	char buffer[100];
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl;
		cout << "                        >Introduceti Detalii<                        " << endl;
		cout << "=====================================================================" << endl;

	}
	int optiunePozitie;
	if (&is == &cin)
	{
		cout << ">>>>Introduceti numele angajatului: ";
	}
	is.getline(buffer, 100);
	if (programator.NumeAngajat != nullptr)
	{
		delete[] programator.NumeAngajat;
	}
	programator.NumeAngajat = new char[strlen(buffer) + 1];
	strcpy_s(programator.NumeAngajat, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti pozitie angajat (UNKNOWN = 0 | JUNIOR = 1 | ENTRY_LEVEL = 2 | TEAM_LEADER = 3 | CEO = 4): ";
	}
	is >> optiunePozitie;
	switch (optiunePozitie)
	{
	case 0:
		programator.id_Pozitie = Pozitie::UNKNOWN;
		break;
	case 1:
		programator.id_Pozitie = Pozitie::JUNIOR;
		break;
	case 2:
		programator.id_Pozitie = Pozitie::ENTRY_LEVEL;
		break;
	case 3:
		programator.id_Pozitie = Pozitie::TEAM_LEADER;
		break;
	case 4:
		programator.id_Pozitie = Pozitie::CEO;
		break;
	default:
		programator.id_Pozitie = Pozitie::UNKNOWN;
		break;
	}
	if (&is == &cin)
	{
		cout << ">>>>Introduceti ID angajat: ";
	}
	is >> programator.id_UnicAngajat;
	if (&is == &cin)
	{
		cout << ">>>>Introduceti salariu angajat (RON): ";
	}
	is >> programator.salariuAngajat;
	is.ignore(100, '\n');
	if (&is == &cin)
	{
		cout << ">>>>Introduceti adresa : ";
	}
	is.getline(buffer, 100);
	if (programator.detaliiAngajat.adresa != nullptr)
	{
		delete[] programator.detaliiAngajat.adresa;
	}
	programator.detaliiAngajat.adresa = new char[strlen(buffer) + 1];
	strcpy_s(programator.detaliiAngajat.adresa, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti email: ";
	}
	is.getline(buffer, 100);
	if (programator.detaliiAngajat.email != nullptr)
	{
		delete[] programator.detaliiAngajat.email;
	}
	programator.detaliiAngajat.email = new char[strlen(buffer) + 1];
	strcpy_s(programator.detaliiAngajat.email, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti limbajul de programare: ";
	}
	is.getline(buffer, 100);
	if (programator.LimbajProgramare != nullptr)
	{
		delete[] programator.LimbajProgramare;
	}
	programator.LimbajProgramare = new char[strlen(buffer) + 1];
	strcpy_s(programator.LimbajProgramare, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl << endl;
	}
	return is;
 }

ostream& operator<<(ostream& os, Programator& programator)
{
	os << "=====================================================================" << endl;
	os << "                        >Afisare Programator<                        " << endl;
	os << "=====================================================================" << endl;
	os << "--->Detalii Angajat." << endl;
	if (programator.NumeAngajat != nullptr)
	{
		os << "\tNumele angajatului: " << programator.returnNumeAngajat()<<"."<< endl;
	}
	else
	{
		os << "\tNumele angajatului: - " << endl << endl;
	}
	os << "\tGradul angajatului: ";
	switch (programator.id_Pozitie)
	{
	case Pozitie::UNKNOWN:
		os << "UNKNOWN." << endl;
		break;
	case Pozitie::JUNIOR:
		os << "JUNIOR." << endl;
		break;
	case Pozitie::ENTRY_LEVEL:
		os << "ENTRY_LEVEL." << endl;
		break;
	case Pozitie::TEAM_LEADER:
		os << "TEAM_LEADER." << endl;
		break;
	case Pozitie::CEO:
		os << "CEO." << endl;
		break;
	default:
		os << "UNKNOWN." << endl;
		break;
	}
	os << "\tID-ul angajatului: " << programator.returnid_UnicAngajat() << "." << endl;
	os << "\tSalariul angajatului: " << programator.returnSalariu() << " RON." << endl;
	if (programator.detaliiAngajat.adresa != nullptr)
	{
		os << "\tAdresa angajatului: " << programator.returnAdresa() << "." << endl;
	}
	else
	{
		os << "\tAdresa angajatului: - " << endl << endl;
	}

	if (programator.detaliiAngajat.email != nullptr)
	{
		os << "\tEmail-ul angajatul: " << programator.returnEmail() << "." << endl;
	}
	else
	{
		os << "\tEmail-ul angajatul: - " << endl << endl;
	}
	os << "--->Detalii Programator." << endl;
	if (programator.LimbajProgramare != nullptr)
	{
		os << "\tLimbajul de programare: " << programator.retunrLimbajProgramare() << "." << endl;
	}
	else
	{
		os << "\tLimbajul de programare: - " << endl;
	}
	os << "=====================================================================" << endl << endl;
	return os;
}


