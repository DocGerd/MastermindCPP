#pragma once

#include "API.h"

#include "Mastermind.h"

#include <array>
#include <list>

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Represents one line of the game board.
		 */
		class MASTERMINDCPPDLL_API ColorCode : public Mastermind
		{
		private:
#pragma warning(disable: 4251)
			/**
			 * \brief Colors in the line.
			 */
			std::array<std::size_t, SLOT_COUNT> colors;
#pragma warning(default: 4251)

		public:
			/**
			 * \brief Create a ColorCode.
			 * \param col columns as std::array
			 */
			ColorCode(std::array<std::size_t, SLOT_COUNT>& col);
			/**
			* \brief Create a ColorCode.
			* \param col columns as std::size_t[]
			*/
			ColorCode(std::size_t col[]);
			/**
			* \brief Create a ColorCode.
			* \param list columns as std::list
			*/
			ColorCode(std::list<std::size_t>& list);
			/**
			 * \brief Destruct this.
			 */
			~ColorCode();

			/**
			 * \brief Get color at index.
			 * \param index the index
			 * \return color at index
			 */
			int get(std::size_t index);

			/**
			 * \brief Get color at index.
			 * \param i the index
			 * \return color at index
			 */
			int operator[](std::size_t i) const;

			/**
			 * \brief Test equality to other ColorCode.
			 * \para rhs the other ColorCode
			 * \return \c true if colors and their positions are the same.
			 */
			bool operator==(const ColorCode& rhs) const;

			/**
			 * \brief String representation of ColorCode.
			 * \return the string
			 */
			virtual std::wstring toString();
			/**
			 * \brief String representation of ColorCode.
			 * \return the string
			 */
			virtual std::wstring toString() const;
		};
	}
}
