#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

#pragma once

#include "API.h"


namespace mastermind {
	class MASTERMINDCPPDLL_API IEvaluator abstract {
	public:
		// Evaluate the given ColorCode to the respective BlackAndWhite.
		virtual BlackAndWhite evaluate(const ColorCode &cc) abstract;
		// Get the solution.
		virtual ColorCode* getSolution() abstract;
	};
}