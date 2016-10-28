#include "stdafx.h"

#include "RequestedState.h"

namespace mastermind
{
	namespace shell
	{
		State::State() :
			state(GameState::HUMAN_GUESSER)
		{
		}

		State::State(GameState state) :
			state(state)
		{
		}

		void State::switchState()
		{
			switchState(state);
		}

		void State::switchState(const GameState& currentState)
		{
			switch (currentState)
			{
			case GameState::HUMAN_GUESSER:
				state = GameState::COMPUTER_GUESSER;
				break;
			case GameState::COMPUTER_GUESSER:
				state = GameState::HUMAN_GUESSER;
				break;
			default:
				throw std::logic_error("cannot happen.");
			}
		}

		State::GameState State::getCurrentState() const
		{
			return state;
		}


	}
}