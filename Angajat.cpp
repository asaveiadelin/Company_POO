#include "Angajat.h"

Angajat::Angajat()
{
	NumeAngajat = nullptr;
	salariuAngajat = NULL;
	id_UnicAngajat=NULL;
	id_Pozitie = Pozitie::UNKNOWN;
	detaliiAngajat.adresa = nullptr;
	detaliiAngajat.email = nullptr;
}
Angajat::Angajat(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie)
{

	this->NumeAngajat = new char[strlen(NumeAngajat) + 1];
	strcpy_s(this->NumeAngajat, strlen(NumeAngajat) + 1, NumeAngajat);
	
	this->detaliiAngajat.adresa= new char[strlen(detaliiAngajat.adresa) + 1];
	strcpy_s(this->detaliiAngajat.adresa, strlen(detaliiAngajat.adresa) + 1, detaliiAngajat.adresa);

	this->detaliiAngajat.email = new char[strlen(detaliiAngajat.email) + 1];
	strcpy_s(this->detaliiAngajat.email, strlen(detaliiAngajat.email) + 1, detaliiAngajat.email);

	this->salariuAngajat = salariuAngajat;
	this->id_UnicAngajat = id_UnicAngajat;
	this->id_Pozitie = id_Pozitie;

}
Angajat::Angajat(const Angajat& sursa)
{
	if (sursa.NumeAngajat != nullptr)
	{
		NumeAngajat = new char[strlen(sursa.NumeAngajat) + 1];
		strcpy_s(NumeAngajat, strlen(sursa.NumeAngajat) + 1, sursa.NumeAngajat);
	}
	else
	{
		NumeAngajat = nullptr;
	}
	if (sursa.detaliiAngajat.adresa != nullptr)
	{
		detaliiAngajat.adresa = new char[strlen(sursa.detaliiAngajat.adresa) + 1];
		strcpy_s(detaliiAngajat.adresa, strlen(sursa.detaliiAngajat.adresa) + 1, sursa.detaliiAngajat.adresa);
	}
	else
	{
		detaliiAngajat.adresa = nullptr;
	}
	if (sursa.detaliiAngajat.email != nullptr)
	{
		detaliiAngajat.email = new char[strlen(sursa.detaliiAngajat.email) + 1];
		strcpy_s(detaliiAngajat.email, strlen(sursa.detaliiAngajat.email) + 1, sursa.detaliiAngajat.email);
	}
	else
	{
		detaliiAngajat.email = nullptr;
	}
	salariuAngajat = sursa.salariuAngajat;
	id_UnicAngajat = sursa.id_UnicAngajat;
	id_Pozitie = sursa.id_Pozitie;
}
Angajat& Angajat::operator=(const Angajat& angajat) 
{
	if (angajat.NumeAngajat != nullptr)
	{
		NumeAngajat = new char[strlen(angajat.NumeAngajat) + 1];
		strcpy_s(NumeAngajat, strlen(angajat.NumeAngajat) + 1, angajat.NumeAngajat);
	}
	else
	{
		NumeAngajat = nullptr;
	}
	if (angajat.detaliiAngajat.adresa != nullptr)
	{
		detaliiAngajat.adresa = new char[strlen(angajat.detaliiAngajat.adresa) + 1];
		strcpy_s(detaliiAngajat.adresa, strlen(angajat.detaliiAngajat.adresa) + 1, angajat.detaliiAngajat.adresa);
	}
	else
	{
		detaliiAngajat.adresa = nullptr;
	}
	if (angajat.detaliiAngajat.email != nullptr)
	{
		detaliiAngajat.email = new char[strlen(angajat.detaliiAngajat.email) + 1];
		strcpy_s(detaliiAngajat.email, strlen(angajat.detaliiAngajat.email) + 1, angajat.detaliiAngajat.email);
	}
	else
	{
		detaliiAngajat.email = nullptr;
	}
	salariuAngajat = angajat.salariuAngajat;
	id_UnicAngajat = angajat.id_UnicAngajat;
	id_Pozitie = angajat.id_Pozitie;

	return*this;
}
Angajat::~Angajat()
{
	if (this->NumeAngajat != nullptr)
	{
		delete[] NumeAngajat;
	}
	if (this->detaliiAngajat.email != nullptr)
	{
		delete[] detaliiAngajat.email;
	}
	if (this->detaliiAngajat.adresa != nullptr)
	{
		delete[] detaliiAngajat.adresa;
	}
	id_Pozitie = Pozitie::UNKNOWN;
}
char* Angajat::returnNumeAngajat()
{
	return NumeAngajat;
}
double Angajat::returnSalariu()
{
	return salariuAngajat;
}
int Angajat::returnid_UnicAngajat()
{
	return id_UnicAngajat;
}

