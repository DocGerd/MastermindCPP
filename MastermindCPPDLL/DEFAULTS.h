#pragma once

#define MAX_MOVES 7
#define SLOT_COUNT 4
#define COLOR_COUNT 6


int codecount() {
	int result = COLOR_COUNT;
	for (auto i = 1; i < SLOT_COUNT; ++i) {
		result *= COLOR_COUNT;
	}
	return result;
}


#define CODE_COUNT codecount()