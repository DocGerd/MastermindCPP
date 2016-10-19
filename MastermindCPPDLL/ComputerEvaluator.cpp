#include "stdafx.h"
#include "ComputerEvaluator.h"

namespace mastermind {

	ComputerEvaluator::ComputerEvaluator(ColorCode solutionCode) :
		solution(solutionCode), moveCount(0)
	{
	}

	ComputerEvaluator::~ComputerEvaluator() {
	}

	BlackAndWhite* ComputerEvaluator::evaluate(const ColorCode &cc) {
		std::size_t black = 0;
		std::size_t white = 0;

		bool* checkedSol = new bool[SLOT_COUNT];
		bool* checkedCc = new bool[SLOT_COUNT];

		// check blacks
		for (std::size_t i = 0; i < SLOT_COUNT; ++i) {
			if (cc[i] == solution[i]) {
				checkedSol[i] = true;
				checkedCc[i] = true;
				++black;
			}
		}
		
		// check whites
		for (std::size_t i = 0; i < SLOT_COUNT; ++i) {
			for (std::size_t j = 0; j < SLOT_COUNT && !checkedSol[i]; ++j) {
				if (!checkedCc[j]) {
					if (solution[i] == cc[j]) {
						checkedCc[j] = true;
						checkedSol[i] = true;
						++white;
					}
				}
			}
		}

		++moveCount;

		return new BlackAndWhite(black, white);
	}

	ColorCode* ComputerEvaluator::getSolution() {
		ColorCode* result = NULL;
		if (moveCount >= MAX_MOVES) {
			result = new ColorCode(solution);
		}
		return result;
	}
}