#pragma once

#include "API.h"

#include "Mastermind.h"
#include "IEvaluator.h"


namespace mastermind {
	class MASTERMINDCPPDLL_API ComputerEvaluator : public virtual IEvaluator, public Mastermind {
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