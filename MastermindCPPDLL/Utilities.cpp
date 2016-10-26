#include "stdafx.h"

#include "Utilities.h"
#include "Mastermind.h"

#include <sstream>
#include <random>

namespace mastermind
{
	namespace shell
	{
		namespace utilities
		{
			using namespace mastermind::logic;

			ColorCode Utilities::createRandomCode()
			{
				std::size_t cols[Mastermind::SLOT_COUNT];
				std::random_device rd;
				std::mt19937 rng(rd());
				std::uniform_int_distribution<int> uni(0, Mastermind::COLOR_COUNT);
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT; ++i)
				{
					cols[i] = uni(rng);
				}
				return ColorCode(cols);
			}

			void Utilities::split(const std::wstring& s, char delim, std::list<std::size_t>& elems)
			{
				std::istringstream ss;
				std::string str(s.begin(), s.end());
				ss.str(str);
				std::string item;
				while (std::getline(ss, item, delim))
				{
					int token = -1;
					bool success = true;
					try
					{
						token = stoi(item);
					}
					catch (std::invalid_argument)
					{
						success = false;
					}
					if (success)
					{
						elems.push_back(token);
					}
				}
			}

			std::list<std::size_t> Utilities::split(const std::wstring& s, char delim)
			{
				std::list<std::size_t> elems;
				split(s, delim, elems);
				return elems;
			}

			std::list<std::size_t> Utilities::parseString(const std::wstring& s)
			{
				std::list<std::size_t> tokens = split(s, ' ');
				return tokens;
			}

			std::wstring Utilities::createAlphabet()
			{
				wchar_t c = 'a';
				std::wstring result = L"";
				result.append(1, c);
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT - 1; ++i)
				{
					++c;
					result.append(L" ");
					result.append(1, c);
				}
				return result;
			}
		}
	}
}
