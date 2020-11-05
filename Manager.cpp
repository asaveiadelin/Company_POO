#include "Manager.h"

Manager::Manager():Angajat()
{
	m_task = MainTask::TASK_UNKNOWN;
}
Manager::Manager(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie, MainTask m_task)
	: Angajat(NumeAngajat, salariuAngajat, detaliiAngajat, id_UnicAngajat, id_Pozitie)
{
	this->m_task = m_task;
}
Manager::Manager(const Manager& sursa) : Angajat(sursa)
{
	this->m_task = sursa.m_task;
}
Manager::~Manager()
{
	m_task = MainTask::TASK_UNKNOWN;
}


//void Manager::Citire(void)
//{
//	int optiuneTask;
//	cout << "=====================================================================" << endl;
//	cout << "                        >Introduceti Detalii<                        " << endl;
//	cout << "=====================================================================" << endl;
//	//Angajat::Citire();
//
//	cout << ">>>>Introduceti main Task(TASK_UNKNOWN = 0 | PRODUCTIE = 1 | VANZARI = 2 |MARKETING = 3): ";
//	cin >> optiuneTask;
//	switch (optiuneTask)
//	{
//	case 0:
//		m_task = MainTask::TASK_UNKNOWN;
//		break;
//	case 1:
//		m_task = MainTask::PRODUCTIE;
//		break;
//	case 2:
//		m_task = MainTask::VANZARI;
//		break;
//	case 3:
//		m_task = MainTask::MARKETING;
//		break;
//	default:
//		m_task = MainTask::TASK_UNKNOWN;
//		break;
//	}
//	cout << "=====================================================================" << endl << endl;
//	cin.ignore(100, '\n');
//}
//
//void Manager::Afisare(void)
//{
//	cout << "=====================================================================" << endl;
//	cout << "                            >Afisare Manager<                        " << endl;
//	cout << "=====================================================================" << endl;
//	//Angajat::Afisare();
//	cout << "------->Detalii Manager." << endl;
//	cout << "\tMain Task: ";
//	switch (m_task)
//	{
//	case MainTask::TASK_UNKNOWN:
//		cout << "TASK_UNKNOWN." << endl;
//		break;
//	case MainTask::PRODUCTIE:
//		cout << "PRODUCTIE." << endl;
//		break;
//	case MainTask::VANZARI:
//		cout << "VANZARI." << endl;
//		break;
//	case MainTask::MARKETING:
//		cout << "MARKETING." << endl;
//		break;
//	}
//	cout << "=====================================================================" << endl << endl;
//}

void Manager::Citire(istream& is)
{
	int optiuneTask;
	char buffer[100];
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl;
		cout << "                  >Introduceti Detalii Manager<                      " << endl;
		cout << "=====================================================================" << endl;
	}
	Angajat::Citire(is);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti main Task(TASK_UNKNOWN = 0 | PRODUCTIE = 1 | VANZARI = 2 |MARKETING = 3): ";
	}
	is >> optiuneTask;
	switch (optiuneTask)
	{
	case 0:
		m_task = MainTask::TASK_UNKNOWN;
		break;
	case 1:
		m_task = MainTask::PRODUCTIE;
		break;
	case 2:
		m_task = MainTask::VANZARI;
		break;
	case 3:
		m_task = MainTask::MARKETING;
		break;
	default:
		m_task = MainTask::TASK_UNKNOWN;
		break;
	}
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl << endl;
	}
	is.ignore(100, '\n');
}

void Manager::Afisare(ostream& os)
{
	os << "=====================================================================" << endl;
	os << "                          >Afisare Manager<                          " << endl;
	os << "=====================================================================" << endl;
	Angajat::Afisare(os);
	os << "--->Detalii Manager." << endl;
	os << "\tMain Task: ";
	switch (m_task)
	{
	case MainTask::TASK_UNKNOWN:
		os << "TASK_UNKNOWN." << endl;
		break;
	case MainTask::PRODUCTIE:
		os << "PRODUCTIE." << endl;
		break;
	case MainTask::VANZARI:
		os << "VANZARI." << endl;
		break;
	case MainTask::MARKETING:
		os << "MARKETING." << endl;
		break;
	}
	os << "=====================================================================" << endl << endl;
}
Manager& Manager::operator=(const Manager& manager)
{
	if (manager.NumeAngajat != nullptr)
	{
		NumeAngajat = new char[strlen(manager.NumeAngajat) + 1];
		strcpy_s(NumeAngajat, strlen(manager.NumeAngajat) + 1, manager.NumeAngajat);
	}
	else
	{
		NumeAngajat = nullptr;
	}
	if (manager.detaliiAngajat.adresa != nullptr)
	{
		detaliiAngajat.adresa = new char[strlen(manager.detaliiAngajat.adresa) + 1];
		strcpy_s(detaliiAngajat.adresa, strlen(manager.detaliiAngajat.adresa) + 1, manager.detaliiAngajat.adresa);
	}
	else
	{
		detaliiAngajat.adresa = nullptr;
	}
	if (manager.detaliiAngajat.email != nullptr)
	{
		detaliiAngajat.email = new char[strlen(manager.detaliiAngajat.email) + 1];
		strcpy_s(detaliiAngajat.email, strlen(manager.detaliiAngajat.email) + 1, manager.detaliiAngajat.email);
	}
	else
	{
		detaliiAngajat.email = nullptr;
	}
	salariuAngajat = manager.salariuAngajat;
	id_UnicAngajat = manager.id_UnicAngajat;
	id_Pozitie = manager.id_Pozitie;
	m_task = manager.m_task;
	return *this;
}

