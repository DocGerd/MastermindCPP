#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Mastermind.h"
#include "../MastermindCPPDLL/ColorCode.h"
#include "../MastermindCPPDLL/ComputerEvaluator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind;

namespace UnitTest1
{
	TEST_CLASS(TestComputerEvaluator)
	{
	public:

		TEST_METHOD(TestCstr)
		{
			std::array<int, 4> sol = {1,2,3,4};
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);
		}

		TEST_METHOD(TestEvaluate)
		{
			// 1 == green
			// 2 == red
			// 3 == blue
			// 4 == green
			// 5 == yellow
			// 6 == orange
			std::array<int, 4> sol = { 1,2,3,4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			ColorCode first(std::array<int, 4>{ 2, 5, 2, 1 });
			BlackAndWhite expected(1, 1);
			BlackAndWhite actual = ce.evaluate(first);
			bool result = expected == actual;
			wchar_t message[200];
			_swprintf(message, L"expected: %s, actual: %s", expected.toString(), actual.toString());
			Assert::IsTrue(result, message, LINE_INFO());

			//ColorCode second(std::array<int, 4>{1, 1, 6, 2});
			//BlackAndWhite expected2(1, 2);
			//BlackAndWhite actual2 = ce.evaluate(second);
			//Assert::AreEqual(expected2, actual2, L"", LINE_INFO());

		}

		TEST_METHOD(TestGetSolution)
		{
			std::array<int, 4> sol = { 1,2,3,4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			Assert::IsNull(ce.getSolution(), L"", LINE_INFO());

			// TODO
		}
	};
}