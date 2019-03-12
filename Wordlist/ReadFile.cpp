#include "pch.h"
#include "ReadFile.h"

void ReadFile(string FileName, vector<string> &words)
{
	int i = 0;
	char letter = '\0';
	char word[600];
	memset(word, '\0', sizeof(word));

	ifstream pin(FileName);
	if (!pin)
	{
		cout << "Error! there is no such file '" << FileName << "' !" << endl;
		exit(0);
	}
	while (pin.peek() != EOF)
	{
		pin.get(letter);
		if (isalpha(letter))
		{
			if (i == 600)
			{
				cout << "sorry! I don't think there is a such long word" << endl;
				cout << "current word: " << word << endl;
				exit(0);
			}
			word[i++] = tolower(letter);
		}
		else
		{
			if (word[0] != '\0')
			{
				words.push_back(word);
				memset(word, '\0', sizeof(word));
				i = 0;
			}
		}
	}
	if (word[0] != '\0')
	{
		words.push_back(word);
	}
	pin.close();
	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());

	if (words.size() > 10000)
	{
		cout << "There are more words than required.";
		exit(0);
	}
}

int headTailHash[26][26] = { 0 };
string longest[26][26];
void ReduceWords(vector<string> &words)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			longest[i][j] = "";
		}
	}

	while (!words.empty())
	{
		string s = words.back();
		words.pop_back();
		int head = s[0] - 'a';
		int tail = s[s.length() - 1] - 'a';
		if (headTailHash[head][tail] == 0)
		{
			headTailHash[head][tail] = s.length();
			longest[head][tail] = s;
		}
		else
		{
			if (head == tail)
			{
				cout << "Invalid File! The words can form words ring." << endl;
				exit(0);
			}
			else if (headTailHash[head][tail] < int(s.length()))
			{
				headTailHash[head][tail] = s.length();
				longest[head][tail] = s;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (headTailHash[i][j] != 0)
			{
				words.push_back(longest[i][j]);
			}
		}
	}
}