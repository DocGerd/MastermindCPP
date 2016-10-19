#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind {
	class IEvaluator abstract {
	public:
		 virtual BlackAndWhite evaluate(const ColorCode<> &cc) abstract;
		 virtual ColorCode<>* getSolution() abstract;
	};
}