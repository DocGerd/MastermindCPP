#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Mastermind.h"
#include "../MastermindCPPDLL/ColorCode.h"
#include "../MastermindCPPDLL/ComputerEvaluator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString<BlackAndWhite>(const BlackAndWhite& q)
			{
				return q.toString();
			}
		}
	}
}

namespace UnitTest1
{
	TEST_CLASS(TestComputerEvaluator)
	{
	public:

		TEST_METHOD(TestCstr)
		{
			std::array<color_t, 4> sol = { 1,2,3,4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);
		}

		TEST_METHOD(TestEvaluate)
		{
			std::array<color_t, 4> sol = { 1, 2, 3, 4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			ColorCode first(std::array<color_t, 4>{2, 5, 2, 1});
			BlackAndWhite expected(0, 2);
			BlackAndWhite actual = *ce.evaluate(&first);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestEvaluate2)
		{
			std::array<color_t, 4> sol = { 1, 2, 3, 4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			ColorCode second(std::array<color_t, 4>{1, 1, 6, 2});
			BlackAndWhite expected2(1, 1);
			BlackAndWhite actual2 = *ce.evaluate(&second);
			Assert::AreEqual(expected2, actual2, L"", LINE_INFO());
		}

		TEST_METHOD(TestGetSolution)
		{
			std::array<color_t, 4> sol = { 1, 2, 3, 4 };
			ColorCode solution(sol);
			ComputerEvaluator ce(solution);

			Assert::IsNull(ce.getSolution(), L"", LINE_INFO());

			ColorCode cc(std::array<color_t, 4>{2, 5, 2, 1});
			for (auto i = 0; i < mastermind::Mastermind::MAX_MOVES; ++i)
			{
				ce.evaluate(&cc);
			}
			Assert::IsNotNull(ce.getSolution(), L"", LINE_INFO());
			bool result = solution == *ce.getSolution();
			Assert::IsTrue(result, L"", LINE_INFO());
		}
	};
}
