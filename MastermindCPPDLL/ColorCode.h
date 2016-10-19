#pragma once

#include "API.h"

#include "Mastermind.h"

#include <string>
#include <array>

namespace mastermind {
	// FIXME:  Template makes no real sense here...
	class MASTERMINDCPPDLL_API ColorCode : public Mastermind {
	private:
#pragma warning(disable: 4251)
		std::array<int, SLOT_COUNT> colors;
#pragma warning(default: 4251)

	public:
		ColorCode(std::array<int, SLOT_COUNT> &col);
		~ColorCode();
		int get(std::size_t index);
		//int operator[](std::size_t i);
		const int operator[](std::size_t i) const;

		virtual std::wstring toString();
	};
}