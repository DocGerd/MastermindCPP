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
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);
		}

		TEST_METHOD(TestGet)
		{
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);

			Assert::AreEqual(4, cc.get(3), L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr1)
		{
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);
			std::size_t result = cc[3];

			Assert::AreEqual((std::size_t)4, result, L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorArr2)
		{
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);
			const ColorCode& c2 = cc;
			std::size_t result = c2[3];

			Assert::AreEqual((std::size_t)4, result, L"", LINE_INFO());
		}

		TEST_METHOD(TestOperatorEq)
		{
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);
			const ColorCode& c2 = cc;
			ColorCode c3(cols);

			Assert::IsTrue(c2 == c3, L"", LINE_INFO());

			std::array<std::size_t, 4> cols2 = {5, 6, 7, 8};
			ColorCode c4(cols2);
			Assert::IsFalse(c2 == c4, L"", LINE_INFO());
		}

		TEST_METHOD(TestToString)
		{
			std::array<std::size_t, 4> cols = {1, 2, 3, 4};
			ColorCode cc(cols);

			std::wstring expected(L"1 2 3 4 ");

			Assert::AreEqual(expected, cc.toString(), L"", LINE_INFO());
		}
	};
}
