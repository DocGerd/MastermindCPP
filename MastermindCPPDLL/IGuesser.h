#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind {
	class IGuesser abstract {
	public:
		virtual ColorCode<> nextGuess() abstract;
		virtual void processEvaluation(BlackAndWhite &bw) abstract;
	};
}