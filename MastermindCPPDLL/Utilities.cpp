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
				color_t cols[Mastermind::SLOT_COUNT];
				std::random_device rd;
				std::mt19937 rng(rd());
				std::uniform_int_distribution<int> uni(0, Mastermind::COLOR_COUNT);
				for (std::size_t i = 0; i < Mastermind::SLOT_COUNT; ++i)
				{
					cols[i] = uni(rng);
				}
				return ColorCode(cols);
			}

			void Utilities::split(const std::wstring& s, char delim, std::list<std::wstring>& elems)
			{
				std::istringstream ss;
				std::string str(s.begin(), s.end());
				ss.str(str);
				std::string item;
				while (std::getline(ss, item, delim))
				{
					std::wstring wstr(item.begin(), item.end());
					elems.push_back(wstr);
				}
			}

			std::list<std::wstring> Utilities::split(const std::wstring& s, char delim)
			{
				std::list<std::wstring> elems;
				split(s, delim, elems);
				return elems;
			}

			std::list<int*> Utilities::parseString(const std::wstring& s)
			{
				std::list<std::wstring> tokens = split(s, ' ');
				std::list<int*> result;
				for (std::list<std::wstring>::iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
				{
					int* curr;
					try
					{
						curr = new int(stoi(*iter));
						result.push_back(curr);
					}
					catch (std::invalid_argument)
					{
						// just ignore
					}
					catch (std::out_of_range)
					{
						// just ignore
					}
				}
				return result;
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
