#include "stdafx.h"

#include "ColorHSI.h"


namespace mastermind
{
	namespace logic
	{
		ColorHSI::ColorHSI(double h, double s, double i) :
			hue(h), saturation(s), intensity(i)
		{
			// TODO: check values
		}

		ColorHSI::ColorHSI(const ColorRGB& colorRGB) :
			hue(hueFromRGB(colorRGB)),
			saturation(saturationFromRGB(colorRGB)),
			intensity(intensityFromRGB(colorRGB))
		{
		}

		double ColorHSI::getHue() const
		{
			return this->hue;
		}

		double ColorHSI::getSaturation() const
		{
			return this->saturation;
		}

		double ColorHSI::getIntensity() const
		{
			return this->intensity;
		}

		double* ColorHSI::getHSI() const
		{
			double* result = new double[3]{hue, saturation, intensity};
			return result;
		}

		std::wstring ColorHSI::toString() const
		{
			std::wstring result = std::wstring(L"(")
				+ std::to_wstring(hue) + L","
				+ std::to_wstring(saturation) + L","
				+ std::to_wstring(intensity) + L")";
			return result;
		}

		bool ColorHSI::operator==(const ColorHSI& rhs) const
		{
			bool result = this->hue == rhs.hue
				&& this->saturation == rhs.saturation
				&& this->intensity == rhs.intensity;
			return result;
		}

		bool ColorHSI::operator!=(const ColorHSI& rhs) const
		{
			return !(*this == rhs);
		}

		double ColorHSI::intensityFromRGB(const ColorRGB& rgb)
		{
			double result = static_cast<double>(rgb.getRed() + rgb.getGreen() + rgb.getBlue());
			result = result / 3.0;
			return result;
		}

		double ColorHSI::saturationFromRGB(const ColorRGB& rgb)
		{
			double frac = 3.0 / (rgb.getRed() + rgb.getGreen() + rgb.getBlue());
			double minrgb = min(min(rgb.getRed(), rgb.getGreen()), rgb.getBlue());
			return 1.0 - frac * minrgb;
		}

		double ColorHSI::hueFromRGB(const ColorRGB& rgb)
		{
			double red = rgb.getRed() / 255.0;
			double green = rgb.getGreen() / 255.0;
			double blue = rgb.getBlue() / 255.0;
			double num = 0.5 * ((red - green) + (red - blue));
			double denum = (red - green) * (red - green) + (red - blue) * (green - blue);
			double result = sqrt(num / denum);
			result = acos(result);
			return result;
		}
	}
}
