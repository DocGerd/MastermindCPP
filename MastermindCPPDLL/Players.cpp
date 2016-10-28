#include "stdafx.h"

#include "Players.h"

#include "HumanGuesser.h"
#include "HumanEvaluator.h"
#include "ComputerGuesser.h"
#include "ComputerEvaluator.h"
#include "Utilities.h"

namespace mastermind
{
	namespace shell
	{
		Players::Players(IGuesser* g, IEvaluator* e) :
			guesser(g), evaluator(e)
		{
		}

		IGuesser* Players::getGuesser() const
		{
			return this->guesser;
		}

		IEvaluator* Players::getEvaluator() const
		{
			return this->evaluator;
		}

		Players* Players::getPlayers(State state, GameHistory* history)
		{
			IEvaluator* e;
			IGuesser* g;
			Mastermind *game = new Mastermind();
			switch (state.getCurrentState())
			{
			case State::GameState::HUMAN_GUESSER:
				g = new HumanGuesser(game, new ReadOnlyHistory(history));
				e = new ComputerEvaluator(game, utilities::Utilities::createRandomCode(game->getSlotCount(), game->getColorCount()));
				break;
			case State::GameState::COMPUTER_GUESSER:
				g = new ComputerGuesser(game);
				e = new HumanEvaluator(game, new ReadOnlyHistory(history));
				break;
			default:
				throw std::logic_error("cannot happen");
			}
			return new Players(g, e);
		}
	}
}