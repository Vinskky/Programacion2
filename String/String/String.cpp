#include <iostream>
#include "String.h"

String::String(){}

String::String(String& str)
{
	
	
}

String::String(char* str)
{
	
}
String::String(const uint capacity){}

String::~String(){};

const char* String::C_str(){ return str; };