#pragma once

#include "API.h"
#include "Mastermind.h"

namespace mastermind
{
	namespace shell
	{
		/**
		 * \brief The shell.
		 */
		class MASTERMINDCPPDLL_API Shell : public Mastermind
		{
		private:
#pragma warning(disable: 4251)
			/**
			* \brief The help text for console output.
			*/
			static const std::wstring HELP_TEXT;
#pragma warning(default: 4251)
		public:
			/**
			 * \brief Main method.
			 * \return --
			 */
			static int main();
		};
	}
}
