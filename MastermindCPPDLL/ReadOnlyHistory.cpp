#include "stdafx.h"

#include "ReadOnlyHistory.h"

namespace mastermind
{
	namespace logic
	{
		ReadOnlyHistory::ReadOnlyHistory(GameHistory* h) :
			history(h)
		{
			if (h == nullptr)
			{
				throw std::invalid_argument("h must not be nullptr!");
			}
		}

		std::wstring ReadOnlyHistory::toString() const
		{
			return history->toString();
		}
	}
}
