#pragma once

#include "API.h"

#include "Mastermind.h"

#include <string>
#include <array>

namespace mastermind {
	namespace logic {
		/// Represents one line of the game board.
		class MASTERMINDCPPDLL_API ColorCode : public Mastermind {
		private:
#pragma warning(disable: 4251)
			/// Colors in the line.
			std::array<int, SLOT_COUNT> colors;
#pragma warning(default: 4251)

		public:
			ColorCode(std::array<int, SLOT_COUNT> &col);
			ColorCode(int col[]);
			~ColorCode();

			/// Get color at index.
			int get(std::size_t index);

			/// Get color at index.
			int operator[](std::size_t i);

			/// Get color at index.
			const int operator[](std::size_t i) const;

			/// Test equality to other ColorCode. true if colors and their positions are the same.
			const bool operator==(const ColorCode &rhs) const;

			/// String representation of ColorCode.
			virtual std::wstring toString();
			/// String representation of ColorCode.
			virtual std::wstring toString() const;
		};
	}
}