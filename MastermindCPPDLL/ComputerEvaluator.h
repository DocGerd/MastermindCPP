#pragma once

#ifdef MASTERMINDCPPDLL_EXPORTS
#define MASTERMINDCPPDLL_API __declspec(dllexport)
#else
#define MASTERMINDCPPDLL_API __declspec(dllimport)
#endif

#include "IEvaluator.h"

namespace mastermind {
	class MASTERMINDCPPDLL_API ComputerEvaluator : public virtual IEvaluator {
	private:
		unsigned int moveCount;
		const ColorCode<> solution;

	public:
		ComputerEvaluator(ColorCode<> soutionCode);
		~ComputerEvaluator();

		virtual BlackAndWhite evaluate(const ColorCode<> &cc) override;
		virtual ColorCode<>* getSolution() override;
	};
}