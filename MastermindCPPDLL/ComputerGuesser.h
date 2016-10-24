#pragma once

#include "API.h"
#include "IGuesser.h"
#include "Mastermind.h"

#include <list>

namespace mastermind {
	namespace logic {
		/**
		 * \brief A computer guesser.
		 */
		class MASTERMINDCPPDLL_API ComputerGuesser : public virtual IGuesser, public Mastermind {
		private:
#pragma warning(disable: 4251)
			/// List of possible codes available to guess.
			std::list<ColorCode> possibleCodes;
#pragma warning(default: 4251)
			/// Amount of moves performed.
			std::size_t moveCount;
			/// Flag indicating player has cheated.
			bool cheated;

		public:
			ComputerGuesser();
			/// \copydoc IGuesser::nextGuess()
			ColorCode* nextGuess() override;
			/// \copydoc IGuesser::processEvaluation()
			void processEvaluation(const BlackAndWhite &bw) override;

		private:
			void createCodes();
		};
	}
}