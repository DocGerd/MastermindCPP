#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MastermindCPPDLL/Mastermind.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	using namespace mastermind::logic;

	TEST_CLASS(TestMastermind)
	{
	public:

		TEST_METHOD(TestMaxMoves)
		{
			Mastermind *game = new Mastermind();
			const uint32_t cc = game->getColorCount();
			const uint32_t sc = game->getSlotCount();
			const uint64_t expected = static_cast<uint64_t>(pow(cc, sc));

			Assert::AreEqual(expected, Mastermind().getCodeCount(), L"", LINE_INFO());
			delete game;
		}

		TEST_METHOD(TestIsWinStick)
		{
			Mastermind m;

			BlackAndWhite bw(Mastermind::DEFAULT_SLOT_COUNT, 0);
			Assert::IsTrue(m.isWinStick(bw), L"", LINE_INFO());

			BlackAndWhite bw2(1, 2);
			Assert::IsFalse(m.isWinStick(bw2), L"", LINE_INFO());
		}
	};
}
