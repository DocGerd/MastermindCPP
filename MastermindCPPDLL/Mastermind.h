#pragma once

#include "API.h"

#include <string>

namespace mastermind {
	/// Class for important global game values.
	class MASTERMINDCPPDLL_API Mastermind {
	public:
		/// Maximum moves allowed until game finished.
		static constexpr std::size_t MAX_MOVES = 7;
		/// Amount of slots for colors.
		static constexpr std::size_t SLOT_COUNT = 4;
		/// Amount of available colors.
		static constexpr std::size_t COLOR_COUNT = 6;

		//! Amount of possible solutions.
		/*!
		 * @return number of possible solutions
		*/
		static inline unsigned long CODE_COUNT() {
			unsigned long result = COLOR_COUNT;
			for (auto i = 1; i < SLOT_COUNT; ++i) {
				result *= COLOR_COUNT;
			}
			return result;
		}
	};
}
