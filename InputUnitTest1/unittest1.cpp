#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Wordlist/InputHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InputUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// 正确_1
			int argc = 5;
			char* argv[101] = {"Wordlist.exe", "-t", "a", "-w", "test_1.txt"};
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);

			Assert::AreEqual(enable_loop, false);
			Assert::AreEqual(word_or_char, 1);
			Assert::AreEqual(head, char(0));
			Assert::AreEqual(tail, 'a');
			Assert::AreEqual(Filename, (string)"test_1.txt");
		}

		TEST_METHOD(TestMethod2)
		{
			// 正确_2
			int argc = 6;
			char* argv[101] = { "Wordlist.exe", "-r", "-h", "a", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);

			Assert::AreEqual(enable_loop, true);
			Assert::AreEqual(word_or_char, 2);
			Assert::AreEqual(head, 'a');
			Assert::AreEqual(tail, char(0));
			Assert::AreEqual(Filename, (string)"test_1.txt");
		}

	};
}