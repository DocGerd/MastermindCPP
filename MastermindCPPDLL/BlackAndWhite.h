#pragma once

#include "API.h"
#include "Mastermind.h"

#include <string>
#include <list>

namespace mastermind {
	namespace logic {
		/// BlackAndWhite. Representation for evaluation sticks.
		/// Black sticks show color and position right.
		/// White sticks show color right but wrong position.
		class MASTERMINDCPPDLL_API BlackAndWhite : public Mastermind {
		private:
			/// amount white sticks.
			std::size_t white;
			/// amount black sticks.
			std::size_t black;
		public:
			/// Stick combination for a win. All black, zero white.
			static const BlackAndWhite WIN_STICKS;

		public:
			BlackAndWhite(std::size_t blacks, std::size_t whites);
			BlackAndWhite(std::list<int> &sticks);

			/// Get string representation. In format "black: %i white: %i".
			virtual std::wstring toString() const;

			/// Get string representation. In format "%i %i".
			std::wstring toStringWithoutDescription() const;

			/// Test equality.
			/*!
			* @param rhs the right hand side BlackAndWhite
			* @return \c true if amount of white left and right is equal and amount of black left and right is equal.
			*/
			bool operator==(const BlackAndWhite& rhs) const;

			/// Test inequality.
			/*!
			 * @param rhs the right hand side BlackAndWhite
			 * @return \c true if <tt>!(a == b)</tt>
			 */
			bool operator!=(const BlackAndWhite& rhs) const;

			/// Get amount of white sticks.
			/*!
			* @return amount of white sticks.
			*/
			std::size_t getWhite() const;

			/// Get amount of black sticks.
			/*!
			 * @return amount of black sticks.
			*/
			std::size_t getBlack() const;
		};
	}
}