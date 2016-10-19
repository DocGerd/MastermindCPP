#pragma once
#ifdef MASTERMINDCPPDLL_EXPORTS
#define MASTERMINDCPPDLL_API __declspec(dllexport)
#else
#define MASTERMINDCPPDLL_API __declspec(dllimport)
#endif
#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind {
	class IEvaluator abstract {
	public:
		 virtual BlackAndWhite evaluate(const ColorCode<> &cc) abstract;
		 virtual ColorCode<>* getSolution() abstract;


	};
}