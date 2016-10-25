#pragma once
#include "API.h"

#include "ColorCode.h"

#include <string>
#include <list>

namespace mastermind
{
	namespace shell
	{
		namespace utilities
		{
			using namespace mastermind::logic;

			/**
			 * \brief Utilities class.
			 */
			class MASTERMINDCPPDLL_API Utilities
			{
			public:
				/**
				* \brief Create a random ColorCode.
				* \return the ColorCode
				*/
				static ColorCode createRandomCode();

				/**
				* \brief Parse a string for numbers. Used for input of ColorCodes.
				* \param s the string to be parsed
				* \return the tokens
				*/
				static std::list<int> parseString(const std::wstring& s);

				/**
				 * \brief Create alphabet string for the representation of the board.
				 * \return string in the form L"a b c d e" etc.
				 */
				static std::wstring createAlphabet();

			protected:
				static void split(const std::wstring& s, char delim, std::list<int>& elems);
				/**
				* \brief Split a string at given delimiters.
				* \param s the string to be split
				* \param delim the delimiter
				* \return the tokens
				*/
				static std::list<int> split(const std::wstring& s, char delim);
			};
		}
	}
}
