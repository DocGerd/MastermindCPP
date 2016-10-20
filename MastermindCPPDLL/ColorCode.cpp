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

	int ColorCode::operator[](std::size_t i) {
		return this->colors[i];
	}

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

	const bool ColorCode::operator==(const ColorCode &rhs) const {
		bool result = true;
		for (std::size_t i = 0; i < SLOT_COUNT && result; ++i) {
			if (this->colors[i] != rhs.colors[i]) {
				result = false;
			}
		}
		return result;
	}
}