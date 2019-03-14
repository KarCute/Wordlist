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
			// ÕýÈ·_1
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
			// ÕýÈ·_2
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

		TEST_METHOD(TestMethod3)
		{
			// ´íÎó_1
			int argc = 5;
			char* argv[101] = { "Wordlist.exe", "-r", "-r", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception1& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod4)
		{
			// ´íÎó_2
			int argc = 7;
			char* argv[101] = { "Wordlist.exe", "-h", "a", "-h", "b", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception1& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod5)
		{
			// ´íÎó_3
			int argc = 5;
			char* argv[101] = { "Wordlist.exe", "-w", "test_1.txt", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception1& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod6)
		{
			// ´íÎó_4
			int argc = 4;
			char* argv[101] = { "Wordlist.exe", "-r", "-t", "c"};
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception1& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod7)
		{
			// ´íÎó_5
			int argc = 6;
			char* argv[101] = { "Wordlist.exe", "-r", "-h", "1", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception2& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod8)
		{
			// ´íÎó_6
			int argc = 6;
			char* argv[101] = { "Wordlist.exe", "-r", "-t", "aa", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception2& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod9)
		{
			// ´íÎó_7
			int argc = 5;
			char* argv[101] = { "Wordlist.exe", "-b", "-r", "-c", "test_1.txt" };
			char head;
			char tail;
			bool enable_loop;
			int word_or_char = 0;
			string Filename;
			try {
				InputHandler(argc, argv, enable_loop, word_or_char, head, tail, Filename);
				Assert::IsTrue(false);
			}
			catch (myexception3& e) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::IsTrue(false);
			}
		}

	};
}