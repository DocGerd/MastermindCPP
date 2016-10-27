#include "stdafx.h"
#include "MainGame.h"

namespace mastermind
{
	namespace logic
	{
		MainGame::MainGame(IGuesser* g, IEvaluator* e, GameHistory* h) :
			moveCount(0), evaluator(e), guesser(g), history(h)
		{
		}

		bool MainGame::next()
		{
			bool finished = false;
			ColorCode* cc;
			BlackAndWhite* bw;

			cc = guesser->nextGuess();
			if (cc == nullptr)
			{
				finished = true;
			}
			else
			{
				history->add(*cc);
				bw = evaluator->evaluate(cc);
				if (bw == nullptr)
				{
					finished = true;
				}
				else
				{
					history->add(*bw);
					guesser->processEvaluation(*bw);
					if (*bw == BlackAndWhite::WIN_STICKS)
					{
						finished = true;
					}
				}
			}
			++moveCount;
			if (moveCount == MAX_MOVES)
			{
				finished = true;
			}
			return finished;
		}
	}
}
