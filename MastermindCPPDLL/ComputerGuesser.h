#pragma once

#include "API.h"
#include "IGuesser.h"
#include "Mastermind.h"

#include <list>

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief A computer guesser.
		 * Uses a heuristic to find a solution. All possibilities are calculated and after each evaluation
		 * impossible solutions will be removed.
		 */
		class MASTERMINDCPPDLL_API ComputerGuesser : public virtual IGuesser
		{
		private:
			/**
			 * \brief Base game.
			 */
			const Mastermind* game;
#pragma warning(disable: 4251)
			/**
			 * \brief List of possible codes available to guess.
			 */
			std::list<ColorCode*>* possibleCodes;
#pragma warning(default: 4251)
			/**
			 * \brief Amount of moves performed.
			 */
			std::size_t moveCount;
			/**
			 * \brief Flag indicating player has cheated.
			 */
			bool cheated;

		public:
			/**
			 * \brief Create a ComputerGuesser.
			 */
			ComputerGuesser(const Mastermind* game);
			/**
			 * \copydoc IGuesser::nextGuess()
			 */
			ColorCode* nextGuess() override;
			/**
			 * \copydoc IGuesser::processEvaluation()
			 */
			void processEvaluation(const BlackAndWhite& bw) override;
			/**
			 * \brief Check if cheating was detected.
			 * \return <tt>true</tt> if evaluator cheated
			 */
			bool cheatingDetected() const;

		private:
			/**
			 * \brief Create all possible ColorCodes.
			 */
			void createCodes();
		};
	}
}
