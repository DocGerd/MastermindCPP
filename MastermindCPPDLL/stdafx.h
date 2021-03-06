// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// reference additional headers your program requires here
#define _USE_MATH_DEFINES
#include <cmath>

#include <stdexcept>

#include <string>
#include <list>
#include <iterator>

#include <array>

#include <cassert>

#include <iostream>


#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)
#define RAD_TO_DEG(rad) ((rad) * 180.0 / M_PI)
