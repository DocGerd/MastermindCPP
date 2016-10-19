#pragma once

#include "API.h"

#include <string>

namespace mastermind {
	class MASTERMINDCPPDLL_API Mastermind {
	private:
		static constexpr std::size_t mMAX_MOVES = 7;
		static constexpr std::size_t mSLOT_COUNT = 4;
		static constexpr std::size_t mCOLOR_COUNT = 6;
		
	public:
		static inline std::size_t MAX_MOVES() {
			return Mastermind::mMAX_MOVES;
		}
		static inline std::size_t SLOT_COUNT() {
			return Mastermind::mSLOT_COUNT;
		}
		static inline std::size_t COLOR_COUNT() {
			return Mastermind::mCOLOR_COUNT;
		}
		static inline unsigned long CODE_COUNT() {
			unsigned long result = mCOLOR_COUNT;
			for (auto i = 1; i < mSLOT_COUNT; ++i) {
				result *= mCOLOR_COUNT;
			}
			return result;
		}

	public:
		virtual std::wstring toString() abstract;
	};
}
