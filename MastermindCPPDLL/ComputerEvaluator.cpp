#include "stdafx.h"
#include "ComputerEvaluator.h"

namespace mastermind
{
	namespace logic
	{
		ComputerEvaluator::ComputerEvaluator(const Mastermind* game, const ColorCode* solutionCode) :
			game(game), moveCount(0), solution(solutionCode)
		{
		}

		ComputerEvaluator::~ComputerEvaluator()
		{
		}

		BlackAndWhite* ComputerEvaluator::evaluate(const ColorCode* cc)
		{
			std::size_t black = 0;
			std::size_t white = 0;

			bool* checkedSol = new bool[game->getSlotCount()];
			bool* checkedCc = new bool[game->getSlotCount()];
			for (std::size_t i = 0; i < game->getSlotCount(); ++i)
			{
				checkedSol[i] = false;
				checkedCc[i] = false;
			}

			// check blacks
			for (std::size_t i = 0; i < game->getSlotCount(); ++i)
			{
				if ((*cc)[i] == (*solution)[i])
				{
					checkedSol[i] = true;
					checkedCc[i] = true;
					++black;
				}
			}

			// check whites
			for (std::size_t i = 0; i < game->getSlotCount(); ++i)
			{
				for (std::size_t j = 0; j < game->getSlotCount() && !checkedSol[i]; ++j)
				{
					if (!checkedCc[j])
					{
						if ((*cc)[j] == (*solution)[i])
						{
							checkedCc[j] = true;
							checkedSol[i] = true;
							++white;
						}
					}
				}
			}

			++moveCount;

			return new BlackAndWhite(black, white);
		}

		ColorCode* ComputerEvaluator::getSolution()
		{
			ColorCode* result = nullptr;
			if (moveCount >= game->getMaxMoves())
			{
				result = new ColorCode(*solution);
			}
			return result;
		}
	}
}
