#include "stdafx.h"
#include "HumanEvaluator.h"

#include <iostream>

namespace mastermind {
	namespace logic {
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
					std::wcout << L"TODO HELP TEXT" << std::endl;
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
					// TODO
				}
			}

			return bw;
		}

		ColorCode* HumanEvaluator::getSolution() {
			return NULL;
		}
	}
}