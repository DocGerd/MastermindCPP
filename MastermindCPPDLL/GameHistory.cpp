#include "stdafx.h"
#include "GameHistory.h"

namespace mastermind
{
	namespace logic
	{
		GameHistory::GameHistory() :
			colorCodes(new std::list<ColorCode>()), blackAndWhites(new std::list<BlackAndWhite>())
		{
		}

		GameHistory::~GameHistory()
		{
			delete colorCodes;
			delete blackAndWhites;
		}

		void GameHistory::add(const ColorCode& cc) const
		{
			if (colorCodes->size() != blackAndWhites->size())
			{
				throw std::logic_error("history corrupt");
			}
			colorCodes->push_back(cc);
		}

		void GameHistory::add(const BlackAndWhite& bw) const
		{
			if (colorCodes->size() - 1 != blackAndWhites->size())
			{
				throw std::logic_error("history corrupt");
			}
			blackAndWhites->push_back(bw);
		}

		std::wstring GameHistory::toString() const
		{
			// TODO: header
			std::wstring result = L"";

			std::list<ColorCode>::iterator iterCC = colorCodes->begin();
			std::list<BlackAndWhite>::iterator iterBW = blackAndWhites->begin();
			while (iterCC != colorCodes->end())
			{
				result.append(L"\n");
				result.append((*iterCC).toString());
				if (iterBW != blackAndWhites->end())
				{
					result.append(L" ");
					result.append((*iterBW).toStringWithoutDescription());
				}
				++iterCC;
			}

			return L"";
		}
	}
}
