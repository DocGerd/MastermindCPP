#pragma once

#include "API.h"

#include "Mastermind.h"

#include <string>
#include <array>

namespace mastermind {
	class MASTERMINDCPPDLL_API ColorCode : public Mastermind {
	private:
#pragma warning(disable: 4251)
		std::array<int, SLOT_COUNT> colors;
#pragma warning(default: 4251)

	public:
		ColorCode(std::array<int, SLOT_COUNT> &col);
		~ColorCode();
		int get(std::size_t index);
		int operator[](std::size_t i);
		const int operator[](std::size_t i) const;
		const bool operator==(const ColorCode &rhs) const;

		virtual std::wstring toString();
	};
}