#pragma once

#include "API.h"

namespace mastermind
{
	namespace shell
	{
		/**
		 * \brief Game state.
		 * Class holds the current game state and can be switched here.
		 */
		class MASTERMINDCPPDLL_API State
		{
		public:
			/**
			* \brief Available states for games.
			*/
			enum class GameState
			{
				/**
				* \brief Human guesser, computer evaluator.
				*/
				HUMAN_GUESSER,
				/**
				* \brief Computer guesser, human evaluator.
				*/
				COMPUTER_GUESSER
			};

		private:
			GameState state;

		public:
			/**
			 * \brief Create a new state. Initialised to HUMAN_GUESSER.
			 */
			State();
			/**
			 * \brief Create a new state.
			 * \param state the state to start.
			 */
			State(GameState state);
			/**
			* \brief Switch the state.
			*/
			void switchState();
			/**
			 * \brief Get current state.
			 * \return the current state
			 */
			GameState getCurrentState() const;

		protected:
			void switchState(const GameState& currentState);
		};
	}
}
