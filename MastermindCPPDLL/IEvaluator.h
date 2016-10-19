#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

#pragma once

#include "API.h"


namespace mastermind {
	class MASTERMINDCPPDLL_API IEvaluator abstract {
	public:
		 virtual BlackAndWhite evaluate(const ColorCode<> &cc) abstract;
		 virtual ColorCode<>* getSolution() abstract;
	};
}