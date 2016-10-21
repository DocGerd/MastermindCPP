#include "stdafx.h"

#include "HumanEvaluator.h"
#include "Utilities.h"

#include <iostream>

namespace mastermind {
	namespace logic {
		const std::wstring HumanEvaluator::HELP_TEXT = std::wstring(L"Available actions:")
			+ L"\nhelp: Print this help message."
			+ L"\ncancel: Cancel the current game."
			+ L"\nprint: Print the history of the game."
			+ L"\nb w: Evaluate last guess with black & white sticks."
			+ L"\n\tb and w from 0 to " + std::to_wstring(Mastermind::SLOT_COUNT)
			+ L" and b + w < " + std::to_wstring(Mastermind::SLOT_COUNT)
			+ L"\n\twrong numbers will be dealt as cheating!";

		HumanEvaluator::HumanEvaluator(ReadOnlyHistory* h) :
			history(h) {
		}

		BlackAndWhite* HumanEvaluator::evaluate(const ColorCode& cc) {
			BlackAndWhite* bw = NULL;
			std::wcout << L"machine guess: " << cc.toString() << std::endl;

			bool wait = true;
			while (wait) {
				std::wcout << L"evaluation> ";
				std::wstring input;
				std::wcin >> input;
				if (input == L"help") {
					std::wcout << HELP_TEXT << std::endl;
					wait = true;
				}
				else if (input == L"cancel") {
					bw = NULL;
					std::wcout << L"Game aborted." << std::endl;
					wait = false;
				}
				else if (input == L"print") {
					std::wcout << history->toString() << std::endl;
					wait = true;
				}
				else {
					// FIXME: parsing bug.
					std::list<int> sticks = mastermind::shell::utilities::Utilities::parseString(input);
					if (sticks.size() == 2) {
						bw = new BlackAndWhite(sticks);
						wait = false;
					}
					else {
						std::wcout << L"Error! Incorrect input" << std::endl;
						wait = true;
					}
				}
			}

			return bw;
		}

		ColorCode* HumanEvaluator::getSolution() {
			return NULL;
		}
	}
}