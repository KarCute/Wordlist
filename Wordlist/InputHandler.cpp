#include "pch.h"
#include "InputHandler.h"

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
				cout << "Wrong parameter! Wrong parameter combination." << endl;
				exit(0);
			}
			enable_loop = true;
		}
		else if (!strcmp(argv[i], "-h"))
		{
			if (head != 0)
			{
				cout << "Wrong parameter! Wrong parameter combination." << endl;
				exit(0);
			}
			i++;
			// Is the char legal
			if (strlen(argv[i]) > 1 || isalpha(argv[i][0]) == 0)
			{
				cout << "Wrong parameter! The parameter does not meet the specifications." << endl;
				exit(0);
			}
			head = argv[i][0];
		}
		else if (!strcmp(argv[i], "-t"))
		{
			if (tail!= 0)
			{
				cout << "Wrong parameter! Wrong parameter combination." << endl;
				exit(0);
			}
			i++;
			// Is the char legal
			if (strlen(argv[i]) > 1 || isalpha(argv[i][0]) == 0)
			{
				cout << "Wrong parameter! The parameter does not meet the specifications." << endl;
				exit(0);
			}
			tail = argv[i][0];
		}
		else if (!strcmp(argv[i], "-w"))
		{
			i++;
			if (word_or_char != 0)
			{
				cout << "Wrong parameter! Wrong parameter combination." << endl;
				exit(0);
			}
			word_or_char = 1;
			Filename = argv[i];
		}
		else if (!strcmp(argv[i], "-c"))
		{
			i++;
			if (word_or_char != 0)
			{
				cout << "Wrong parameter! Wrong parameter combination." << endl;
				exit(0);
			}
			word_or_char = 2;
			Filename = argv[i];
		}
		else
		{
			cout << "Wrong parameter! The parameter does not meet the specifications." << endl;
			exit(0);
		}
	}
	if (word_or_char == 0)
	{
		cout << "Wrong parameter! The parameter does not meet the specifications." << endl;
		exit(0);
	}
	head = tolower(head);
	tail = tolower(tail);
}