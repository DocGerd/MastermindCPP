#pragma once

#include "API.h"
#include "Mastermind.h"
#include "IEvaluator.h"
#include "IGuesser.h"
#include "GameHistory.h"

namespace mastermind {
	namespace logic {
		/*!
		* The Game.
		* Game logic is in here. No in and output. Works only with the interfaces of
		* <tt>Evaluator</tt> and <tt>Guesser</tt>.
		*/
		class MASTERMINDCPPDLL_API MainGame : public Mastermind {
		private:
			std::size_t moveCount;
			IEvaluator* const evaluator;
			IGuesser* const guesser;
			GameHistory* const history;

		public:
			/*!
			* Creates a MainGame object.
			* @param g the guesser, must not be <tt>null</tt>
			* @param e the evaluator, must not be <tt>null</tt>
			* @param h the history to write to, must not be <tt>null</tt>
			* Human* classes before
			*/
			MainGame(IGuesser *g, IEvaluator *e, GameHistory *h);
			/*!
			 * The game itself. Performs the next turn, i.e.one turn each of
			 * Guesser and Evaluator.
			 * @return <tt>true</tt> if game finished, i.e.won or cancel
			*/
			bool next();
		};
	}
}