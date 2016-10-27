#include "stdafx.h"
#include "HumanGuesser.h"
#include "Utilities.h"
#include <iostream>

namespace mastermind
{
	namespace logic
	{
		const std::wstring HumanGuesser::HELP_TEXT = std::wstring(L"Available actions:")
		+ L"\nhelp: Print this help message."
		+ L"\ncancel: Cancel the current game."
		+ L"\nprint: Print the history of the game."
		+ L"\n" + mastermind::shell::utilities::Utilities::createAlphabet()
		+ L": Enter next guess with colors "
		+ mastermind::shell::utilities::Utilities::createAlphabet() + L"."
		+ L"\n\tColors are from 0 to " + std::to_wstring(COLOR_COUNT - 1)
		+ L"\n\twrong numbers will count as a try";

		HumanGuesser::HumanGuesser(ReadOnlyHistory* h) :
			history(h)
		{
		}

		ColorCode* HumanGuesser::nextGuess()
		{
			ColorCode* cc = nullptr;
			bool wait = true;
			while (wait)
			{
				std::wcout << L"next guess> ";
				std::wstring input;
				std::getline(std::wcin, input);
				if (input == L"help")
				{
					std::wcout << HELP_TEXT << std::endl;
					wait = true;
				}
				else if (input == L"cancel")
				{
					cc = nullptr;
					std::wcout << L"Game aborted." << std::endl;
					wait = false;
				}
				else if (input == L"print")
				{
					std::wcout << history->toString();
					wait = true;
				}
				else
				{
					std::list<int*> colors = mastermind::shell::utilities::Utilities::parseString(input);
					if (colors.size() == SLOT_COUNT)
					{
						std::list<color_t*> colorsN;
						std::transform(colors.begin(), colors.end(), std::back_inserter(colorsN), shell::utilities::reinterpret_caster<int, color_t>());
						cc = new ColorCode(colorsN);
						wait = false;
					}
					else
					{
						std::wcout << L"Error! Incorrect input" << std::endl;
						wait = true;
					}
				}
			}

			return cc;
		}

		void HumanGuesser::processEvaluation(const BlackAndWhite& bw)
		{
			std::wcout << bw.toString() << std::endl;

			if (bw == BlackAndWhite::WIN_STICKS)
			{
				std::wcout << L"Congratulations!" << std::endl;
			}
		}
	}
}
