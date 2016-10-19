#pragma once

#include "API.h"

#include <string>

namespace mastermind {
	class MASTERMINDCPPDLL_API Mastermind {
	public:
		static constexpr std::size_t MAX_MOVES = 7;
		static constexpr std::size_t SLOT_COUNT = 4;
		static constexpr std::size_t COLOR_COUNT = 6;
		
		static inline unsigned long CODE_COUNT() {
			unsigned long result = COLOR_COUNT;
			for (auto i = 1; i < SLOT_COUNT; ++i) {
				result *= COLOR_COUNT;
			}
			return result;
		}

	public:
		virtual std::wstring toString() abstract;
	};
}
