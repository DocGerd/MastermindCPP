#pragma once

#include "API.h"
#include "Mastermind.h"
#include "IEvaluator.h"
#include "IGuesser.h"
#include "GameHistory.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief The Game.
		 * Game logic is in here. No in and output. Works only with the interfaces of
		 * IEvaluator and IGuesser.
		 */
		class MASTERMINDCPPDLL_API MainGame : public Mastermind
		{
		private:
			/**
			 * \brief Amount of already performed moves.
			 */
			std::size_t moveCount;
			/**
			 * \brief The evaluator of the game.
			 */
			IEvaluator* const evaluator;
			/**
			 * \brief The Guesser of the game.
			 */
			IGuesser* const guesser;
			/**
			 * \brief History for the game.
			 */
			GameHistory* const history;

		public:
			/**
			* Creates a MainGame object.
			* \param g the guesser, must not be <tt>null</tt>
			* \param e the evaluator, must not be <tt>null</tt>
			* \param h the history to write to, must not be <tt>null</tt>
			*/
			MainGame(IGuesser* g, IEvaluator* e, GameHistory* h);
			/**
			* \brief The game itself. Performs the next turn, i.e.one turn each of
			* Guesser and Evaluator.
			* \return <tt>true</tt> if game finished, i.e.won or cancel
			*/
			bool next();
		};
	}
}
