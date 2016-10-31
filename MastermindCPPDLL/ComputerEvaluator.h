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
			* \brief Base game.
			*/
			const Mastermind* game;
			/**
			 * \brief Amount of already performed moves.
			 */
			unsigned int moveCount;
			/**
			 * \brief The solution.
			 */
			const ColorCode* solution;

		public:
			/**
			 * \brief Create a ComputerEvaluator.
			 * \param game the main game
			 * \param solutionCode the solution
			 */
			ComputerEvaluator(const Mastermind* game, const ColorCode* solutionCode);
			/**
			 * \brief Destruct this.
			 */
			~ComputerEvaluator();

			/**
			 * \copydoc mastermind::logic::IEvaluator::evaluate()
			 */
			BlackAndWhite* evaluate(const ColorCode* cc) override;
			/**
			 * \copydoc mastermind::logic::IEvaluator::getSolution()
			 */
			ColorCode* getSolution() override;
		};
	}
}
