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
			const double hue = hsi.getHue() * M_PI / 180.0;
			const double saturation = hsi.getSaturation();
			const double intensity = hsi.getIntensity();

			double r;
			double g;
			double b;

			// TODO: epsilon check
			if (saturation == 0.0)
			{
				r = intensity;
				g = intensity;
				b = intensity;
			}
			else if (hue >= 0.0 && hue < 2.0 * M_PI / 3.0)
			{
				b = (1.0 - saturation) / 3.0;
				r = (1.0 + saturation * cos(hue) / cos(M_PI / 3.0 - hue)) / 3.0;
				g = 1.0 - r - b;
			}
			else if (hue >= 2.0 * M_PI / 3.0 && hue < 4.0 * M_PI / 3.0)
			{
				double hn = hue - 2.0 * M_PI / 3.0;
				r = (1.0 - saturation) / 3.0;
				g = (1.0 + saturation * cos(hn) / cos(M_PI / 3.0 - hn)) / 3.0;
				b = 1.0 - r - g;
			}
			else if (hue >= 4.0 * M_PI / 3.0 && hue < 2.0 * M_PI)
			{
				double hn = hue - 4.0 * M_PI / 3.0;
				g = (1.0 - saturation) / 3.0;
				b = (1.0 + saturation * cos(hn) / cos(M_PI / 3.0 - hn)) / 3.0;
				r = 1.0 - b - g;
			}
			else
			{
				throw std::invalid_argument("Hue out of range!");
			}
			const double R = 3.0 * intensity * r;
			const double G = 3.0 * intensity * g;
			const double B = 3.0 * intensity * b;
			return new ColorRGB(R, G, B);
		}

		ColorHSI* Color::rgbToHSI(const ColorRGB& rgb)
		{
			return new ColorHSI(rgb);
		}
	}
}
