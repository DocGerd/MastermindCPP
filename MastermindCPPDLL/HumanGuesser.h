#pragma once

#include "API.h"
#include "IGuesser.h"
#include "Mastermind.h"
#include "ReadOnlyHistory.h"

namespace mastermind {
	namespace logic {
		class MASTERMINDCPPDLL_API HumanGuesser : public virtual IGuesser, public Mastermind {
		private:
			ReadOnlyHistory* const history;
#pragma warning(disable: 4251)
			static const std::wstring HELP_TEXT;
#pragma warning(default: 4251)

		public:
			HumanGuesser(ReadOnlyHistory *h);

			ColorCode* nextGuess() override;
			void processEvaluation(const BlackAndWhite &bw) override;
		};
	}
}