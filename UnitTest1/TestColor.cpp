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
		TEST_METHOD(TestRGBtoHSI1)
		{
			const ColorRGB rgb(50, 50, 10);

			const double expectedHue = 60.0;
			const double expectedSat = 0.7273;
			const double expectedInt = 37.0 / 255.0;

			const ColorHSI* hsi = Color::rgbToHSI(rgb);
			const double hue = hsi->getHue();
			const double sat = hsi->getSaturation();
			const double intens = hsi->getIntensity();

			Assert::AreEqual(expectedHue, hue, 0.005, L"", LINE_INFO());
			Assert::AreEqual(expectedSat, sat, 0.005, L"", LINE_INFO());
			Assert::AreEqual(expectedInt, intens, 0.005, L"", LINE_INFO());
		}

		TEST_METHOD(TestHSItoRGBCase1)
		{
			const ColorHSI hsi(60.0, 0.7273, 37.0 / 255.0);
			const uint8_t expectedRed = 50;
			const uint8_t expectedGreen = 50;
			const uint8_t expectedBlue = 10;

			const ColorRGB* rgb = Color::hsiToRGB(hsi);
			const uint8_t red = rgb->getRed();
			const uint8_t green = rgb->getGreen();
			const uint8_t blue = rgb->getBlue();

			Assert::AreEqual(expectedRed, red, L"", LINE_INFO());
			Assert::AreEqual(expectedGreen, green, L"", LINE_INFO());
			Assert::AreEqual(expectedBlue, blue, L"", LINE_INFO());
		}

		TEST_METHOD(TestHSItoRGBCase2)
		{
			const ColorHSI hsi(180.0, 0.8916, 138.0 / 255.0);
			const uint8_t expectedRed = 15;
			const uint8_t expectedGreen = 200;
			const uint8_t expectedBlue = 200;

			const ColorRGB* rgb = Color::hsiToRGB(hsi);
			const uint8_t red = rgb->getRed();
			const uint8_t green = rgb->getGreen();
			const uint8_t blue = rgb->getBlue();

			Assert::AreEqual(expectedRed, red, L"", LINE_INFO());
			Assert::AreEqual(expectedGreen, green, L"", LINE_INFO());
			Assert::AreEqual(expectedBlue, blue, L"", LINE_INFO());
		}

		TEST_METHOD(TestHSItoRGBCase3)
		{
			const ColorHSI hsi(300.0, 0.9268, 137.0 / 255.0);
			const uint8_t expectedRed = 200;
			const uint8_t expectedGreen = 10;
			const uint8_t expectedBlue = 200;

			const ColorRGB* rgb = Color::hsiToRGB(hsi);
			const uint8_t red = rgb->getRed();
			const uint8_t green = rgb->getGreen();
			const uint8_t blue = rgb->getBlue();

			Assert::AreEqual(expectedRed, red, L"", LINE_INFO());
			Assert::AreEqual(expectedGreen, green, L"", LINE_INFO());
			Assert::AreEqual(expectedBlue, blue, L"", LINE_INFO());
		}
	};
}
