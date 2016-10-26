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
			 * \brief Check equality.
			 * \param rhs the other Color
			 * \return <tt>true</tt> if the color values are equal
			 */
			//bool operator==(const Color &rhs) const;
			/**
			 * \brief Check inequality.
			 * \param rhs the other Color
			 * \return <tt>true</tt> if at least one of the color values are not equal
			 */
			//bool operator!=(const Color &rhs) const;

			std::wstring getName() const;


			static ColorRGB* hsiToRGB(const ColorHSI& hsi);
			static ColorHSI* rgbToHSI(const ColorRGB& rgb);
		};
	}
}
