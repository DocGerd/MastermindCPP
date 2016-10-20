#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind {
	/// Interface for a Guesser.
	class IGuesser abstract {
	public:
		/// Get the next guess.
		/*!
		 * @return ColorCode of the guess.
		*/
		virtual ColorCode nextGuess() abstract;
		virtual void processEvaluation(BlackAndWhite &bw) abstract;
	};
}