#pragma once
#include "API.h"
#include "Mastermind.h"
#include "ColorCode.h"
#include "BlackAndWhite.h"

#include <list>

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Game History.
		 * Saves performed moves, i.e. ColorCodes and BlackAndWhites, so the board can be printed.
		 */
		class MASTERMINDCPPDLL_API GameHistory : public Mastermind
		{
		private:
			/**
			 * \brief History of ColorCodes.
			 */
			std::list<ColorCode>* const colorCodes;
			/**
			 * \brief History of BlackAndWhites.
			 */
			std::list<BlackAndWhite>* const blackAndWhites;

		public:
			/**
			 * \brief Create empty history.
			 */
			GameHistory();
			/**
			 * \brief Destruct this.
			 */
			~GameHistory();

			/**
			 * \brief Add a ColorCode to the history.
			 * \param cc the ColorCode
			 */
			void add(const ColorCode& cc) const;

			/**
			 * \brief Add a BlackAndWhite to the history.
			 * \param bw the BlackAndWhite
			 */
			void add(const BlackAndWhite& bw) const;

			/**
			 * \brief Get the string representation of the game history.
			 * \return the string
			 */
			std::wstring toString() const;
		};
	}
}
