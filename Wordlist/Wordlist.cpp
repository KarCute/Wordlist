// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "ReadFile.h"
#include "FindLongestWordList.h"
#include "InputHandler.h"
#include <assert.h>

//Command line input
int main(int argc, char* argv[])
{
	char head;
	char tail;
	bool enable_loop;
	int word_or_char = 0;
	string Filename;
	vector<string> words;
	try {
		InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
		ReadFile(Filename, words);

		ofstream outfile;
		outfile.open("solution.txt");

		if (!outfile.is_open())
		{
			cout << "can't open file solution.txt!" << endl;
			exit(0);
		}

		vector<string> ans;
		int length = 0;
		if (word_or_char == 1)
		{
			length = getListWithWord(words, words.size(), ans, head, tail, enable_loop);
		}
		else if (word_or_char == 2)
		{
			length = getListWithLength(words, words.size(), ans, head, tail, enable_loop);
		}

		for (int i = 0; i < length; i++)
		{
			outfile << ans[i] << endl;
		}

		outfile.close();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

//Unit Test Coverage
//int main()
//{
//	vector <string> word;
//	ReadFile("normal_test.txt", word);
//	char* words[101]; // { "algebra", "apple", "zoo", "elephant", "under", "fox", "dog", "moon", "leaf", "trick", "pseudopseudohypoparathyroidism" };
//	char* answer[101];
//	for (int i = 0; i < 101; i++)
//	{
//		answer[i] = (char*)malloc(sizeof(char) * 601);
//		words[i] = (char*)malloc(sizeof(char) * 601);
//	}
//
//	strcpy_s(words[0], 8, "algebra");
//	strcpy_s(words[1], 6, "apple");
//	strcpy_s(words[2], 4, "zoo");
//	strcpy_s(words[3], 9, "elephant");
//	strcpy_s(words[4], 6, "under");
//	strcpy_s(words[5], 4, "fox");
//	strcpy_s(words[6], 5, "anne");
//	strcpy_s(words[7], 5, "moon");
//	strcpy_s(words[8], 5, "leaf");
//	strcpy_s(words[9], 6, "trick");
//	strcpy_s(words[10], 31, "pseudopseudohypoparathyroidism");
//
//	int l = gen_chain_word(words, 11, answer, 0, 0, false);
//	l = gen_chain_word(words, 11, answer, 'a', 0, false); 
//	l = gen_chain_word(words, 11, answer, 0, 't', false);
//	l = gen_chain_word(words, 11, answer, 'a', 't', false);
//	l = gen_chain_char(words, 11, answer, 0, 0, false);
//	l = gen_chain_char(words, 11, answer, 'p', 0, false);
//	l = gen_chain_char(words, 11, answer, 0, 't', false);
//	l = gen_chain_char(words, 11, answer, 'a', 't', false);
//
//	strcpy_s(words[0], 8, "element");
//	strcpy_s(words[1], 7, "heaven");
//	strcpy_s(words[2], 6, "table");
//	strcpy_s(words[3], 6, "teach");
//	strcpy_s(words[4], 5, "talk");
//	l = gen_chain_word(words, 5, answer, 0, 0, true);
//	l = gen_chain_word(words, 5, answer, 'e', 0, true);
//	l = gen_chain_word(words, 5, answer, 0, 'n', true);
//	l = gen_chain_word(words, 5, answer, 'e', 'n', true);
//	l = gen_chain_char(words, 5, answer, 't', 0, true);
//	l = gen_chain_char(words, 5, answer, 0, 'n', true);
//	l = gen_chain_char(words, 5, answer, 't', 'n', true);
//	l = gen_chain_char(words, 5, answer, 0, 0, true);
//
//
//	int argc = 5;
//	strcpy_s(words[0], 13, "Wordlist.exe");
//	strcpy_s(words[1], 3, "-t");
//	strcpy_s(words[2], 2, "a");
//	strcpy_s(words[3], 3, "-w");
//	strcpy_s(words[4], 11, "test_1.txt");
//	char head;
//	char tail;
//	bool enable_loop;
//	int word_or_char = 0;
//	string Filename;
//	InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//
//	strcpy_s(words[1], 3, "-t");
//	strcpy_s(words[2], 2, "a");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//
//	strcpy_s(words[1], 3, "-r");
//	strcpy_s(words[2], 3, "-r");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	strcpy_s(words[1], 3, "-h");
//	strcpy_s(words[2], 2, "1");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	strcpy_s(words[1], 3, "-t");
//	strcpy_s(words[2], 2, "1");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	strcpy_s(words[1], 3, "-t");
//	strcpy_s(words[2], 2, "a");
//	strcpy_s(words[3], 3, "-h");
//	strcpy_s(words[4], 2, "b");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//	strcpy_s(words[1], 3, "-w");
//	strcpy_s(words[2], 11, "test_1.txt");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	strcpy_s(words[1], 3, "-r");
//	strcpy_s(words[2], 3, "-b");
//	strcpy_s(words[3], 3, "-c");
//	strcpy_s(words[4], 11, "test_1.txt");
//	head = 0;
//	tail = 0;
//	enable_loop = false;
//	word_or_char = 0;
//	try
//	{
//		InputHandler(argc, words, enable_loop, word_or_char, head, tail, Filename);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	for (int i = 0; i < 101; i++)
//	{
//		free(answer[i]);
//		free(words[i]);
//	}
//	return 0;
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
