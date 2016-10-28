#pragma once

#include "API.h"
#include "IGuesser.h"
#include "IEvaluator.h"
#include "RequestedState.h"
#include "GameHistory.h"

namespace mastermind
{
	namespace shell
	{
		using namespace mastermind::logic;

		/**
		 * \brief Players of the game.
		 */
		class MASTERMINDCPPDLL_API Players
		{
		private:
			/**
			 * \brief Player who is guessing.
			 */
			IGuesser* const guesser;
			/**
			 * \brief Player who is evaluating.
			 */
			IEvaluator* const evaluator;

		public:
			/**
			 * \brief Create Players.
			 * \param g the guesser
			 * \param e the evaluator
			 */
			Players(IGuesser* g, IEvaluator* e);

			/**
			 * \brief Get the guesser.
			 * \return the guesser
			 */
			IGuesser* getGuesser() const;

			/**
			 * \brief Get the evaluator.
			 * \return the evaluator
			 */
			IEvaluator* getEvaluator() const;

			/**
			* \brief Get the player objects.
			* Just here are the objects created so the objects are created just
			* in time. (in case someone "switches" pretty often...)
			* \param state the requested state
			* \param history the history which should be referenced in the Human* objects
			* \return the players
			*/
			static Players* getPlayers(State state, GameHistory* history);
		};
	}
}
