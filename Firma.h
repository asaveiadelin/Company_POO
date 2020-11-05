#pragma once
#include "Angajat.h";
#include "Programator.h"
#include "Manager.h"

enum class TipAngajat
{
	PROGRAMATOR=1,
	MANAGER=2
};
class Firma
{
public:
	static Angajat* CreareAngajat(TipAngajat tip);
};

