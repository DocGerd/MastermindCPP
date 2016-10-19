#pragma once

#ifdef MASTERMINDCPPDLL_EXPORTS
#define MASTERMINDCPPDLL_API __declspec(dllexport)
#else
#define MASTERMINDCPPDLL_API __declspec(dllimport)
#endif

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