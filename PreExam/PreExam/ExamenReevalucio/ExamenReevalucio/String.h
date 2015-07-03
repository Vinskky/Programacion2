#ifndef _String_H_
#define _String_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TMP_STRING_SIZE	4096


class String
{
private:
	char* string;
	unsigned int size;

	void Alloc(unsigned int newSize)
	{
		size = newSize;
		String* str = new String[size];
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
			Alloc(newSize);
		else
			Alloc(1);
		Clear();
	}

	String(const String& str)
	{
		Alloc(*str.string);
		strcpy_s(string, size, str.string);
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
				strcpy_s(string, size, tmp);
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
		if (strlen(str.string) + 1 > size)
		{
			delete[] string;
			Alloc(strlen(str.string) + 1);
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
		unsigned int need_size = strlen(str.string) + strlen(string) + 1;

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
	/*

	const String& prefix(const char* str)
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
	for (int i = 0; i > str->size; i++)
	{

	}
	}


	}
	return(*this);
	}

	*/
	void Clear()
	{
		string[0] = '\0';
	}

	/*//void Trim()
	{
		//char* end = string;
		//cutRight
		//while (*--end != ' ') end = '\0';
		bool a;
		//Right Cut
		for (int i = size - 1; i > 0 && a == false; i--)
		{
			if (string[i] = ' ')
			{
				string[i] = '\0';
				a = false;
			}
			else
			{
				a = true;
			}
		}
		a = false;
		for (int z = 0; z < size - 1 && a == false; z++)
		{
			if (string[z] == ' ') string[z] = '\0';
			else a = true;
		}
	}

	//void SubString(const String& WordToChange, const String& WordSub)const
	{
		int countWordsToChange, startString;
		bool checker = true;
		//counting number of words to change
		for (int i = 0; i < this->size - 1; i++)
		{
			for (int z = 0; z < WordToChange.size - 1 && checker == true; z++)
			{
				if (this->string[i] != WordToChange.string[z])
					checker = false;
			}
			if (checker == true)
			{
				countWordsToChange++;
			}

		}


	}*/

	/*
	EXAMEN REEVALUCIO
	*/
	int DoubleVocals()
	{
		int counter = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (string[i] == 'a')
			{
				counter++;
				AddVocal('a', i++);
			}
			else if (string[i] == 'A')
			{
				counter++;
				AddVocal('A', i++);
			}
			else if (string[i] == 'e')
			{
				counter++;
				AddVocal('e', i++);
			}
			else if (string[i] == 'E')
			{
				counter++;
				AddVocal('E', i++);
			}
			else if (string[i] == 'i')
			{
				counter++;
				AddVocal('i', i++);
			}
			else if (string[i] == 'I')
			{
				counter++;
				AddVocal('I', i++);
			}
			else if (string[i] == 'o')
			{
				counter++;
				AddVocal('o', i++);
			}
			else if (string[i] == 'O')
			{
				counter++;
				AddVocal('O', i++);
			}
			else if (string[i] == 'u')
			{
				counter++;
				AddVocal('u', i++);
			}
			else if (string[i] == 'U')
			{
				counter++;
				AddVocal('U', i++);
			}
		}
		return counter;
	}

	void AddVocal(char character, int position )
	{
		for (int i = position; i < size - 1; i++)
		{
			string[i] = string[i++];
		}
		string[position] = character;
	}
};

#endif _String_H_