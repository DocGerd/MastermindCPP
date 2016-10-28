#include "stdafx.h"

#include "ColorCode.h"

#include <string>

namespace mastermind
{
	namespace logic
	{
		ColorCode::ColorCode(std::vector<color_t>& col) :
			colors(col)
		{
		}

		ColorCode::ColorCode(std::list<color_t*>& list)
		{
			const size_t size = list.size();
			std::list<color_t*>::iterator iter = list.begin();
			for (size_t i = 0; i < size && iter != list.end(); ++i)
			{
				colors.push_back(**iter);
				++iter;
			}
		}

		ColorCode::ColorCode(size_t size, color_t col[])
		{
			for (size_t i = 0; i < size; ++i)
			{
				colors.push_back(col[i]);
			}
		}

		ColorCode::~ColorCode()
		{
		}

		color_t ColorCode::get(std::size_t index)
		{
			return this->colors[index];
		}

		color_t ColorCode::operator[](std::size_t i) const
		{
			return this->colors[i];
		}
		
		std::wstring ColorCode::toString() const
		{
			std::wstring result(L"");
			for (std::size_t i = 0; i < colors.size(); ++i)
			{
				result.append(std::to_wstring(this->colors[i]));
				result.append(L" ");
			}
			return result;
		}

		bool ColorCode::operator==(const ColorCode& rhs) const
		{
			bool result = true;
			for (std::size_t i = 0; i < colors.size() && result; ++i)
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
