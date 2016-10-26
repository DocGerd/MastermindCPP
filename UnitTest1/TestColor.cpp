#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MastermindCPPDLL/Color.h"
#include "../MastermindCPPDLL/ColorHSI.h"
#include "../MastermindCPPDLL/ColorRGB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mastermind::logic;

namespace UnitTest1
{
	TEST_CLASS(TestColor)
	{
	public:
		TEST_METHOD(TestRGBtoHSI)
		{
			ColorRGB rgb(12, 44, 240);

			float expectedHue = 233.0f;
			float expectedSat = 0.8784f;
			float expectedInt = 99.0f / 255.0f;

			ColorHSI* hsi = Color::rgbToHSI(rgb);
			float hue = hsi->getHue();
			float sat = hsi->getSaturation();
			float intens = hsi->getIntensity();

			Assert::AreEqual(expectedHue, hue, 0.001f, L"", LINE_INFO());
			Assert::AreEqual(expectedSat, sat, 0.001f, L"", LINE_INFO());
			Assert::AreEqual(expectedInt, intens, 0.001f, L"", LINE_INFO());
		}

		TEST_METHOD(TestHSItoRGB)
		{
			ColorHSI hsi(233.0f, 0.8784f, 99.0f / 255.0f);
			uint8_t expectedRed = 12;
			uint8_t expectedGreen = 44;
			uint8_t expectedBlue = 240;

			ColorRGB* rgb = Color::hsiToRGB(hsi);
			uint8_t red = rgb->getRed();
			uint8_t green = rgb->getGreen();
			uint8_t blue = rgb->getBlue();

			Assert::AreEqual(expectedRed, red, L"", LINE_INFO());
			Assert::AreEqual(expectedGreen, green, L"", LINE_INFO());
			Assert::AreEqual(expectedBlue, blue, L"", LINE_INFO());
		}
	};
}
