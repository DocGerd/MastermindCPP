#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MastermindCPPDLL/Color.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace UnitTest1
{
	TEST_CLASS(TestColor)
	{
	public:
		TEST_METHOD(TestGetRed)
		{
			Color c1(123, 111, 20);

			uint8_t expected = 123;
			uint8_t actual = c1.getRed();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetGreen)
		{
			Color c1(123, 111, 20);

			uint8_t expected = 111;
			uint8_t actual = c1.getGreen();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetBlue)
		{
			Color c1(123, 111, 20);

			uint8_t expected = 20;
			uint8_t actual = c1.getBlue();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetRGB)
		{
			Color c1(123, 111, 20);

			uint8_t* expected = new uint8_t[3]{ 123, 111, 20 };
			uint8_t* actual = c1.getRGB();

			for (auto i = 0; i < 3; ++i)
			{
				Assert::AreEqual(expected[i], actual[i], L"", LINE_INFO());
			}			
		}

		TEST_METHOD(TestToString)
		{
			Color c1(123, 111, 20);
			std::wstring expected = std::wstring(L"(123,111,20)");
			std::wstring actual = c1.toString();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestEq)
		{
			Color c1(123, 111, 20);
			Color c2(123, 111, 20);
			Color c3(10, 29, 73);

			bool expected = true;
			bool actual = c1 == c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = false;
			actual = c1 == c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestNEq)
		{
			Color c1(123, 111, 20);
			Color c2(123, 111, 20);
			Color c3(10, 29, 73);

			bool expected = false;
			bool actual = c1 != c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = true;
			actual = c1 != c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}