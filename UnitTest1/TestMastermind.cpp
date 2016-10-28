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
			mastermind::logic::Mastermind *game = new mastermind::logic::Mastermind();
			const uint32_t cc = game->getColorCount();
			const uint32_t sc = game->getSlotCount();
			const uint64_t expected = static_cast<uint64_t>(pow(cc, sc));

			Assert::AreEqual(expected, mastermind::logic::Mastermind::Mastermind().getCodeCount(), L"", LINE_INFO());
			delete game;
		}
	};
}
