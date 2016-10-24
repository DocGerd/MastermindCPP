#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Interface for a Guesser.
		 */
		class MASTERMINDCPPDLL_API IGuesser abstract
		{
		public:
			virtual ~IGuesser()
			{
			}

			/**
			 * \brief Get the next guess.
			 * \return The next guess of the player. <tt>null</tt> aborts the game.
			 */
			virtual ColorCode* nextGuess() abstract;

			/**
			 * \brief Process evaluation.
			 * This method processes the other player's feedback on
			 * the last guess provided by <tt>nextGuess</tt>.
			 * Must only be executed if <tt>nextGuess</tt> has been
			 * called before and has not returned <tt>null</tt>.
			 * 
			 * \param bw Evaluation of the last guess.
			 */
			virtual void processEvaluation(const BlackAndWhite& bw) abstract;
		};
	}
}
