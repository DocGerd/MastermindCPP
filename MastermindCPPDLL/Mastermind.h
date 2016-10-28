#pragma once

#include "API.h"
#include "BlackAndWhite.h"

namespace mastermind
{
	namespace logic {
		/**
		 * \brief Class for important global game values.
		 */
		class MASTERMINDCPPDLL_API Mastermind
		{
		private:
			/**
			* \brief Maximum moves allowed until game finished.
			*/
			static constexpr uint32_t DEFAULT_MAX_MOVES = 7;
			/**
			* \brief Amount of slots for colors.
			*/
			static constexpr uint32_t DEFAULT_SLOT_COUNT = 4;
			/**
			* \brief Amount of available colors.
			*/
			static constexpr uint32_t DEFAULT_COLOR_COUNT = 6;

			/**
			* \brief Maximum moves allowed until game finished.
			*/
			const uint32_t max_moves;
			/**
			* \brief Amount of slots for colors.
			*/
			const uint32_t slot_count;
			/**
			* \brief Amount of available colors.
			*/
			const uint32_t color_count;
			/**
			* \brief Amount of possible codes.
			*/
			const uint64_t code_count;

		public:
			Mastermind(uint32_t max_moves = DEFAULT_MAX_MOVES,
				uint32_t slot_count = DEFAULT_SLOT_COUNT,
				uint32_t color_count = DEFAULT_COLOR_COUNT);

			/**
			 * \brief Get max moves.
			 * \return max moves
			 */
			uint32_t getMaxMoves() const;
			/**
			 * \brief Get slot count.
			 * \return slot count
			 */
			uint32_t getSlotCount() const;
			/**
			 * \brief Get color count.
			 * \return color count
			 */
			uint32_t getColorCount() const;
			/**
			 * \brief Get code count.
			 * \return code count
			 */
			uint64_t getCodeCount() const;


			bool isWinStick(const BlackAndWhite& bw) const;
		};
	}
}
