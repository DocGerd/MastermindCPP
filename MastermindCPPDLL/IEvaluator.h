#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

namespace mastermind
{
	namespace logic
	{
		/**
		 * \brief Interface for an Evaluator of a ColorCode.
		 * This interface class should be abstract however Doxygen has parsing problems then.
		 */
		class MASTERMINDCPPDLL_API IEvaluator //abstract
		{
		public:
			virtual ~IEvaluator()
			{
			}

			/**
			 * \brief Evaluate the given ColorCode to the respective BlackAndWhite.
			 * \param cc the ColorCode to be evaluated, must not be <tt>null</tt>
			 * \return the resulting BlackAndWhite
			*/
			virtual BlackAndWhite* evaluate(const ColorCode* cc) abstract;

			/**
			 * \brief Get the solution.
			 * \return the solution ColorCode or NULL if not available yet.
			*/
			virtual ColorCode* getSolution() abstract;
		};
	}
}
