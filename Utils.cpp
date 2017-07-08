#include "Utils.hpp"

namespace vm
{

Word GetBits(Word w, unsigned start, unsigned num) {
	w = w << start;
	w = w >> (wordLen - num);

	return w;
}

}
