#pragma once

#include "API.h"
#include "Color.h"

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
			const double hue;
			/**
			* \brief Saturation value.
			*/
			const double saturation;
			/**
			* \brief Intensity value.
			*/
			const double intensity;

		public:
			/**
			* \brief Create a HSI color.
			* \param h hue value, must be [0.0..360.0)
			* \param s saturation value, must be [0.0..1.0]
			* \param i intensity value, must be [0.0..1.0]
			* 
			* \exception std::invalid_argument
			*/
			ColorHSI(double h, double s, double i);
			ColorHSI(const ColorRGB& colorRGB);

			/**
			* \brief Get hue value.
			* \return the hue value
			*/
			double getHue() const;
			/**
			* \brief Get saturation value.
			* \return the saturation value
			*/
			double getSaturation() const;
			/**
			* \brief Get intensity value.
			* \return the intensity value
			*/
			double getIntensity() const;
			/**
			* \brief Get RGB values as array.
			* \return array with HSI values
			*/
			double* getHSI() const;

			/**
			 * \copydoc mastermind::logic::Color::toString()
			 */
			std::wstring toString() const override;
			bool operator==(const ColorHSI& rhs) const;
			bool operator!=(const ColorHSI& rhs) const;

			static double hueFromRGB(const ColorRGB& rgb);
			static double saturationFromRGB(const ColorRGB& rgb);
			static double intensityFromRGB(const ColorRGB& rgb);
		};
	}
}