istream& operator>>(istream& is, Manager& manager)
{
	int optiuneTask;
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
	if (manager.NumeAngajat != nullptr)
	{
		delete[] manager.NumeAngajat;
	}
	manager.NumeAngajat = new char[strlen(buffer) + 1];
	strcpy_s(manager.NumeAngajat, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti pozitie angajat (UNKNOWN = 0 | JUNIOR = 1 | ENTRY_LEVEL = 2 | TEAM_LEADER = 3 | CEO = 4): ";
	}
	is >> optiunePozitie;
	switch (optiunePozitie)
	{
	case 0:
		manager.id_Pozitie = Pozitie::UNKNOWN;
		break;
	case 1:
		manager.id_Pozitie = Pozitie::JUNIOR;
		break;
	case 2:
		manager.id_Pozitie = Pozitie::ENTRY_LEVEL;
		break;
	case 3:
		manager.id_Pozitie = Pozitie::TEAM_LEADER;
		break;
	case 4:
		manager.id_Pozitie = Pozitie::CEO;
		break;
	default:
		manager.id_Pozitie = Pozitie::UNKNOWN;
		break;
	}
	if (&is == &cin)
	{
		cout << ">>>>Introduceti ID angajat: ";
	}
	is >> manager.id_UnicAngajat;
	if (&is == &cin)
	{
		cout << ">>>>Introduceti salariu angajat (RON): ";
	}
	is >> manager.salariuAngajat;
	is.ignore(100, '\n');
	if (&is == &cin)
	{
		cout << ">>>>Introduceti adresa : ";
	}
	is.getline(buffer, 100);
	if (manager.detaliiAngajat.adresa != nullptr)
	{
		delete[] manager.detaliiAngajat.adresa;
	}
	manager.detaliiAngajat.adresa = new char[strlen(buffer) + 1];
	strcpy_s(manager.detaliiAngajat.adresa, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti email: ";
	}
	is.getline(buffer, 100);
	if (manager.detaliiAngajat.email != nullptr)
	{
		delete[] manager.detaliiAngajat.email;
	}
	manager.detaliiAngajat.email = new char[strlen(buffer) + 1];
	strcpy_s(manager.detaliiAngajat.email, strlen(buffer) + 1, buffer);
	if (&is == &cin)
	{
		cout << ">>>>Introduceti main Task(TASK_UNKNOWN = 0 | PRODUCTIE = 1 | VANZARI = 2 |MARKETING = 3): ";
	}
	is >> optiuneTask;
	switch (optiuneTask)
	{
	case 0:
		manager.m_task = MainTask::TASK_UNKNOWN;
		break;
	case 1:
		manager.m_task = MainTask::PRODUCTIE;
		break;
	case 2:
		manager.m_task = MainTask::VANZARI;
		break;
	case 3:
		manager.m_task = MainTask::MARKETING;
		break;
	default:
		manager.m_task = MainTask::TASK_UNKNOWN;
		break;
	}
	if (&is == &cin)
	{
		cout << "=====================================================================" << endl << endl;
	}
	is.ignore(100, '\n');
	return is;
}
ostream& operator<<(ostream& os, Manager& manager)
{
	os << "=====================================================================" << endl;
	os << "                            >Afisare Manager<                        " << endl;
	os << "=====================================================================" << endl;
	os << "--->Detalii Angajat." << endl;
	if (manager.NumeAngajat != nullptr)
	{
		os << "\tNumele angajatului: " << manager.returnNumeAngajat() << "." << endl;
	}
	else
	{
		os << "\tNumele angajatului: - " << endl << endl;
	}
	os << "\tGradul angajatului: ";
	switch (manager.id_Pozitie)
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
	os << "\tID-ul angajatului: " << manager.returnid_UnicAngajat() << "." << endl;
	os << "\tSalariul angajatului: " << manager.returnSalariu() << " RON." << endl;
	if (manager.detaliiAngajat.adresa != nullptr)
	{
		os << "\tAdresa angajatului: " << manager.returnAdresa() << "." << endl;
	}
	else
	{
		os << "\tAdresa angajatului: - " << endl << endl;
	}

	if (manager.detaliiAngajat.email != nullptr)
	{
		os << "\tEmail-ul angajatul: " << manager.returnEmail() << "." << endl;
	}
	else
	{
		os << "\tEmail-ul angajatul: - " << endl << endl;
	}
	os << "------->Detalii Manager." << endl;
	os << "\tMain Task: ";
	switch (manager.m_task)
	{
	case MainTask::TASK_UNKNOWN:
		os << "TASK_UNKNOWN." << endl;
		break;
	case MainTask::PRODUCTIE:
		os << "PRODUCTIE." << endl;
		break;
	case MainTask::VANZARI:
		os << "VANZARI." << endl;
		break;
	case MainTask::MARKETING:
		os << "MARKETING." << endl;
		break;
	}
	os << "=====================================================================" << endl << endl;
	return os;
}

void Manager::ChangeTask(int newTask)
{
	switch (newTask)
	{
	case 0:
		this->m_task = MainTask::TASK_UNKNOWN;
		break;
	case 1:
		this->m_task = MainTask::PRODUCTIE;
		break;
	case 2:
		this->m_task = MainTask::VANZARI;
		break;
	case 3:
		this->m_task = MainTask::MARKETING;
		break;
	default:
		this->m_task = MainTask::TASK_UNKNOWN;
		break;
	}
}