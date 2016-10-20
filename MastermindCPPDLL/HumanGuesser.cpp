#include "stdafx.h"
#include "HumanGuesser.h"

#include <iostream>

namespace mastermind {
	namespace logic {
		HumanGuesser::HumanGuesser(ReadOnlyHistory *h) :
			history(h) {
		}

		ColorCode* HumanGuesser::nextGuess() {
			ColorCode* cc = NULL;
			bool wait = true;
			while (wait) {
				std::wcout << L"next guess> ";
				std::wstring input;
				std::wcin >> input;
				if (input == L"help") {
					std::wcout << L"TODO HELP TEXT" << std::endl;
					wait = true;
				}
				else if (input == L"cancel") {
					cc = NULL;
					std::wcout << L"Game aborted." << std::endl;
					wait = false;
				}
				else if (input == L"print") {
					std::wcout << history->toString();
					wait = true;
				}
				else {
					// TODO
				}
			}

			return cc;
		}

		void HumanGuesser::processEvaluation(const BlackAndWhite &bw) {
			std::wcout << bw.toString() << std::endl;

			if (bw == BlackAndWhite::WIN_STICKS) {
				std::wcout << L"Congratulations!" << std::endl;
			}
		}
	}
}