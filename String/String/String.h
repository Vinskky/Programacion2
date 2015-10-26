#ifndef _String_H_
#define _String_H_

typedef unsigned int uint;

class String
{
private:
	char* str;
	uint capacity;

public:
	String(){};
	String(String& str){}
	String(char* str){}
	String(const uint capacity){}

	~String(){};

	const char* C_str(){}

};



#endif