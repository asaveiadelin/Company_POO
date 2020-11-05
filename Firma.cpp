#include "Firma.h"
Angajat* Firma::CreareAngajat(TipAngajat tip)
{
	Angajat* x = nullptr;
	switch (tip)
	{
	case TipAngajat::PROGRAMATOR:
		x = new Programator();
		break;
	case TipAngajat::MANAGER:
		x = new Manager();
		break;
	default:
		break;
	}
	return x;
}