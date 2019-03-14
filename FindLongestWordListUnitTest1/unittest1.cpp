#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Wordlist/FindLongestWordList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FindLongestWordListUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: normal_test1
			char* words[101] = { "algebra", "apple", "zoo", "elephant", "under", "fox", "dog", "moon", "leaf", "trick", "pseudopseudohypoparathyroidism" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char)*601);
			}

			int l = gen_chain_word(words, 11, answer, 'a', 0, false);
			Assert::AreEqual(l, 4);
			Assert::AreEqual("algebra", answer[0]);
			Assert::AreEqual("apple", answer[1]);
			Assert::AreEqual("elephant", answer[2]);
			Assert::AreEqual("trick", answer[3]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: normal_test2
			char* words[101] = { "algebra", "apple", "zoo", "elephant", "under", "fox", "dog", "moon", "leaf", "trick", "pseudopseudohypoparathyroidism" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_char(words, 11, answer, 0, 0, false);
			Assert::AreEqual(l, 2);
			Assert::AreEqual("pseudopseudohypoparathyroidism", answer[0]);
			Assert::AreEqual("moon", answer[1]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: normal_test3
			char* words[101] = { "element", "heaven", "table", "teach", "talk"};
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_word(words, 5, answer, 0, 0, true);
			Assert::AreEqual(l, 4);
			Assert::AreEqual("table", answer[0]);
			Assert::AreEqual("element", answer[1]);
			Assert::AreEqual("teach", answer[2]);
			Assert::AreEqual("heaven", answer[3]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: normal_test4 
			char* words[101] = { "element", "heaven", "table", "teach", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_char(words, 5, answer, 0, 0, true);
			Assert::AreEqual(l, 4);
			Assert::AreEqual("table", answer[0]);
			Assert::AreEqual("element", answer[1]);
			Assert::AreEqual("teach", answer[2]);
			Assert::AreEqual("heaven", answer[3]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: normal_test5
			char* words[101] = { "apple", "banane", "cane", "a", "papa", "erase" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_word(words, 6, answer, 0, 'e', false);
			Assert::AreEqual(l, 4);
			Assert::AreEqual("papa", answer[0]);
			Assert::AreEqual("a", answer[1]);
			Assert::AreEqual("apple", answer[2]);
			Assert::AreEqual("erase", answer[3]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: normal_test6
			char* words[101] = { "apple", "banane", "cane", "a", "papa", "erase" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_char(words, 6, answer, 'a', 'e', false);
			Assert::AreEqual(l, 3);
			Assert::AreEqual("a", answer[0]);
			Assert::AreEqual("apple", answer[1]);
			Assert::AreEqual("erase", answer[2]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: normal_test7
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_word(words, 5, answer, 'a', 0, true);
			Assert::AreEqual(l, 3);
			Assert::AreEqual("alement", answer[0]);
			Assert::AreEqual("teaco", answer[1]);
			Assert::AreEqual("oeaven", answer[2]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

 		TEST_METHOD(TestMethod8)
		{
			// TODO: normal_test8
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			int l = gen_chain_char(words, 5, answer, 0, 'n', true);
			Assert::AreEqual(l, 4);
			Assert::AreEqual("tabla", answer[0]);
			Assert::AreEqual("alement", answer[1]);
			Assert::AreEqual("teaco", answer[2]);
			Assert::AreEqual("oeaven", answer[3]);
			for (int i = 0; i < 101; i++)
			{
				free(answer[i]);
			}
		}

		TEST_METHOD(TestMethod9)
		{
			// wrong_test1
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}

			
			try {
				int l = gen_chain_word(words, 5, answer, 0, 'n', false);
				Assert::IsTrue(false);
			}
			catch (myexception7& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod10)
		{
			// wrong_test2
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}


			try {
				int l = gen_chain_char(words, 5, answer, 0, 'n', false);
				Assert::IsTrue(false);
			}
			catch (myexception7& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod11)
		{
			// wrong_test3
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}


			try {
				int l = gen_chain_word(words, 5, answer, 'b', 'n', true);
				Assert::IsTrue(false);
			}
			catch (myexception8& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod12)
		{
			// wrong_test4
			char* words[101] = { "alement", "oeaven", "bablu", "peacl", "yalk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}


			try {
				int l = gen_chain_char(words, 5, answer, 0, 'n', false);
				Assert::IsTrue(false);
			}
			catch (myexception8& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod13)
		{
			// wrong_test5
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}


			try {
				int l = gen_chain_word(words, 5, answer, '1', 'n', true);
				Assert::IsTrue(false);
			}
			catch (myexception2& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod14)
		{
			// wrong_test6
			char* words[101] = { "alement", "oeaven", "tabla", "teaco", "talk" };
			char* answer[101];
			for (int i = 0; i < 101; i++)
			{
				answer[i] = (char*)malloc(sizeof(char) * 601);
			}


			try {
				int l = gen_chain_char(words, 5, answer, 'b', '.', false);
				Assert::IsTrue(false);
			}
			catch (myexception2& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

	};
}