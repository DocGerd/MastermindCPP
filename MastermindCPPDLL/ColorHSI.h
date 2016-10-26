#pragma once

#include "API.h"
#include "Color.h"
#include "ColorRGB.h"

namespace mastermind
{
	namespace logic
	{
		/**
		* \brief A RGB color representation.
		* RGB values must be each [0..255].
		*/
		class MASTERMINDCPPDLL_API ColorHSI : public Color
		{
		private:
			friend class ColorRGB;
			/**
			* \brief Hue value.
			*/
			const float hue;
			/**
			* \brief Saturation value.
			*/
			const float saturation;
			/**
			* \brief Intensity value.
			*/
			const float intensity;

		public:
			/**
			* \brief Create a HSI color.
			* \param h hue value, must be [0.0..360.0)
			* \param s saturation value, must be [0.0..1.0]
			* \param i intensity value, must be [0.0..1.0]
			*/
			ColorHSI(float h, float s, float i);
			ColorHSI(const ColorRGB& colorRGB);

			/**
			* \brief Get hue value.
			* \return the hue value
			*/
			float getHue() const;
			/**
			* \brief Get saturation value.
			* \return the saturation value
			*/
			float getSaturation() const;
			/**
			* \brief Get intensity value.
			* \return the intensity value
			*/
			float getIntensity() const;
			/**
			* \brief Get RGB values as array.
			* \return array with HSI values
			*/
			float* getHSI() const;

			std::wstring toString() const override;
			bool operator==(const ColorHSI &rhs) const;
			bool operator!=(const ColorHSI &rhs) const;

			static float hueFromRGB(const ColorRGB& rgb);
			static float saturationFromRGB(const ColorRGB& rgb);
			static float intensityFromRGB(const ColorRGB& rgb);
		};
	}
}
