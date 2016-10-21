#pragma once

#include "API.h"
#include "Mastermind.h"

namespace mastermind {
	namespace shell {
		class MASTERMINDCPPDLL_API Shell : public Mastermind {
		private:
#pragma warning(disable: 4251)
			static const std::wstring HELP_TEXT;
#pragma warning(default: 4251)
		public:
			static int main();
		};
	}
}