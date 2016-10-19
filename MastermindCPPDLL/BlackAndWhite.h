#pragma once

#include "API.h"

#include <string>

namespace mastermind {
	class MASTERMINDCPPDLL_API BlackAndWhite {
	private:
		const unsigned int white;
		const unsigned int black;

	public:
		BlackAndWhite(unsigned int blacks, unsigned int whites);

		virtual std::wstring toString();
		std::wstring toStringWithoutDescription();
		bool operator==(const BlackAndWhite& rhs);
		bool operator!=(const BlackAndWhite& rhs);
	};
}