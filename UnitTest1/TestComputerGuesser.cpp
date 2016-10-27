#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/ComputerGuesser.h"
#include "../MastermindCPPDLL/ColorCode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString<ColorCode>(const ColorCode& q)
			{
				return q.toString();
			}
		}
	}
}

namespace UnitTest1
{
	TEST_CLASS(TestComputerGuesser)
	{
	public:
		TEST_METHOD(TestRunCheat)
		{
			// first guess should be 0 0 0 0
			ComputerGuesser cg;
			ColorCode* guess = cg.nextGuess();
			ColorCode* expected = new ColorCode(std::array<color_t, 4>{0, 0, 0, 0});
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			// evaluation 0 1
			cg.processEvaluation(BlackAndWhite(0, 1));
			bool actual = cg.cheatingDetected();
			Assert::IsTrue(actual, L"", LINE_INFO());
		}

		TEST_METHOD(TestRunNormal)
		{
			// solution is 4 3 1 3
			// first guess should be 0 0 0 0
			ComputerGuesser cg;
			ColorCode* guess = cg.nextGuess();
			ColorCode* expected = new ColorCode(std::array<color_t, 4>{0, 0, 0, 0});
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(0, 0));
			delete expected;
			delete guess;
			// solution is 4 3 1 3
			expected = new ColorCode(std::array<color_t, 4>{1, 1, 1, 1});
			guess = cg.nextGuess();
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(1, 0));
			delete expected;
			delete guess;
			// solution is 4 3 1 3
			expected = new ColorCode(std::array<color_t, 4>{1, 2, 2, 2});
			guess = cg.nextGuess();
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(0, 1));
			delete expected;
			delete guess;
			// solution is 4 3 1 3
			expected = new ColorCode(std::array<color_t, 4>{3, 1, 3, 3});
			guess = cg.nextGuess();
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(1, 2));
			delete expected;
			delete guess;
			// solution is 4 3 1 3
			expected = new ColorCode(std::array<color_t, 4>{3, 3, 1, 4});
			guess = cg.nextGuess();
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(2, 2));
			delete expected;
			delete guess;
			// solution is 4 3 1 3
			expected = new ColorCode(std::array<color_t, 4>{3, 3, 4, 1});
			guess = cg.nextGuess();
			Assert::IsNotNull(guess, L"", LINE_INFO());
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(3, 0));
			delete expected;
			delete guess;
			guess = cg.nextGuess();
			Assert::IsNull(guess, L"", LINE_INFO());
			// no more moves...
		}
	};
}
