#include "stdafx.h"

#include "ColorHSI.h"


namespace mastermind
{
	namespace logic
	{
		ColorHSI::ColorHSI(float h, float s, float i) :
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

		float ColorHSI::getHue() const
		{
			return this->hue;
		}

		float ColorHSI::getSaturation() const
		{
			return this->saturation;
		}

		float ColorHSI::getIntensity() const
		{
			return this->intensity;
		}

		float* ColorHSI::getHSI() const
		{
			float* result = new float[3]{ hue, saturation, intensity };
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

		float ColorHSI::intensityFromRGB(const ColorRGB& rgb)
		{
			float result = static_cast<float>(rgb.getRed() + rgb.getGreen() + rgb.getBlue());
			result = result / 3.0f;
			return result;
		}

		float ColorHSI::saturationFromRGB(const ColorRGB& rgb)
		{
			float frac = 3.0f / (rgb.getRed() + rgb.getGreen() + rgb.getBlue());
			float minrgb = min(min(rgb.getRed(), rgb.getGreen()), rgb.getBlue());
			return 1.0f - frac * minrgb;
		}

		float ColorHSI::hueFromRGB(const ColorRGB& rgb)
		{
			float red = rgb.getRed() / 255.0f;
			float green = rgb.getGreen() / 255.0f;
			float blue = rgb.getBlue() / 255.0f;
			float num = 0.5f * ((red - green) + (red - blue));
			float denum = (red - green)*(red - green) + (red - blue) *(green - blue);
			float result = sqrt(num / denum);
			result = acos(result);
			return result;
		}
	}
}