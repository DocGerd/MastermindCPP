#pragma once

#include "API.h"
#include "IEvaluator.h"
#include "Mastermind.h"
#include "ReadOnlyHistory.h"

namespace mastermind {
	namespace logic {
		class MASTERMINDCPPDLL_API HumanEvaluator : public virtual IEvaluator, public Mastermind {
		private:
			ReadOnlyHistory* const history;

		public:
			HumanEvaluator(ReadOnlyHistory* h);

			BlackAndWhite* evaluate(const ColorCode& cc) override;
			ColorCode* getSolution() override;
		};
	}
}