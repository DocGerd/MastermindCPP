#pragma once

#include "API.h"

#include <list>

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Representation for evaluation sticks.
		 * Black sticks show color and position right.
		 * White sticks show color right but wrong position.
		 */
		class MASTERMINDCPPDLL_API BlackAndWhite
		{
		private:
			/**
			* \brief amount black sticks.
			*/
			std::size_t black;
			/**
			 * \brief amount white sticks.
			 */
			std::size_t white;
		public:

			/**
			 * \brief Create BlackAndWhite.
			 * \param blacks amount of black sticks
			 * \param whites amount of white sticks
			 */
			BlackAndWhite(std::size_t blacks, std::size_t whites);
			/**
			 * \brief Create BlackAndWhite.
			 * \param sticks list with <tt>size == 2</tt>, first is blacks and second is whites
			 */
			BlackAndWhite(std::list<std::size_t*>& sticks);

			/**
			 * \brief Get string representation.
			 * \return string in format <tt>"black: %i white: %i"</tt>
			 */
			virtual std::wstring toString() const;

			/**
			 * \brief Get string representation.
			 * \return string in format <tt>"%i %i"</tt>
			 */
			std::wstring toStringWithoutDescription() const;

			/**
			 * \brief Test equality.
			 * \param rhs the right hand side BlackAndWhite
			 * \return \c true if amount of white left and right is equal and amount of black left and right is equal.
			 */
			bool operator==(const BlackAndWhite& rhs) const;

			/**
			 * \brief Test inequality.
			 * \param rhs the right hand side BlackAndWhite
			 * \return \c true if <tt>!(a == b)</tt>
			 */
			bool operator!=(const BlackAndWhite& rhs) const;

			/**
			 * \brief Get amount of white sticks.
			 * \return amount of white sticks
			 */
			std::size_t getWhite() const;

			/**
			 * \brief Get amount of black sticks.
			 * \return amount of black sticks.
			 */
			std::size_t getBlack() const;
		};
	}
}
