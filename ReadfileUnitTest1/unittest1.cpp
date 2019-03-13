#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Wordlist/ReadFile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReadfileUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			vector <string> words;
			ReadFile("normal_test.txt", words);
			Assert::AreEqual((string)"algebra", words[0]);
			Assert::AreEqual((string)"apple", words[1]);
			Assert::AreEqual((string)"dog", words[2]);
			Assert::AreEqual((string)"elephant", words[3]);
			Assert::AreEqual((string)"fox", words[4]);
			Assert::AreEqual((string)"leaf", words[5]);
			Assert::AreEqual((string)"moon", words[6]);

		}

	};
}