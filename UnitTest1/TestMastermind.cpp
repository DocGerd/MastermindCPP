#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Mastermind.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestMastermind)
	{
	public:

		TEST_METHOD(TestMaxMoves)
		{
			const std::size_t cc = mastermind::Mastermind::COLOR_COUNT;
			const std::size_t sc = mastermind::Mastermind::SLOT_COUNT;
			const unsigned long expected = (unsigned long)pow(cc, sc);

			Assert::AreEqual(expected, mastermind::Mastermind::CODE_COUNT(), L"", LINE_INFO());
		}
	};
}