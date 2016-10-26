#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MastermindCPPDLL/ColorHSI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace UnitTest1
{
	TEST_CLASS(TestColorHSI)
	{
	public:
		TEST_METHOD(TestGetHue)
		{
			ColorHSI c1(251.1, 0.756, 0.426);

			double expected = 251.1;
			double actual = c1.getHue();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetSaturation)
		{
			ColorHSI c1(251.1, 0.756, 0.426);

			double expected = 0.756;
			double actual = c1.getSaturation();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetIntensity)
		{
			ColorHSI c1(251.1, 0.756, 0.426);

			double expected = 0.426;
			double actual = c1.getIntensity();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetHSI)
		{
			ColorHSI c1(251.1, 0.756, 0.426);

			double* expected = new double[3]{251.1, 0.756, 0.426};
			double* actual = c1.getHSI();

			for (auto i = 0; i < 3; ++i)
			{
				Assert::AreEqual(expected[i], actual[i], L"", LINE_INFO());
			}
		}

		TEST_METHOD(TestToString)
		{
			ColorHSI c1(251.1f, 0.756f, 0.426f);
			std::wstring expected = std::wstring(L"(251.100006,0.756000,0.426000)");
			std::wstring actual = c1.toString();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestEq)
		{
			ColorHSI c1(251.1, 0.756, 0.426);
			ColorHSI c2(251.1, 0.756, 0.426);
			ColorHSI c3(283.7, 0.686, 0.596);

			bool expected = true;
			bool actual = c1 == c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = false;
			actual = c1 == c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestNEq)
		{
			ColorHSI c1(251.1, 0.756, 0.426);
			ColorHSI c2(251.1, 0.756, 0.426);
			ColorHSI c3(283.7, 0.686, 0.596);

			bool expected = false;
			bool actual = c1 != c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = true;
			actual = c1 != c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}
