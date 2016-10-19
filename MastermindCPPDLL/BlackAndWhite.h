#pragma once

#include "API.h"

#include <string>

namespace mastermind {

	// BlackAndWhite. Representation for evaluation sticks.
	// Black sticks show color and position right.
	// White sticks show color right but wrong position.
	class MASTERMINDCPPDLL_API BlackAndWhite {
	private:
		// amount white sticks.
		const std::size_t white;
		// amount black sticks.
		const std::size_t black;

	public:
		BlackAndWhite(std::size_t blacks, std::size_t whites);

		// Get string representation. In format "black: %i white: %i".
		virtual std::wstring toString();

		// Get string representation. In format "black: %i white: %i".
		virtual std::wstring toString() const;

		// Get string representation. In format "%i %i".
		std::wstring toStringWithoutDescription();

		// Test equality. true if amount of white and amount of black is equal.
		bool operator==(const BlackAndWhite& rhs);

		// Test equality. true if amount of white and amount of black is equal.
		const bool operator==(const BlackAndWhite& rhs) const;

		// Test inequality. true if !(a == b)
		bool operator!=(const BlackAndWhite& rhs);

		// Get amount of white sticks.
		std::size_t getWhite();

		// Get amount of black sticks.
		std::size_t getBlack();
	};
}