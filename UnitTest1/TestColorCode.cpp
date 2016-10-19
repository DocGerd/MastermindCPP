#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MastermindCPPDLL/ColorCode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(TestColorCode)
	{
	public:
		
		TEST_METHOD(TestCstr)
		{
			std::array<int, 4> cols = { 1, 2, 3, 4 };
			mastermind::ColorCode cc(cols);
		}

		TEST_METHOD(TestGet)
		{
			std::array<int, 4> cols = { 1, 2, 3, 4 };
			mastermind::ColorCode cc(cols);

			Assert::AreEqual(4, cc.get(3), L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr1)
		{
			std::array<int, 4> cols = { 1, 2, 3, 4 };
			mastermind::ColorCode cc(cols);
			int result = cc[3];

			Assert::AreEqual(4, result, L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr2)
		{
			std::array<int, 4> cols = { 1, 2, 3, 4 };
			mastermind::ColorCode cc(cols);
			const mastermind::ColorCode &c2 = cc;
			int result = c2[3];

			Assert::AreEqual(4, result, L"", LINE_INFO());
		}

		TEST_METHOD(TestToString)
		{
			std::array<int, 4> cols = { 1, 2, 3, 4 };
			mastermind::ColorCode cc(cols);

			std::wstring expected(L"1 2 3 4 ");

			Assert::AreEqual(expected, cc.toString(), L"", LINE_INFO());
		}
	};
}