#pragma once

#include "ColorCode.h"
#include <random>

namespace mastermind {
	namespace shell {
		namespace utilities {
			using namespace mastermind::logic;

			/// Create a random ColorCode.
			/*!
			 * @return the ColorCode
			*/
			ColorCode createRandomCode() {
				int cols[Mastermind::SLOT_COUNT];
				std::random_device rd;
				std::mt19937 rng(rd());
				std::uniform_int_distribution<int> uni(0, Mastermind::COLOR_COUNT);
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT; ++i) {
					cols[i] = uni(rng);
				}
				return ColorCode(cols);
			}

			int* parseString(std::wstring s) {
				// TODO
			}

			/// Create alphabet string for the representation of the board.
			std::wstring createAlphabet() {
				char c = 'a';
				std::wstring result = L"";
				result.append(std::to_wstring(c));
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT - 1; ++i) {
					++c;
					result.append(L" ");
					result.append(std::to_wstring(c));
				}
				return result;
			}
		}
	}
}