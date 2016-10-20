#pragma once

#ifdef MASTERMINDCPPDLL_EXPORTS
#define MASTERMINDCPPDLL_API __declspec(dllexport)
#else
#define MASTERMINDCPPDLL_API __declspec(dllimport)
#endif