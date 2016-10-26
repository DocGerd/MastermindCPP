#include "stdafx.h"

#include "ColorCode.h"

namespace mastermind
{
	namespace logic
	{
		ColorCode::ColorCode(std::array<std::size_t, SLOT_COUNT>& col) :
			colors(col)
		{
		}

		ColorCode::ColorCode(std::list<std::size_t>& list)
		{
			const size_t size = list.size();
			std::list<std::size_t>::iterator iter = list.begin();
			for (size_t i = 0; i < size && iter != list.end(); ++i)
			{
				colors[i] = *iter;
				++iter;
			}
		}

		ColorCode::ColorCode(std::size_t col[])
		{
			for (std::size_t i = 0; i < SLOT_COUNT; ++i)
			{
				colors[i] = col[i];
			}
		}

		ColorCode::~ColorCode()
		{
		}

		int ColorCode::get(std::size_t index)
		{
			return this->colors[index];
		}

		int ColorCode::operator[](std::size_t i) const
		{
			return this->colors[i];
		}

		std::wstring ColorCode::toString()
		{
			std::wstring result(L"");
			for (std::size_t i = 0; i < SLOT_COUNT; ++i)
			{
				result.append(std::to_wstring(this->colors[i]));
				result.append(L" ");
			}
			return result;
		}

		std::wstring ColorCode::toString() const
		{
			std::wstring result(L"");
			for (std::size_t i = 0; i < SLOT_COUNT; ++i)
			{
				result.append(std::to_wstring(this->colors[i]));
				result.append(L" ");
			}
			return result;
		}

		bool ColorCode::operator==(const ColorCode& rhs) const
		{
			bool result = true;
			for (std::size_t i = 0; i < SLOT_COUNT && result; ++i)
			{
				if (this->colors[i] != rhs.colors[i])
				{
					result = false;
				}
			}
			return result;
		}
	}
}
