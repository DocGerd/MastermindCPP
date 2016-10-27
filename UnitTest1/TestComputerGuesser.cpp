#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Mastermind.h"
#include "../MastermindCPPDLL/ColorCode.h"
#include "../MastermindCPPDLL/ComputerGuesser.h"

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
			// first guess should be 0 0 0 0
			ComputerGuesser cg;
			ColorCode* guess = cg.nextGuess();
			ColorCode* expected = new ColorCode(std::array<color_t, 4>{0, 0, 0, 0});
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(0, 0));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{1, 1, 1, 1});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(1, 0));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{1, 2, 3, 4});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(0, 3));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{2, 1, 3, 5});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(0, 2));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{4, 3, 1, 2});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(3, 0));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{4, 3, 1, 4});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			cg.processEvaluation(BlackAndWhite(3, 0));
			delete expected;
			delete guess;
			expected = new ColorCode(std::array<color_t, 4>{4, 3, 1, 0});
			guess = cg.nextGuess();
			Assert::AreEqual(*expected, *guess, L"", LINE_INFO());

			// no more moves...
		}
	};
}
