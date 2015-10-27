#include <iostream>
#include "String.h"

String::String() : str(NULL), capacity(NULL){}

String::String(String& str)
{
	capacity = str.capacity;
	str = new char[capacity];	
}

String::String(char* str)
{
	char* tmp;
	*tmp = *str;
	while (tmp != '\0')
	{
		capacity++;
		tmp++;
	}
}
String::String(uint cap): capacity(cap)
{
	str = new char[capacity];
}

String::~String()
{
	delete str;
	capacity = 0;
};
bool String::operator == (const String& a)
{
	if (str == a.str)
	{
		return true;
	}
	return false;
}

bool String::operator == (char* a)
{
	if (a == NULL)
		return false;
	char* tmp, *tmp2;
	*tmp = *a;
	*tmp2 = *str;
	while(tmp == tmp2)
	{
		tmp++;
		tmp2++;
		if (*tmp == '\0' && *tmp2 == '\0')
			return true;
	}
	return false;
}

bool String::operator += (String& a)
{

}

bool String::operator += (char* a)
{

}
const char* String::C_str(){ return str; };