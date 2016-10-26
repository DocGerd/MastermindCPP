#include "stdafx.h"

#include "Color.h"

#include "ColorRGB.h"
#include "ColorHSI.h"


namespace mastermind
{
	namespace logic
	{
		Color::Color() :
			name(L"")
		{
		}

		Color::Color(std::wstring name) :
			name(name)
		{
		}

		std::wstring Color::getName() const
		{
			return this->name;
		}

		ColorRGB* Color::hsiToRGB(const ColorHSI& hsi)
		{
			const float hue = hsi.getHue() * M_PI / 180.0f;
			const float saturation = hsi.getSaturation();
			const float intensity = hsi.getIntensity();

			float r = -1.0f;
			float g = -1.0f;
			float b = -1.0f;

			// TODO: epsilon check
			if (saturation == 0.0f)
			{
				r = intensity;
				g = intensity;
				b = intensity;
			}
			else if (hue >= 0.0f && hue < 2.0f * M_PI / 3.0f)
			{
				b = (1.0f - saturation) / 3.0f;
				r = (1.0f + saturation * cos(hue) / cos(M_PI / 3.0f - hue)) / 3.0f;
				g = 1.0f - r - b;
			}
			else if (hue >= 2.0f * M_PI / 3.0f && hue < 4.0 * M_PI / 3.0f)
			{
				float hn = hue - 2.0f *M_PI / 3.0f;
				r = (1.0f - saturation) / 3.0f;
				g = (1.0f + saturation * cos(hn) / cos(M_PI / 3.0f - hn)) / 3.0f;
				b = 1.0f - r - g;
			}
			else if (hue >= 4.0f * M_PI / 3.0f && hue < 2.0f * M_PI)
			{
				float hn = hue - 4.0f * M_PI / 3.0f;
				g = (1.0f - saturation) / 3.0f;
				b = (1.0f + saturation * cos(hn) / cos(M_PI / 3.0f - hn)) / 3.0f;
				r = 1.0f - b - g;
			}
			else
			{
				throw std::invalid_argument("Hue out of range!");
			}

			return new ColorRGB(3 * intensity * r, 3 * intensity * g, 3 * intensity * b);
		}

		ColorHSI* Color::rgbToHSI(const ColorRGB& rgb)
		{
			return new ColorHSI(rgb);
		}
	}
}