char* Angajat::returnAdresa()
{
	return detaliiAngajat.adresa;
}

char* Angajat::returnEmail()
{
	return  detaliiAngajat.email;
}
//void Angajat::Citire(void)
//{
//	char buffer[100];
//	int optiunePozitie;
//	cout << ">>>>Introduceti nume angajat: ";
//	cin.getline(buffer, 100);
//	if (NumeAngajat != nullptr)
//	{
//		delete[] NumeAngajat;
//	}
//	NumeAngajat = new char[strlen(buffer) + 1];
//	strcpy_s(NumeAngajat, strlen(buffer) + 1, buffer);
//	
//	cout << ">>>>Introduceti pozitie angajat (UNKNOWN = 0 | JUNIOR = 1 | ENTRY_LEVEL = 2 | TEAM_LEADER = 3 | CEO = 4): ";
//	cin >> optiunePozitie;
//	switch (optiunePozitie)
//	{
//	case 0:
//		id_Pozitie = Pozitie::UNKNOWN;
//		break;
//	case 1:
//		id_Pozitie = Pozitie::JUNIOR;
//		break;
//	case 2:
//		id_Pozitie = Pozitie::ENTRY_LEVEL;
//		break;
//	case 3:
//		id_Pozitie = Pozitie::TEAM_LEADER;
//		break;
//	case 4:
//		id_Pozitie = Pozitie::CEO;
//		break;
//	default:
//		id_Pozitie = Pozitie::UNKNOWN;
//		break;
//	}
//	cout << ">>>>Introduceti ID angajat: ";
//	cin>>id_UnicAngajat;
//	cout << ">>>>Introduceti salariu angajat (RON): ";
//	cin >> salariuAngajat;
//	cin.ignore(100, '\n');
//	cout << ">>>>Introduceti adresa angajat: ";
//	cin.getline(buffer, 100);
//	if (detaliiAngajat.adresa != nullptr)
//	{
//		delete[] detaliiAngajat.adresa;
//	}
//	detaliiAngajat.adresa = new char[strlen(buffer) + 1];
//	strcpy_s(detaliiAngajat.adresa , strlen(buffer) + 1, buffer);
//
//	cout << ">>>>Introduceti email angajat: ";
//	cin.getline(buffer, 100);
//	if (detaliiAngajat.email != nullptr)
//	{
//		delete[] detaliiAngajat.email;
//	}
//	detaliiAngajat.email = new char[strlen(buffer) + 1];
//	strcpy_s(detaliiAngajat.email, strlen(buffer) + 1, buffer);
//}

//void Angajat::Afisare(void)
//{
//	cout << "------->Detalii Angajat." << endl;
//	if (NumeAngajat != nullptr)
//	{
//		cout << "\tNumele angajatului: " << this->returnNumeAngajat()<<"." << endl;
//	}
//	else
//	{
//		cout << "\tNumele angajatului: - " << endl;
//	}
//	cout << "\tGradul angajatului: ";
//	switch (id_Pozitie)
//	{
//	case Pozitie::UNKNOWN:
//		cout << "UNKNOWN." << endl;
//		break;
//	case Pozitie::JUNIOR:
//		cout << "JUNIOR." << endl;
//		break;
//	case Pozitie::ENTRY_LEVEL:
//		cout << "ENTRY_LEVEL." << endl;
//		break;
//	case Pozitie::TEAM_LEADER:
//		cout << "TEAM_LEADER." << endl;
//		break;
//	case Pozitie::CEO:
//		cout << "CEO." << endl;
//		break;
//	default:
//		cout << "UNKNOWN." << endl;
//		break;
//	}
//	cout << "\tID-ul angajatului: " << this->returnid_UnicAngajat() << "." << endl;
//	cout << "\tSalariul angajatului: " << this->returnSalariu() << " RON." << endl;
//	if (detaliiAngajat.adresa != nullptr)
//	{
//		cout << "\tAdresa angajatului: " << this->returnAdresa() << "." << endl;
//	}
//	else
//	{
//		cout << "\tAdresa angajatului: - " << endl;
//	}
//
//	if (detaliiAngajat.email != nullptr)
//	{
//		cout << "\tEmail-ul angajatul: " << this->returnEmail() << "." << endl;
//	}
//	else
//	{
//		cout << "\tEmail-ul angajatul: - " << endl;
//	}
//}

