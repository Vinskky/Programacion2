#ifndef _String_H_
#define _String_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TMP_STRING_SIZE	4096

template <class TYPE0>
class String
{
private:
	char* string;
	unsigned int size;

	void Alloc(unsigned int newSize)
	{
		size = newSize;
		string = new string[size];
	}

public:
	//Constructors
	String()
	{
		Alloc(1);
		Clear();
	}
	String(unsigned int newSize)
	{
		if (size > 0)
			Alloc(newSize)
		else
			Alloc(1);
		Clear();
	}

	String(const String& str)
	{
		Alloc(str.string);
		strcpy_s(string, size, str);
	}

	String(const char *format, ...)
	{
		if (format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list  ap;

			// Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if (res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}
		if (size == 0)
		{
			Alloc(1);
			Clear();
		}
	}

	//Destructor
	~String()
	{
		if (string != NULL)
			delete[] string;
	}

	//Operators

	bool operator== (const String& str) const
	{
		return strcmp(str.string, string) == 0;
	}

	bool operator== (const char* str) const
	{
		if (str != NULL)
			return strcmp(str, string) == 0;
		return false;
	}

	bool operator!= (const String& str) const
	{
		return strcmp(str.string, string) != 0;
	}

	bool operator!= (const char* str) const
	{
		if (string != NULL)
			return strcmp(str, string) != 0;
		return true;
	}

	const String& operator= (const String& str)
	{
		if (strlen(str) + 1 > size)
		{
			delete[] string;
			Alloc(strlen(str) + 1);
		}
		else
			Clear();

		strcpy_s(string, size, str.string);

		return(*this);
	}

	const String& operator= (const char* str)
	{
		if (string != NULL)
		{
			if (strlen(str) + 1 > size)
			{
				delete[] string;
				Alloc(strlen(str) + 1);
			}
			else
				Clear();

			strcpy_s(string, size, str);
		}
		else
		{
			Clear();
		}

		return(*this);
	}

	const String& operator+= (const String& str)
	{
		unsigned int need_size = strlen(str) + strlen(string) + 1;

		if (need_size > size)
		{
			char* tmp = string;
			Alloc(need_size);
			strcpy_s(string, size, tmp);
			delete[] tmp;
		}

		strcat_s(string, size, str.string);

		return(*this);
	}

	const String& operator+= (const char* str)
	{
		if (str != NULL)
		{
			unsigned int need_size = strlen(str) + strlen(string) + 1;

			if (need_size > size)
			{
				char* tmp = string;
				Alloc(need_size);
				strcpy_s(string, size, tmp);
				delete[] tmp;
			}

			strcat_s(string, size, str);
		}

		return(*this);
	}

	void Clear()
	{
		string[0] = '\0';
	}

	
};

#endif _String_H_