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
			ColorHSI c1(251.1f, 0.756f, 0.426f);

			float expected = 251.1f;
			float actual = c1.getHue();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetSaturation)
		{
			ColorHSI c1(251.1f, 0.756f, 0.426f);

			float expected = 0.756f;
			float actual = c1.getSaturation();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetIntensity)
		{
			ColorHSI c1(251.1f, 0.756f, 0.426f);

			float expected = 0.426f;
			float actual = c1.getIntensity();

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetHSI)
		{
			ColorHSI c1(251.1f, 0.756f, 0.426f);

			float* expected = new float[3]{ 251.1f, 0.756f, 0.426f };
			float* actual = c1.getHSI();

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
			ColorHSI c1(251.1f, 0.756f, 0.426f);
			ColorHSI c2(251.1f, 0.756f, 0.426f);
			ColorHSI c3(283.7f, 0.686f, 0.596f);

			bool expected = true;
			bool actual = c1 == c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = false;
			actual = c1 == c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestNEq)
		{
			ColorHSI c1(251.1f, 0.756f, 0.426f);
			ColorHSI c2(251.1f, 0.756f, 0.426f);
			ColorHSI c3(283.7f, 0.686f, 0.596f);

			bool expected = false;
			bool actual = c1 != c2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());

			expected = true;
			actual = c1 != c3;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}