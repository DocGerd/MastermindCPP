#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MastermindCPPDLL/ColorCode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace UnitTest1
{
	TEST_CLASS(TestColorCode)
	{
	public:

		TEST_METHOD(TestCstr)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);
		}

		TEST_METHOD(TestGet)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);

			Assert::AreEqual(static_cast<color_t>(4), cc.get(3), L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr1)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);
			color_t result = cc[3];

			Assert::AreEqual(static_cast<color_t>(4), result, L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr2)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);
			const ColorCode& c2 = cc;
			color_t result = c2[3];

			Assert::AreEqual(static_cast<color_t>(4), result, L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorEq)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);
			const ColorCode& c2 = cc;
			ColorCode c3(cols);

			Assert::IsTrue(c2 == c3, L"", LINE_INFO());

			std::vector<color_t> cols2 = { 5, 6, 7, 8 };
			ColorCode c4(cols2);
			Assert::IsFalse(c2 == c4, L"", LINE_INFO());
		}

		TEST_METHOD(TestToString)
		{
			std::vector<color_t> cols = { 1, 2, 3, 4 };
			ColorCode cc(cols);

			std::wstring expected(L"1 2 3 4 ");

			Assert::AreEqual(expected, cc.toString(), L"", LINE_INFO());
		}
	};
}
