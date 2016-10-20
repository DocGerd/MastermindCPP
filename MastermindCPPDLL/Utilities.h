#pragma once

#include "ColorCode.h"
#include <random>
#include <string>
#include <sstream>
#include <list>
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

			static void split(const std::wstring &s, char delim, std::list<int> &elems) {
				std::istringstream ss;
				std::string str(s.begin(), s.end());
				ss.str(str);
				std::string item;
				while (std::getline(ss, item, delim)) {
					elems.push_back(stoi(item));
				}
			}

			/*!
			 * Split a string at given delimiters.
			 * @param s the string to be split
			 * @param delim the delimiter
			 * @param the
			*/
			static std::list<int> split(const std::wstring &s, char delim) {
				std::list<int> elems;
				split(s, delim, elems);
				return elems;
			}

			/*!
			 * Parse a string for numbers. Used for input of ColorCodes.
			 * @param s the string to be parsed
			 * @return the tokens
			 */
			std::list<int> parseString(const std::wstring &s) {
				std::list<int> tokens = split(s, ' ');
				return tokens;
			}

			/// Create alphabet string for the representation of the board.
			std::wstring createAlphabet() {
				wchar_t c = 'a';
				std::wstring result = L"";
				result.append(1, c);
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT - 1; ++i) {
					++c;
					result.append(L" ");
					result.append(1, c);
				}
				return result;
			}
		}
	}
}