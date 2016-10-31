#include "stdafx.h"

#include "HumanEvaluator.h"
#include "Utilities.h"

#include <iostream>

namespace mastermind
{
	namespace logic
	{
		HumanEvaluator::HumanEvaluator(const Mastermind* game, ReadOnlyHistory* h) :
			game(game),
			history(h),
			HELP_TEXT(std::wstring(L"Available actions:")
				+ L"\nhelp: Print this help message."
				+ L"\ncancel: Cancel the current game."
				+ L"\nprint: Print the history of the game."
				+ L"\nb w: Evaluate last guess with black & white sticks."
				+ L"\n\tb and w from 0 to " + std::to_wstring(game->getSlotCount())
				+ L" and b + w < " + std::to_wstring(game->getSlotCount())
				+ L"\n\twrong numbers will be dealt as cheating!")
		{
			if (game == nullptr)
			{
				throw std::invalid_argument("game must not be nullptr!");
			}
			if (h == nullptr)
			{
				throw std::invalid_argument("h must not be nullptr!");
			}
		}

		BlackAndWhite* HumanEvaluator::evaluate(const ColorCode* cc)
		{
			if (cc == nullptr)
			{
				throw std::invalid_argument("cc must not be nullptr!");
			}

			BlackAndWhite* bw = nullptr;
			std::wcout << L"machine guess: " << cc->toString() << std::endl;

			bool wait = true;
			while (wait)
			{
				std::wcout << L"evaluation> ";
				std::wstring input;
				std::getline(std::wcin, input);
				if (input == L"help")
				{
					std::wcout << HELP_TEXT << std::endl;
					wait = true;
				}
				else if (input == L"cancel")
				{
					bw = nullptr;
					std::wcout << L"Game aborted." << std::endl;
					wait = false;
				}
				else if (input == L"print")
				{
					std::wcout << history->toString() << std::endl;
					wait = true;
				}
				else
				{
					std::list<int*> sticks = mastermind::shell::utilities::Utilities::parseString(input);
					if (sticks.size() == 2)
					{
						std::list<std::size_t*> sticksN;
						std::transform(sticks.begin(), sticks.end(), std::back_inserter(sticksN), shell::utilities::reinterpret_caster<int, std::size_t>());
						bw = new BlackAndWhite(sticksN);
						wait = false;
					}
					else
					{
						std::wcout << L"Error! Incorrect input" << std::endl;
						wait = true;
					}
				}
			}

			return bw;
		}

		ColorCode* HumanEvaluator::getSolution()
		{
			return nullptr;
		}
	}
}
