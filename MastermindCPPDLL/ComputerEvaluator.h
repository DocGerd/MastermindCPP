#pragma once

#include "API.h"

#include "Mastermind.h"
#include "IEvaluator.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Evaluator which automatically evaluates the ColorCode given to a solution.
		 */
		class MASTERMINDCPPDLL_API ComputerEvaluator : public virtual IEvaluator
		{
		private:
			/**
			 * \brief Amount of already performed moves.
			 */
			unsigned int moveCount;
			/**
			* \brief Base game.
			*/
			const Mastermind* game;
			/**
			 * \brief The solution.
			 */
			const ColorCode* solution;

		public:
			/**
			 * \brief Create a ComputerEvaluator.
			 * \param solutionCode the solution
			 */
			ComputerEvaluator(const Mastermind* game, const ColorCode* solutionCode);
			/**
			 * \brief Destruct this.
			 */
			~ComputerEvaluator();

			/**
			 * \copydoc IEvaluator::evaluate()
			 */
			BlackAndWhite* evaluate(const ColorCode* cc) override;
			/**
			 * \copydoc IEvaluator::getSolution()
			 */
			ColorCode* getSolution() override;
		};
	}
}
