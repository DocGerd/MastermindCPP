#pragma once

#include <stdexcept>

namespace mastermind
{
	namespace shell
	{
		/**
		 * \brief Available states for games.
		 */
		enum RequestedState
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

		/**
		 * \brief Switch the state.
		 * \param state current state
		 * \return the other state
		 */
		static RequestedState switchState(const RequestedState& state)
		{
			RequestedState result;
			switch (state)
			{
			case HUMAN_GUESSER:
				result = RequestedState::COMPUTER_GUESSER;
				break;
			case COMPUTER_GUESSER:
				result = RequestedState::HUMAN_GUESSER;
				break;
			default:
				throw std::logic_error("cannot happen.");
			}
			return result;
		}
	}
}
