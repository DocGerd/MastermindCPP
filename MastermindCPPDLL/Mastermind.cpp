#include "stdafx.h"

#include "Mastermind.h"
#include "Utilities.h"


namespace mastermind
{
	namespace logic
	{
		Mastermind::Mastermind(uint32_t max_moves,
			uint32_t slot_count,
			uint32_t color_count) :
			max_moves(max_moves),
			slot_count(slot_count),
			color_count(color_count),
			code_count(shell::utilities::Utilities::POWER(color_count, slot_count))
		{
		}

		uint32_t Mastermind::getMaxMoves() const
		{
			return max_moves;
		}

		uint32_t Mastermind::getSlotCount() const
		{
			return slot_count;
		}

		uint32_t Mastermind::getColorCount() const
		{
			return color_count;
		}

		uint64_t Mastermind::getCodeCount() const
		{
			return code_count;
		}

		bool Mastermind::isWinStick(const logic::BlackAndWhite& bw) const
		{
			if (bw.getWhite() == 0 && bw.getBlack() == getSlotCount())
			{
				return true;
			}
			return false;
		}
	}
}
