#include "stdafx.h"

#include "Shell.h"

#include "../MastermindCPPDLL/GameHistory.h"
#include "../MastermindCPPDLL/Players.h"
#include "../MastermindCPPDLL/MainGame.h"

namespace mastermind
{
	namespace shell
	{
		const std::wstring Shell::HELP_TEXT = std::wstring(L"Available commands: ")
			+ L"\nhelp: Print this help message."
			+ L"\nstart: Start a new game in the current mode."
			+ L"\nquit: Terminate the programme."
			+ L"\nswitch: Change the game mode.";

		using namespace mastermind::logic;

		Shell::Shell() :
			game()
		{
		}

		int Shell::main() const
		{
			State state(State::GameState::HUMAN_GUESSER);

			bool quit = false;
			while (!quit)
			{
				std::wcout << L"mastermind> ";
				std::wstring input;
				std::getline(std::wcin, input);

				if (input == L"help")
				{
					printHelp();
				}
				else if (input == L"start")
				{
					runMain(state);
				}
				else if (input == L"quit")
				{
					quit = true;
				}
				else if (input == L"switch")
				{
					state.switchState();
				}
				else
				{
					std::wcout << L"Error! Incorrect input." << std::endl;
				}
			}

			return 0;
		}

		void Shell::runMain(const State& state) const
		{
			GameHistory* history = new GameHistory();
			Players* players = Players::getPlayers(state, history);
			IGuesser* g = players->getGuesser();
			IEvaluator* e = players->getEvaluator();
			MainGame* mg = new MainGame(game, g, e, history);
			bool cancel = false;
			while (!cancel)
			{
				cancel = mg->next();
			}
			ColorCode* solution = e->getSolution();
			if (solution != nullptr)
			{
				std::wcout << L"no more moves - solution: " << solution->toString() << std::endl;
			}
		}


		void Shell::printHelp()
		{
			std::wcout << HELP_TEXT << std::endl;
		}

	}
}
