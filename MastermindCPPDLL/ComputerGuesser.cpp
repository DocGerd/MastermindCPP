#include "stdafx.h"

#include "ComputerGuesser.h"
#include "ComputerEvaluator.h"
#include <iostream>

namespace mastermind {
	namespace logic {
		ComputerGuesser::ComputerGuesser() :
			moveCount(0), cheated(false) {
			createCodes();
		}

		ColorCode* ComputerGuesser::nextGuess() {
			ColorCode *result = NULL;
			if (!cheated) {
				result = &possibleCodes.front();
				++moveCount;
			}
			return result;
		}

		void ComputerGuesser::processEvaluation(const BlackAndWhite &bw) {
			// win situation
			if (bw == BlackAndWhite::WIN_STICKS) {
				std::cout << L"Wow! I did it!" << std::endl;
			}
			else {
				// remove ColorCodes which cannot be possible anymore.
				ComputerEvaluator evaluator(possibleCodes.front());
				for (std::list<ColorCode>::iterator iter = possibleCodes.begin(); iter != possibleCodes.end(); ++iter) {
					BlackAndWhite curr = *evaluator.evaluate(*iter);
					if (curr != bw) {
						possibleCodes.erase(iter);
					}
				}

				// lost situation
				if (moveCount == MAX_MOVES) {
					std::cout << L"no more moves - I couldn't find a solution" << std::endl;
				}
				// cheating situation
				else if (possibleCodes.empty()) {
					std::cout << L"no possibilities left - you have been cheating!" << std::endl;
					cheated = true;
				}
			}
		}

		void ComputerGuesser::createCodes() {
			possibleCodes = std::list<ColorCode>();
			int colors[SLOT_COUNT];
			for (size_t i = 0; i < SLOT_COUNT; ++i) {
				colors[i] = 0;
			}
			possibleCodes.push_back(ColorCode(colors));
			const std::size_t code_count = CODE_COUNT();
			for (std::size_t i = 1; i < code_count; ++i) {
				colors[SLOT_COUNT - 1] = i % COLOR_COUNT;
				for (std::size_t j = 1; j < SLOT_COUNT; ++j) {
					colors[SLOT_COUNT - 1 - j] =
						(i / POWER(COLOR_COUNT, j)) % COLOR_COUNT;
				}
				possibleCodes.push_back(ColorCode(colors));
			}
		}
	}
}