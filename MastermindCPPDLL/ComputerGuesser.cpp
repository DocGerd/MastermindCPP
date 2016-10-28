#include "stdafx.h"

#include "ComputerGuesser.h"
#include "ComputerEvaluator.h"
#include "Utilities.h"

namespace mastermind
{
	namespace logic
	{
		ComputerGuesser::ComputerGuesser(const Mastermind* game) :
			game(game), moveCount(0), cheated(false)
		{
			createCodes();
		}

		ColorCode* ComputerGuesser::nextGuess()
		{
			ColorCode* result = nullptr;
			if (!cheated)
			{
				result = possibleCodes->front();
				++moveCount;
			}
			return result;
		}

		void ComputerGuesser::processEvaluation(const BlackAndWhite& bw)
		{
			// win situation
			if (game->isWinStick(bw))
			{
				std::cout << L"Wow! I did it!" << std::endl;
			}
			else
			{
				// remove ColorCodes which cannot be possible anymore.
				ComputerEvaluator evaluator(game, possibleCodes->front());
				std::list<ColorCode*>* possibleCodesNew = new std::list<ColorCode*>();
				for (std::list<ColorCode*>::iterator iter = possibleCodes->begin(); iter != possibleCodes->end(); ++iter)
				{
					ColorCode* cc = *iter;
					BlackAndWhite* curr = evaluator.evaluate(cc);
					if (*curr == bw)
					{
						possibleCodesNew->push_back(cc);
					}
					delete curr;
				}
				delete possibleCodes;
				possibleCodes = possibleCodesNew;

				// lost situation
				if (moveCount == game->getMaxMoves())
				{
					std::cout << L"no more moves - I couldn't find a solution" << std::endl;
				}
				// cheating situation
				else if (possibleCodes->empty())
				{
					std::cout << L"no possibilities left - you have been cheating!" << std::endl;
					cheated = true;
				}
			}
		}

		bool ComputerGuesser::cheatingDetected() const
		{
			return this->cheated;
		}


		void ComputerGuesser::createCodes()
		{
			possibleCodes = new std::list<ColorCode*>();
			color_t* colors = new color_t[game->getSlotCount()];
			for (size_t i = 0; i < game->getSlotCount(); ++i)
			{
				colors[i] = 0;
			}
			possibleCodes->push_back(new ColorCode(game->getSlotCount(), colors));
			const std::size_t code_count = game->getCodeCount();
			for (int i = 1; i < code_count; ++i)
			{
				colors[game->getSlotCount() - 1] = i % game->getColorCount();
				for (int j = 1; j < game->getSlotCount(); ++j)
				{
					colors[game->getSlotCount() - 1 - j] =
						(i / shell::utilities::Utilities::POWER(game->getColorCount(), j)) % game->getColorCount();
				}
				possibleCodes->push_back(new ColorCode(game->getSlotCount(), colors));
			}
		}
	}
}
