#include "Store.hpp"

#include "Computer.hpp"

namespace vm
{

Store::~Store()
{
	
}

void Store::Execute()
{
	computer.SetMemoryAtIndex(memoryLocation, computer.GetAccumulator());
}

bool Store::WouldBeValid(Word instructionBits)
{
	bool valid = false;

	Word firstBits = GetBits(instructionBits, 0u, 2u);
	if (firstBits == 2u) {
		valid = true;	
	}

	return valid;
}

Store::Store(Computer& c, Word instructionBits)
	: computer(c)
{
	this->memoryLocation = GetBits(instructionBits, 2u, 14u);

	if (!WouldBeValid(instructionBits)) {
		// TODO throw exception
	}
}

}
