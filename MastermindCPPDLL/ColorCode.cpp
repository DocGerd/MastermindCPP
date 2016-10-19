

#include "stdafx.h"

#include "ColorCode.h"

#include <stdexcept>

namespace mastermind {
	ColorCode::ColorCode(std::array<int, SLOT_COUNT> &col) :
		colors(col)
	{
	}

	ColorCode::~ColorCode()
	{
	}

	int ColorCode::get(std::size_t index) {
		return this->colors[index];
	}

	//template<std::size_t slot_count>
	//int ColorCode<slot_count>::operator[](std::size_t i) {
	//	return this->colors[i];
	//}

	const int ColorCode::operator[](std::size_t i) const {
		return this->colors[i];
	}

	std::wstring ColorCode::toString() {
		std::wstring result(L"");
		for (std::size_t i = 0; i < SLOT_COUNT; ++i) {
			result.append(std::to_wstring(this->colors[i]));
			result.append(L" ");
		}
		return result;
	}
}