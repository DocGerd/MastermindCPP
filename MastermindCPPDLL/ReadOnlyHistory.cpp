#include "stdafx.h"

#include "ReadOnlyHistory.h"

namespace mastermind {
	namespace logic {
		ReadOnlyHistory::ReadOnlyHistory(GameHistory* h) :
			history(h) {
		}

		std::wstring ReadOnlyHistory::toString() {
			return history->toString();
		}
	}
}