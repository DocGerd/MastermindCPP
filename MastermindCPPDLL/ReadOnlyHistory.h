#pragma once

#include "API.h"
#include "GameHistory.h"

namespace mastermind {
	namespace logic {
		/// Read-only history to ensure invariant of history.
		class MASTERMINDCPPDLL_API ReadOnlyHistory {
		private:
			/// The history.
			GameHistory* const history;

		public:
			/*!
			 * Create a read-only history.
			 * @param h the base history
			*/
			ReadOnlyHistory(GameHistory *h);

			/*!
			 * Get string of this history.
			 * @return the string
			 */
			std::wstring toString();
		};
	}
}