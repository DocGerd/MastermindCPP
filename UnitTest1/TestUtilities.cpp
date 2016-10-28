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
			std::wstring actual = mastermind::shell::utilities::Utilities::createAlphabet(4);

			Assert::AreEqual(actual, expected, L"", LINE_INFO());
		}

		TEST_METHOD(TestParseString)
		{
			std::wstring str = L"12 29 1 0";
			std::list<int*> list = mastermind::shell::utilities::Utilities::parseString(str);
			Assert::AreEqual(static_cast<size_t>(4), list.size(), L"", LINE_INFO());
			size_t size = list.size();

			Assert::AreEqual(static_cast<std::size_t>(12), static_cast<size_t>(*list.front()), L"", LINE_INFO());
			list.pop_front();
			Assert::AreEqual(static_cast<std::size_t>(29), static_cast<size_t>(*list.front()), L"", LINE_INFO());
			list.pop_front();
			Assert::AreEqual(static_cast<std::size_t>(1), static_cast<size_t>(*list.front()), L"", LINE_INFO());
			list.pop_front();
			Assert::AreEqual(static_cast<std::size_t>(0), static_cast<size_t>(*list.front()), L"", LINE_INFO());
			list.pop_front();
		}

		TEST_METHOD(TestParseStringFail)
		{
			std::wstring str = L"12 a 1 0";
			std::list<int*> list = mastermind::shell::utilities::Utilities::parseString(str);
			Assert::AreEqual(static_cast<size_t>(3), list.size(), L"", LINE_INFO());
		}

		TEST_METHOD(TestRandomCode)
		{
			mastermind::logic::ColorCode *random = mastermind::shell::utilities::Utilities::createRandomCode(4, 6);
			Assert::IsNotNull(random, L"", LINE_INFO());
		}
	};
}
