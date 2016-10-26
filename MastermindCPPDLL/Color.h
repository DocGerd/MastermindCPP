#pragma once

#include "API.h"
#include <string>

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief A RGB color representation.
		 * RGB values must be each [0..255].
		 */
		class MASTERMINDCPPDLL_API Color
		{
		private:
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
			 * \param r red value, must be [0..255]
			 * \param g green value, must be [0..255]
			 * \param b blue value, must be [0..255]
			 */
			Color(uint8_t r, uint8_t g, uint8_t b);

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

			/**
			 * \brief String representation of this Color.
			 * \return string in form <tt>L"(R,G,B)"</tt>
			 */
			virtual std::wstring toString() const;

			/**
			 * \brief Check equality.
			 * \param rhs the other Color
			 * \return <tt>true</tt> if the RGB values are equal
			 */
			bool operator==(const Color &rhs) const;
			/**
			 * \brief Check inequality.
			 * \param rhs the other Color
			 * \return <tt>true</tt> if at least one of the RGB values are not equal
			 */
			bool operator!=(const Color &rhs) const;
		};
	}
}
