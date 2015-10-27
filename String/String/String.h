#ifndef _String_H_
#define _String_H_
#define ALLOC 100
typedef unsigned int uint;

class String
{
private:
	char* str;
	uint capacity;

	void Realloc()
	{
		capacity += ALLOC;
		str[capacity];
	}
public:
	String(){};
	String(String& str){}
	String(char* str){}
	String(const uint capacity){}

	~String(){};

	bool operator == (const String& a)
	{

	}

	bool operator == (char* a)
	{

	}

	bool operator += (String& a)
	{

	}

	bool operator += (char* a)
	{

	}
	const char* C_str(){}

};



#endif