void Angajat::Citire(istream& is)
{
	char buffer[100];
	int optiunePozitie;
	if (&is == &cin)
	{
		cout << ">>>>Introduceti numele angajatului: ";
	}
	is.getline(buffer, 100);
	if (NumeAngajat != nullptr)
	{
		delete[] this->NumeAngajat;
	}
	NumeAngajat = new char[strlen(buffer) + 1];
	strcpy_s(NumeAngajat, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti pozitie angajat (UNKNOWN = 0 | JUNIOR = 1 | ENTRY_LEVEL = 2 | TEAM_LEADER = 3 | CEO = 4): ";
	}
	is >> optiunePozitie;
	switch (optiunePozitie)
	{
	case 0:
		id_Pozitie = Pozitie::UNKNOWN;
		break;
	case 1:
		id_Pozitie = Pozitie::JUNIOR;
		break;
	case 2:
		id_Pozitie = Pozitie::ENTRY_LEVEL;
		break;
	case 3:
		id_Pozitie = Pozitie::TEAM_LEADER;
		break;
	case 4:
		id_Pozitie = Pozitie::CEO;
		break;
	default:
		id_Pozitie = Pozitie::UNKNOWN;
		break;
	}
	if (&is == &cin)
	{
		cout << ">>>>Introduceti ID angajat: ";
	}
	is >> id_UnicAngajat;
	if (&is == &cin)
	{
		cout << ">>>>Introduceti salariu angajat (RON): ";
	}
	is >> salariuAngajat;
	is.ignore(100, '\n');
	if (&is == &cin)
	{
		cout << ">>>>Introduceti adresa : ";
	}
	is.getline(buffer, 100);
	if (detaliiAngajat.adresa != nullptr)
	{
		delete[] detaliiAngajat.adresa;
	}
	detaliiAngajat.adresa = new char[strlen(buffer) + 1];
	strcpy_s(detaliiAngajat.adresa, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti email: ";
	}
	is.getline(buffer, 100);
	if (detaliiAngajat.email != nullptr)
	{
		delete[] detaliiAngajat.email;
	}
	detaliiAngajat.email = new char[strlen(buffer) + 1];
	strcpy_s(detaliiAngajat.email, strlen(buffer) + 1, buffer);
}
void Angajat::Afisare(ostream& os)
{
	os << "--->Detalii Angajat." << endl;
	if (NumeAngajat != nullptr)
	{
		os << "\tNumele angajatului: " << this->returnNumeAngajat() << "." << endl;
	}
	else
	{
		os << "\tNumele angajatului: - " << endl << endl;
	}
	os << "\tGradul angajatului: ";
	switch (id_Pozitie)
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
	os << "\tID-ul angajatului: " << this->returnid_UnicAngajat() << "." << endl;
	os << "\tSalariul angajatului: " << this->returnSalariu() << " RON." << endl;
	if (detaliiAngajat.adresa != nullptr)
	{
		os << "\tAdresa angajatului: " << this->returnAdresa() << "." << endl;
	}
	else
	{
		os << "\tAdresa angajatului: - " << endl << endl;
	}

	if (detaliiAngajat.email != nullptr)
	{
		os << "\tEmail-ul angajatul: " << this->returnEmail() << "." << endl;
	}
	else
	{
		os << "\tEmail-ul angajatul: - " << endl << endl;
	}
}