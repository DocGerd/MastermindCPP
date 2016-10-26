#pragma once

#include "API.h"

#include <string>

namespace mastermind
{
	namespace logic
	{
		class ColorRGB;
		class ColorHSI;

		/**
		 * \brief A color representation.
		 */
		class MASTERMINDCPPDLL_API Color
		{
		private:
#pragma warning(disable: 4251)
			/**
			 * \brief Name of this color.
			 */
			const std::wstring name;
#pragma warning(default: 4251)


		public:
			Color();
			Color(std::wstring name);

			virtual ~Color()
			{
			}

			/**
			 * \brief String representation of this Color.
			 * \return string in form <tt>L"(R,G,B)"</tt> or <tt>L"(H,S,I)"</tt>
			 */
			virtual std::wstring toString() const abstract;

			/**
			 * \brief Get name of this color.
			 * \return the name or <tt>L""</tt> if no name was given
			 */
			std::wstring getName() const;

			/**
			 * Get RGB color from HSI color.
			 * \param hsi the HSI color
			 * \return the resulting RGB color
			 */
			static ColorRGB* hsiToRGB(const ColorHSI& hsi);
			/**
			 * Get HSI color from RGB color.
			 * \param rgb the RGB color.
			 * \return the resulting HSI color
			 */
			static ColorHSI* rgbToHSI(const ColorRGB& rgb);
		};
	}
}
