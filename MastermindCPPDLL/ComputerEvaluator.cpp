#include "stdafx.h"
#include "ComputerEvaluator.h"
#include "DEFAULTS.h"

#ifdef SLOT_COUNT
#undef SLOT_COUNT
#endif

namespace mastermind {

	ComputerEvaluator::ComputerEvaluator(ColorCode<> solutionCode) :
		solution(solutionCode), moveCount(0)
	{
	}

	ComputerEvaluator::~ComputerEvaluator() {
	}

	BlackAndWhite ComputerEvaluator::evaluate(const ColorCode<> &cc) {
		unsigned int black = 0;
		unsigned int white = 0;

		static const unsigned int SLOT_COUNT = ColorCode<>::getSlotCount();
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

		return BlackAndWhite(black, white);
	}

	ColorCode<>* ComputerEvaluator::getSolution() {
		ColorCode<>* result = NULL;
		if (moveCount >= MAX_MOVES) {
			result = new ColorCode<>(solution);
		}
		return result;
	}
}