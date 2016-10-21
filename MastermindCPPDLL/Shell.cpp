#include "stdafx.h"
#include "Shell.h"
#include "RequestedState.h"
#include "GameHistory.h"
#include "MainGame.h"
#include "Players.h"
#include "IGuesser.h"
#include "IEvaluator.h"

#include <iostream>

namespace mastermind {
	namespace shell {
		const std::wstring Shell::HELP_TEXT = std::wstring(L"Available commands: ")
			+ L"\nhelp: Print this help message."
			+ L"\nstart: Start a new game in the current mode."
			+ L"\nquit: Terminate the programme."
			+ L"\nswitch: Change the game mode.";

		using namespace mastermind::logic;

		int Shell::main() {
			RequestedState state = RequestedState::HUMAN_GUESSER;

			bool quit = false;
			while (!quit) {
				std::wcout << L"mastermind> ";
				std::wstring input;
				std::wcin >> input;

				if (input == L"help") {
					std::wcout << HELP_TEXT << std::endl;
				}
				else if (input == L"start") {
					GameHistory* history = new GameHistory();
					Players* players = getPlayers(state, history);
					IGuesser* g = players->getGuesser();
					IEvaluator* e = players->getEvaluator();
					MainGame* mg = new MainGame(g, e, history);
					bool cancel = false;
					while (!cancel) {
						cancel = mg->next();
					}
					ColorCode *solution = e->getSolution();
					if (solution != NULL) {
						std::wcout << L"no more moves - solution: " << solution->toString() << std::endl;
					}
				}
				else if (input == L"quit") {
					quit = true;
				}
				else if (input == L"switch") {
					state = switchState(state);
				}
				else {
					std::wcout << L"Error! Incorrect input." << std::endl;
				}
			}

			return 0;
		}
	}
}