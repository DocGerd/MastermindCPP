#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/BlackAndWhite.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind;


namespace UnitTest1
{
	TEST_CLASS(TestBlackAndWhite)
	{
	public:
		TEST_METHOD(TestGetBlack) {
			std::size_t black = 3;
			std::size_t white = 2;
			BlackAndWhite bnw(black, white);

			Assert::AreEqual(black, bnw.getBlack(), L"", LINE_INFO());
		}

		TEST_METHOD(TestGetWhite) {
			std::size_t black = 3;
			std::size_t white = 2;
			BlackAndWhite bnw(black, white);

			Assert::AreEqual(white, bnw.getWhite(), L"", LINE_INFO());
		}

		TEST_METHOD(TestEquals) {
			BlackAndWhite bnw1(3, 2);
			BlackAndWhite bnw2(3, 2);
			BlackAndWhite bnw3(2, 3);

			bool result = bnw1 == bnw2;
			Assert::IsTrue(result, L"", LINE_INFO());

			result = bnw1 == bnw3;
			Assert::IsFalse(result, L"", LINE_INFO());
		}

		TEST_METHOD(TestEqualsConst) {
			const BlackAndWhite &bnw1 = BlackAndWhite(3, 2);
			const BlackAndWhite &bnw2 = BlackAndWhite(3, 2);
			const BlackAndWhite &bnw3 = BlackAndWhite(2, 3);

			bool result = bnw1 == bnw2;
			Assert::IsTrue(result, L"", LINE_INFO());

			result = bnw1 == bnw3;
			Assert::IsFalse(result, L"", LINE_INFO());
		}

		TEST_METHOD(TestNotEquals) {
			BlackAndWhite bnw1(3, 2);
			BlackAndWhite bnw2(3, 2);
			BlackAndWhite bnw3(2, 3);

			bool result = bnw1 != bnw2;
			Assert::IsFalse(result, L"", LINE_INFO());

			result = bnw1 != bnw3;
			Assert::IsTrue(result, L"", LINE_INFO());
		}
	};
}