#include "stdafx.h"

#include "Color.h"


namespace mastermind
{
	namespace logic
	{
		Color::Color(uint8_t r, uint8_t g, uint8_t b) :
			red(r), green(g), blue(b)
		{
			// no check of parameters necessary as uint8_t is [0..255] anyway
		}

		uint8_t Color::getRed() const
		{
			return this->red;
		}

		uint8_t Color::getGreen() const
		{
			return this->green;
		}

		uint8_t Color::getBlue() const
		{
			return this->blue;
		}

		uint8_t* Color::getRGB() const
		{
			return new uint8_t[3]{ red, green, blue };
		}

		std::wstring Color::toString() const
		{
			std::wstring result = std::wstring(L"(")
				+ std::to_wstring(red) + L","
				+ std::to_wstring(green) + L","
				+ std::to_wstring(blue) + L")";
			return result;
		}

		bool Color::operator==(const Color& rhs) const
		{
			bool result = this->red == rhs.red
				&& this->green == rhs.green
				&& this->blue == rhs.blue;
			return result;
		}

		bool Color::operator!=(const Color& rhs) const
		{
			return !(*this == rhs);
		}
	}
}