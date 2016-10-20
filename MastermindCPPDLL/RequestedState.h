#pragma once

#include "API.h"

#include <stdexcept>

namespace mastermind {
	namespace shell {
		static enum RequestedState {
			HUMAN_GUESSER,
			COMPUTER_GUESSER
		};

		static RequestedState switchState(const RequestedState &state) {
			RequestedState result;
			switch (state) {
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