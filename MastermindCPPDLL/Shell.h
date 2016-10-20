#pragma once

#include "API.h"
#include "Mastermind.h"

namespace mastermind {
	namespace shell {
		class MASTERMINDCPPDLL_API Shell : public Mastermind {
		public:
			static int main();
		};
	}
}