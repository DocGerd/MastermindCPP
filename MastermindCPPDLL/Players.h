#pragma once

#include "API.h"
#include "IGuesser.h"
#include "IEvaluator.h"
#include "RequestedState.h"
#include "GameHistory.h"
#include "HumanGuesser.h"
#include "HumanEvaluator.h"
#include "ComputerGuesser.h"
#include "ComputerEvaluator.h"
#include "Utilities.h"

namespace mastermind {
	namespace shell {
		using namespace mastermind::logic;

		class MASTERMINDCPPDLL_API Players {
		private:
			IGuesser* const guesser;
			IEvaluator* const evaluator;

		public:
			Players(IGuesser *g, IEvaluator *e) :
				guesser(g), evaluator(e) { }

			IGuesser* getGuesser() {
				return this->guesser;
			}
			IEvaluator* getEvaluator() {
				return this->evaluator;
			}
		};

		/**
		* Get the player objects.
		* Just here are the objects created so the objects are created just
		* in time. (in case someone "switches" pretty often...)
		* @param state the requested state, must not be <tt>null</tt>
		* @param history the history which should be referenced in the Human*
		* objects
		* @return the players
		*/
		Players* getPlayers(RequestedState state, GameHistory *history) {
			IEvaluator *e = NULL;
			IGuesser *g = NULL;
			switch (state) {
			case HUMAN_GUESSER:
				g = new HumanGuesser(new ReadOnlyHistory(history));
				e = new ComputerEvaluator(utilities::Utilities::createRandomCode());
				break;
			case COMPUTER_GUESSER:
				g = new ComputerGuesser();
				e = new HumanEvaluator(new ReadOnlyHistory(history));
				break;
			default:
				throw std::logic_error("cannot happen");
			}
			return new Players(g, e);
		}
	}
}