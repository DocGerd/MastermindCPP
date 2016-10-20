#pragma once

#include "API.h"

#include "Mastermind.h"
#include "IEvaluator.h"

namespace mastermind {
	namespace logic {
		/// Elevator which automatically evaluates the ColorCode given to a solution.
		class MASTERMINDCPPDLL_API ComputerEvaluator : public virtual IEvaluator, public Mastermind {
		private:
			/// Amount of already performed moves.
			unsigned int moveCount;
			/// The solution.
			const ColorCode solution;

		public:
			/// Create a ComputerEvaluator.
			/*!
			 * @param solutionCode the solution
			*/
			ComputerEvaluator(ColorCode soutionCode);
			/// Destruct this.
			~ComputerEvaluator();

			//! @copydoc IEvaluator::evaluate()
			BlackAndWhite* evaluate(const ColorCode &cc) override;
			//! @copydoc IEvaluator::getSolution()
			ColorCode* getSolution() override;
		};
	}
}