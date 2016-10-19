#pragma once
#ifdef MASTERMINDCPPDLL_EXPORTS
#define MASTERMINDCPPDLL_API __declspec(dllexport)
#else
#define MASTERMINDCPPDLL_API __declspec(dllimport)
#endif
#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind {
	class IGuesser abstract {
	public:
		virtual ColorCode<> nextGuess() abstract;
		virtual void processEvaluation(BlackAndWhite &bw) abstract;
	};
}