#include "stdafx.h"
#include "MainGame.h"

namespace mastermind
{
	namespace logic
	{
		MainGame::MainGame(const Mastermind* game, IGuesser* g, IEvaluator* e, GameHistory* h) :
			game(game),
			moveCount(0),
			evaluator(e),
			guesser(g),
			history(h)
		{
			if (game == nullptr)
			{
				throw std::invalid_argument("game must not be nullptr!");
			}
			if (e == nullptr)
			{
				throw std::invalid_argument("e must not be nullptr!");
			}
			if (g == nullptr)
			{
				throw std::invalid_argument("g must not be nullptr!");
			}
			if (h == nullptr)
			{
				throw std::invalid_argument("h must not be nullptr!");
			}
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
					if (game->isWinStick(*bw))
					{
						finished = true;
					}
				}
			}
			++moveCount;
			if (moveCount == game->getMaxMoves())
			{
				finished = true;
			}
			return finished;
		}
	}
}
