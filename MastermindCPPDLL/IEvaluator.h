#pragma once

#include "API.h"

#include "ColorCode.h"
#include "BlackAndWhite.h"

#include "API.h"

namespace mastermind {
	namespace logic {
		/// Interface for an Evaluator of a ColorCode.
		class MASTERMINDCPPDLL_API IEvaluator abstract {
		public:
			virtual ~IEvaluator()
			{
			}

			/// Evaluate the given ColorCode to the respective BlackAndWhite.
			/*!
			 * @param cc the ColorCode to be evaluated
			 * @return the resulting BlackAndWhite
			*/
			virtual BlackAndWhite* evaluate(const ColorCode &cc) abstract;
			/// Get the solution.
			/*!
			 * @return the solution ColorCode or NULL if not available yet.
			*/
			virtual ColorCode* getSolution() abstract;
		};
	}
}