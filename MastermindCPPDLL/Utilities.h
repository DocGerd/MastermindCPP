#pragma once
#include "API.h"

#include "ColorCode.h"

#include <list>

namespace mastermind
{
	namespace shell
	{
		namespace utilities
		{
			using namespace mastermind::logic;

			/**
			 * \brief Reinterpreter for list conversions.
			 * \param From type to cast from
			 * \param To type to cast to
			 * \param p pointer to cast
			 * \return the casted pointer
			 */
			template<typename From, typename To>
			struct MASTERMINDCPPDLL_API reinterpret_caster
			{
				To* operator()(From* p)
				{
					return reinterpret_cast<To*>(p);
				}
			};

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
				static std::list<int*> parseString(const std::wstring& s);

				/**
				 * \brief Create alphabet string for the representation of the board.
				 * \return string in the form L"a b c d e" etc.
				 */
				static std::wstring createAlphabet();

			protected:
				static void split(const std::wstring& s, char delim, std::list<std::wstring>& elems);
				/**
				* \brief Split a string at given delimiters.
				* \param s the string to be split
				* \param delim the delimiter
				* \return the tokens
				*/
				static std::list<std::wstring> split(const std::wstring& s, char delim);
			};
		}
	}
}
