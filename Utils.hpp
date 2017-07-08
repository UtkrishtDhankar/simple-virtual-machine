#pragma once

#include <cstdint>

namespace vm {
	// I don't like to type uint16_t all the time
	typedef uint16_t Word;

	constexpr unsigned wordLen = 16;

	Word GetBits(Word w, unsigned start, unsigned num);
}
