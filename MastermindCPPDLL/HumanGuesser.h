#pragma once

#include "API.h"
#include "IGuesser.h"
#include "Mastermind.h"
#include "ReadOnlyHistory.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief A human guesser for console.
		 */
		class MASTERMINDCPPDLL_API HumanGuesser : public virtual IGuesser, public Mastermind
		{
		private:
			/**
			 * \brief History for the evaluator.
			 * Used for print.
			 */
			ReadOnlyHistory* const history;
#pragma warning(disable: 4251)
			/**
			 * \brief The help text for console output.
			 */
			static const std::wstring HELP_TEXT;
#pragma warning(default: 4251)

		public:
			/**
			* \brief Create a HumanGuesser.
			* \param h the history to read from
			*/
			HumanGuesser(ReadOnlyHistory* h);

			ColorCode* nextGuess() override;
			void processEvaluation(const BlackAndWhite& bw) override;
		};
	}
}
