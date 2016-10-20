#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Utilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestUtilities)
	{
	public:
		TEST_METHOD(TestCreateAlphabet)
		{
			std::wstring expected = L"a b c d";
			std::wstring actual = mastermind::shell::utilities::createAlphabet();

			Assert::AreEqual(actual, expected, L"", LINE_INFO());
		}

		TEST_METHOD(TestParseString)
		{
			std::wstring str = L"12 29 1 0";
			std::list<int> list = mastermind::shell::utilities::parseString(str);
			Assert::AreEqual((size_t)4, list.size(), L"", LINE_INFO());
			size_t size = list.size();
			int* tokens = new int[size];
			for (std::size_t i = 0; i < size; ++i) {
				tokens[i] = list.front();
				list.pop_front();
			}

			Assert::AreEqual(12, tokens[0], L"", LINE_INFO());
			Assert::AreEqual(29, tokens[1], L"", LINE_INFO());
			Assert::AreEqual(1, tokens[2], L"", LINE_INFO());
			Assert::AreEqual(0, tokens[3], L"", LINE_INFO());
		}
	};
}