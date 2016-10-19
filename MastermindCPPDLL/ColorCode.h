#pragma once

#include "API.h"

#include <string>
#include <array>

namespace mastermind {
	// FIXME:  Template makes no real sense here...
	template<std::size_t slot_count = 4>
	class MASTERMINDCPPDLL_API ColorCode {
	private:
#pragma warning(disable: 4251)
		std::array<int, slot_count> colors;
#pragma warning(default: 4251)

	public:
		ColorCode(std::array<int, slot_count> &col);
		~ColorCode();
		int get(std::size_t index);
		//int operator[](std::size_t i);
		const int operator[](std::size_t i) const;

		virtual std::wstring toString();

		static std::size_t getSlotCount() {
			return slot_count;
		}
	};

	//template class ColorCode<4>;
}