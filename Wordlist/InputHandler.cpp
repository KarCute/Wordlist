#include "pch.h"
#include "Error.h"

void InputHandler(int argc, char* argv[], bool &enable_loop, int &word_or_char, char &head, char &tail, string &Filename)
{
	int i = 1;
	enable_loop = false;
	word_or_char = 0;
	head = 0;
	tail = 0;
	for(int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-r"))
		{
			if (enable_loop)
			{
				throw myexception1();
			}
			enable_loop = true;
		}
		else if (!strcmp(argv[i], "-h"))
		{
			if (head != 0)
			{
				throw myexception1();
			}
			i++;
			// Is the char legal
			if (strlen(argv[i]) > 1 || isalpha(argv[i][0]) == 0)
			{
				throw myexception2();
			}
			head = argv[i][0];
		}
		else if (!strcmp(argv[i], "-t"))
		{
			if (tail!= 0)
			{
				throw myexception1();
			}
			i++;
			// Is the char legal
			if (strlen(argv[i]) > 1 || isalpha(argv[i][0]) == 0)
			{
				throw myexception2();
			}
			tail = argv[i][0];
		}
		else if (!strcmp(argv[i], "-w"))
		{
			i++;
			if (word_or_char != 0)
			{
				throw myexception1();
			}
			word_or_char = 1;
			Filename = argv[i];
		}
		else if (!strcmp(argv[i], "-c"))
		{
			i++;
			if (word_or_char != 0)
			{
				throw myexception1();
			}
			word_or_char = 2;
			Filename = argv[i];
		}
		else
		{
			throw myexception3();
		}
	}
	if (word_or_char == 0)
	{
		throw myexception1();
	}
	head = tolower(head);
	tail = tolower(tail);
}