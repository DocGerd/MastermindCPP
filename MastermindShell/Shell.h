#pragma once

#include "../MastermindCPPDLL/Mastermind.h"

namespace mastermind
{
	namespace shell
	{
		/**
		 * \brief The shell.
		 */
		class Shell
		{
		private:
			/**
			* \brief The help text for console output.
			*/
			static const std::wstring HELP_TEXT;
		public:
			/**
			 * \brief Main method.
			 * \return --
			 */
			static int main();
		};
	}
}
