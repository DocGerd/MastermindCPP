#pragma once
#include "API.h"
#include "Mastermind.h"
#include "ColorCode.h"
#include "BlackAndWhite.h"

#include <list>

namespace mastermind {
	namespace logic {
		class MASTERMINDCPPDLL_API GameHistory : public Mastermind {
		private:
			/// History of the ColorCodes.
			std::list<ColorCode>* const colorCodes;
			/// History of the BlackAndWhites.
			std::list<BlackAndWhite>* const blackAndWhites;

		public:
			/// Create a GameHistory.
			GameHistory();
			/// Destruct a GameHistory.
			~GameHistory();

			/*!
			 * Add a ColorCode to the history.
			 * @param cc the ColorCode.
			*/
			void add(const ColorCode &cc) const;

			/*!
			 * Add a BlackAndWhite to the history.
			 * @param bw the BlackAndWhite
			*/
			void add(const BlackAndWhite &bw) const;

			/*!
			 * Get the string representation of the game history.
			 * @return the string
			*/
			std::wstring toString() const;
		};
	}
}