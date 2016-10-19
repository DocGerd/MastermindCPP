

#include "stdafx.h"

#include "ColorCode.h"

#include <stdexcept>

namespace mastermind {
	template<std::size_t slot_count>
	ColorCode<slot_count>::ColorCode(std::array<int, slot_count> &col) :
		colors(col)
	{
	}

	template<std::size_t slot_count>
	ColorCode<slot_count>::~ColorCode()
	{
	}

	template<std::size_t slot_count>
	int ColorCode<slot_count>::get(std::size_t index) {
		return this->colors[index];
	}

	//template<std::size_t slot_count>
	//int ColorCode<slot_count>::operator[](std::size_t i) {
	//	return this->colors[i];
	//}

	template<std::size_t slot_count>
	const int ColorCode<slot_count>::operator[](std::size_t i) const {
		return this->colors[i];
	}

	template<std::size_t slot_count>
	std::wstring ColorCode<slot_count>::toString() {
		std::wstring result(L"");
		for (std::size_t i = 0; i < slot_count; ++i) {
			result.append(std::to_wstring(this->colors[i]));
			result.append(L" ");
		}
		return result;
	}
}