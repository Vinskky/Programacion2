//Clase cadena la cual no tindrà dependencia de la llargada de les possibles cadenes.

#include <Windows.h>
#include <stdio.h>
#include <assert.h>

class Cadena
{
private:
	char* cadena;
	int tamany;

public:
	Cadena()
	{ 
		tamany = 1;
		cadena = new char[tamany];
		cadena[0] = '\0';
	}
	Cadena(const char*c)
	{
		tamany = strlen(c)+1;
		cadena = new char[tamany];
		strcpy s(cadena, c);

	}
	Cadena(const Cadena&)
	{ 
	
	
	}

	String(const char* format, ...){ }

	String(const String&){ }

	~Cadena()
	{ 
		
		delete[] cadena; //si es fa servir new amb [] el delete portarè []

	}
		//return len() const(cadena); // retorna el tamany de la cadena
};