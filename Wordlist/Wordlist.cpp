// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "ReadFile.h"
#include "FindLongestWordList.h"
#include "InputHandler.h"

//Command line input
int main(int argc, char* argv[])
{
	char head;
	char tail;
	bool enable_loop;
	int word_or_char = 0;
	string Filename;
	vector<string> words;
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

	if (length < 2)
	{
		cout << "Invalid File! There is no word list in the file." << endl;
		exit(0);
	}
	
	for (int i = 0; i < length; i++)
	{
		outfile << ans[i] << endl;
	}

	outfile.close();
	return 0;
}

//int main()
//{
//	vector<string> words;
//	words = { "algebra", "apple", "zoo", "elephant", "under", "fox", "dog", "moon", "leaf", "trick", "pseudopseudohypoparathyroidism" };
//	//ReadFile("circle_1.txt", words);
//	cout << words.size() << endl;
//	for (int i = 0; i < words.size(); i++)
//	{
//		cout << words[i] << endl;
//	}
//	cout << endl;
//
//	//ReduceWords(words);
//	//cout << words.size() << endl;
//	//for (int i = 0; i < words.size(); i++)
//	//{
//	//	cout << words[i] << endl;
//	//}
//	//cout << endl;
//	Graph G = CreateGraph(words);
//
//	if (!G->hasList)
//	{
//		cout << "Invalid File! There is no word list in the file." << endl;
//		exit(0);
//	}
//	PrintGraph(G);
//	//hasCircle(G, 0);
//	//if (G->withCircle)
//	//{
//	//	cout << "Invalid File! The words can form words ring." << endl;
//	//	exit(0);
//	//}
//	//cout << " no ring";
//	vector<string> ans;
//	int l = getListWithWord(words, words.size(), ans, 'a', 0, false);
//	//int l = getListWithWord(G, words, ans, 0, 0);
//	cout << l << endl;
//	cout << endl;
//	cout << endl;
//	//l = getListWithLength(G, words, ans, 0, 0);
//	//cout << l << endl;
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
