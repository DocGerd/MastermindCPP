#pragma once

#include "API.h"
#include "Color.h"
#include "ColorHSI.h"

namespace mastermind
{
	namespace logic
	{
		/**
		* \brief A RGB color representation.
		* RGB values must be each [0..255].
		*/
		class MASTERMINDCPPDLL_API ColorRGB : public Color
		{
		private:
			friend class ColorHSI;
			/**
			* \brief Red value.
			*/
			const uint8_t red;
			/**
			* \brief Green value.
			*/
			const uint8_t green;
			/**
			* \brief Blue value.
			*/
			const uint8_t blue;

		public:
			/**
			* \brief Create a RGB color.
			* \param name name for this color
			* \param r red value, must be [0..255]
			* \param g green value, must be [0..255]
			* \param b blue value, must be [0..255]
			*/
			ColorRGB(std::wstring name, uint8_t r, uint8_t g, uint8_t b);
			/**
			* \brief Create a RGB color.
			* \param r red value, must be [0..255]
			* \param g green value, must be [0..255]
			* \param b blue value, must be [0..255]
			*/
			ColorRGB(uint8_t r, uint8_t g, uint8_t b);

			/**
			* \brief Get red value.
			* \return the red value
			*/
			uint8_t getRed() const;
			/**
			* \brief Get green value.
			* \return the blue value
			*/
			uint8_t getGreen() const;
			/**
			* \brief Get blue value.
			* \return the blue value
			*/
			uint8_t getBlue() const;
			/**
			* \brief Get RGB values as array.
			* \return array with RGB values
			*/
			uint8_t* getRGB() const;

			std::wstring toString() const override;
			bool operator==(const ColorRGB &rhs) const;
			bool operator!=(const ColorRGB &rhs) const;
		};
	}
}
