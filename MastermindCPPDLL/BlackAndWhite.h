#pragma once

#include "API.h"

#include <string>

namespace mastermind {
	class MASTERMINDCPPDLL_API BlackAndWhite {
	private:
		const std::size_t white;
		const std::size_t black;

	public:
		BlackAndWhite(std::size_t blacks, std::size_t whites);

		virtual std::wstring toString();
		std::wstring toStringWithoutDescription();
		bool operator==(const BlackAndWhite& rhs);
		const bool operator==(const BlackAndWhite& rhs) const;
		bool operator!=(const BlackAndWhite& rhs);
		std::size_t getWhite();
		std::size_t getBlack();
	};
}