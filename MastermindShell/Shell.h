#pragma once

#include "../MastermindCPPDLL/Mastermind.h"
#include "../MastermindCPPDLL/RequestedState.h"

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

			const logic::Mastermind* game;

		public:
			Shell();
			/**
			 * \brief Main method.
			 * \return 0
			 */
			int main() const;

		protected:
			void runMain(const State& state) const;
			/**
			 * \brief Print help to console.
			 */
			static void printHelp();
		};
	}
}
