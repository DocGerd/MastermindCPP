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
			// hue must be changed from DEG to RAD
			const double hue = DEG_TO_RAD(hsi.getHue());
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
			else if (0.0 <= hue && hue < DEG_TO_RAD(120.0))
			{
				b = (1.0 - saturation) / 3.0;
				r = (1.0 + (saturation * cos(hue)) / (cos(DEG_TO_RAD(60.0) - hue))) / 3.0;
				g = 1.0 - (b + r);
			}
			else if (DEG_TO_RAD(120.0) < hue && hue <= DEG_TO_RAD(240.0))
			{
				double hn = hue - DEG_TO_RAD(120.0);
				r = (1.0 - saturation) / 3.0;
				g = (1.0 + saturation * cos(hn) / cos(DEG_TO_RAD(60.0) - hn)) / 3.0;
				b = 1.0 - (r + g);
			}
			else if (DEG_TO_RAD(240.0) < hue && hue <= DEG_TO_RAD(360.0))
			{
				double hn = hue - DEG_TO_RAD(240.0);
				g = (1.0 - saturation) / 3.0;
				b = (1.0 + saturation * cos(hn) / cos(DEG_TO_RAD(60) - hn)) / 3.0;
				r = 1.0 - (g + b);
			}
			else
			{
				throw std::invalid_argument("Hue out of range!");
			}
			const double R = 3.0 * intensity * r * 255.0;
			const double G = 3.0 * intensity * g * 255.0;
			const double B = 3.0 * intensity * b * 255.0;
			return new ColorRGB(
				static_cast<uint8_t>(round(R)),
				static_cast<uint8_t>(round(G)),
				static_cast<uint8_t>(round(B)));
		}

		ColorHSI* Color::rgbToHSI(const ColorRGB& rgb)
		{
			return new ColorHSI(rgb);
		}
	}
}
