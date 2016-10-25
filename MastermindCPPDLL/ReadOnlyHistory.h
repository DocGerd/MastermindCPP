#pragma once

#include "API.h"
#include "GameHistory.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Read-only history to ensure invariant of history.
		 */
		class MASTERMINDCPPDLL_API ReadOnlyHistory
		{
		private:
			/**
			 * \brief The history.
			 */
			GameHistory* const history;

		public:
			/**
			 * \brief Create a read-only history.
			 * \param h the base history
			 */
			ReadOnlyHistory(GameHistory* h);

			/**
			 * \brief Get string of this history.
			 * \return the string
			 */
			std::wstring toString() const;
		};
	}
}
