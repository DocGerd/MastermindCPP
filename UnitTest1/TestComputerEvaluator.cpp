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
			std::array<int, 4> sol = { 1,2,3,4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			ColorCode first(std::array<int, 4>{ 2, 5, 2, 1 });
			BlackAndWhite* expected = new BlackAndWhite(1, 1);
			BlackAndWhite* actual = ce.evaluate(first);
			wchar_t message[200];
			_swprintf(message, L"expected: %s, actual: %s", expected->toString(), actual->toString());
			Assert::IsTrue(*expected == *actual, message, LINE_INFO());

			ColorCode second(std::array<int, 4>{1, 1, 6, 2});
			delete expected;
			expected = new BlackAndWhite(1, 2);
			delete actual;
			actual = ce.evaluate(second);			
			_swprintf(message, L"expected: %s, actual: %s", expected->toString(), actual->toString());
			Assert::IsTrue(*expected == *actual, message, LINE_INFO());
		}

		TEST_METHOD(TestGetSolution)
		{
			std::array<int, 4> sol = { 1,2,3,4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			Assert::IsNull(ce.getSolution(), L"", LINE_INFO());

			// TODO
			Assert::Fail(L"Missing test!");
		}
	};
}