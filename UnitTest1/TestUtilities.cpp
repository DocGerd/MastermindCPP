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
			std::wstring actual = mastermind::shell::utilities::Utilities::createAlphabet();

			Assert::AreEqual(actual, expected, L"", LINE_INFO());
		}

		TEST_METHOD(TestParseString)
		{
			std::wstring str = L"12 29 1 0";
			std::list<std::size_t> list = mastermind::shell::utilities::Utilities::parseString(str);
			Assert::AreEqual(static_cast<size_t>(4), list.size(), L"", LINE_INFO());
			size_t size = list.size();
			std::size_t* tokens = new std::size_t[size];
			for (std::size_t i = 0; i < size; ++i)
			{
				tokens[i] = list.front();
				list.pop_front();
			}

			Assert::AreEqual((std::size_t)12, tokens[0], L"", LINE_INFO());
			Assert::AreEqual((std::size_t)29, tokens[1], L"", LINE_INFO());
			Assert::AreEqual((std::size_t)1, tokens[2], L"", LINE_INFO());
			Assert::AreEqual((std::size_t)0, tokens[3], L"", LINE_INFO());
		}

		TEST_METHOD(TestParseStringFail)
		{
			std::wstring str = L"12 a 1 0";
			std::list<std::size_t> list = mastermind::shell::utilities::Utilities::parseString(str);
			Assert::AreEqual(static_cast<size_t>(3), list.size(), L"", LINE_INFO());
		}

		TEST_METHOD(TestRandomCode)
		{
			mastermind::logic::ColorCode random = mastermind::shell::utilities::Utilities::createRandomCode();
			Assert::IsTrue(true, L"", LINE_INFO());
		}
	};
}
