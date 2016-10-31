#pragma once

#include "API.h"
#include "IEvaluator.h"
#include "Mastermind.h"
#include "ReadOnlyHistory.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief A human Evaluator for console.
		 */
		class MASTERMINDCPPDLL_API HumanEvaluator : public virtual IEvaluator, public Mastermind
		{
		private:
			/**
			* \brief Base game.
			*/
			const Mastermind* game;
			/**
			 * \brief History for the evaluator.
			 * Used for print.
			 */
			ReadOnlyHistory* const history;
#pragma warning(disable: 4251)
			/**
			 * \brief The help text for console output.
			 */
			const std::wstring HELP_TEXT;
#pragma warning(default: 4251)

		public:
			/**
			 * \brief Create a HumanEvaluator.
			 * \param game the main game
			 * \param h the history to read from
			 */
			HumanEvaluator(const Mastermind* game, ReadOnlyHistory* h);


			BlackAndWhite* evaluate(const ColorCode* cc) override;
			/**
			 * \copydoc mastermind::logic::IEvaluator::getSolution()
			 */
			ColorCode* getSolution() override;
		};
	}
}
