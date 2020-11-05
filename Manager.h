#pragma once
#include "Angajat.h"

enum class MainTask {
	TASK_UNKNOWN = 0,
	PRODUCTIE = 1,
	VANZARI = 2,
	MARKETING = 3
};

class Manager:public Angajat
{
private: 
	MainTask m_task;

public:
	Manager();
	Manager(const char* NumeAngajat, double salariuAngajat, DetaliiPersonale detaliiAngajat, int id_UnicAngajat, Pozitie id_Pozitie, MainTask m_task);
	Manager(const Manager& sursa);
	~Manager();

	void Citire(istream& is);
	void Afisare(ostream& os);
	
	Manager& operator=(const Manager& manager);
	friend ostream& operator<<(ostream& os, Manager& manager);
	friend istream& operator>>(istream& is, Manager& manager);

	void ChangeTask(int newTask);
};

