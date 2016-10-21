#pragma once

#include "API.h"
#include "IEvaluator.h"
#include "Mastermind.h"
#include "ReadOnlyHistory.h"

namespace mastermind {
	namespace logic {
		class MASTERMINDCPPDLL_API HumanEvaluator : public virtual IEvaluator, public Mastermind {
		private:
			ReadOnlyHistory* const history;
#pragma warning(disable: 4251)
			static const std::wstring HELP_TEXT;
#pragma warning(default: 4251)

		public:
			HumanEvaluator(ReadOnlyHistory* h);

			BlackAndWhite* evaluate(const ColorCode& cc) override;
			ColorCode* getSolution() override;
		};
	}
}