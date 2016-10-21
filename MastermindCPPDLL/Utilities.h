#pragma once
#include "API.h"

#include "ColorCode.h"

#include <string>
#include <list>

namespace mastermind {
	namespace shell {
		namespace utilities {
			using namespace mastermind::logic;

			class MASTERMINDCPPDLL_API Utilities {
			public:
				/*! Create a random ColorCode.
				* @return the ColorCode
				*/
				static ColorCode createRandomCode();

				/*!
				* Parse a string for numbers. Used for input of ColorCodes.
				* @param s the string to be parsed
				* @return the tokens
				*/
				static std::list<int> parseString(const std::wstring &s);

				/// Create alphabet string for the representation of the board.
				static std::wstring createAlphabet();

			protected:
				static void split(const std::wstring &s, char delim, std::list<int> &elems);
				/*!
				* Split a string at given delimiters.
				* @param s the string to be split
				* @param delim the delimiter
				* @param the
				*/
				static std::list<int> split(const std::wstring &s, char delim);
			};
		}
	}
}