#pragma once

#include "API.h"

#include <string>

namespace mastermind
{
	/**
	 * \brief Class for important global game values.
	 */
	class MASTERMINDCPPDLL_API Mastermind
	{
	public:
		/**
		 * \brief Destruct this.
		 */
		virtual ~Mastermind()
		{
		}

		/**
		 * \brief Maximum moves allowed until game finished.
		 */
		static constexpr std::size_t MAX_MOVES = 7;
		/**
		 * \brief Amount of slots for colors.
		 */
		static constexpr std::size_t SLOT_COUNT = 4;
		/**
		 * \brief Amount of available colors.
		 */
		static constexpr std::size_t COLOR_COUNT = 6;

		/**
		 * \brief Amount of possible solutions.
		 * \return number of possible solutions.
		 */
		static unsigned long CODE_COUNT()
		{
			return POWER(COLOR_COUNT, SLOT_COUNT);
		}

		/**
		 * \brief Calculate power of two int values.
		 * \return lhs^rhs
		 */
		static unsigned long POWER(int lhs, int rhs)
		{
			unsigned long result = lhs;
			for (auto i = 1; i < rhs; ++i)
			{
				result *= lhs;
			}
			return result;
		}
	};
}
