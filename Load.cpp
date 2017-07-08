#include "Load.hpp"

#include "Computer.hpp"

namespace vm
{

Load::~Load()
{
	
}

void Load::Execute()
{
	computer.SetAccumulator(computer.GetMemory()[memoryLocation]);
}

bool Load::WouldBeValid(Word instructionBits)
{
	bool valid = false;

	Word firstBits = GetBits(instructionBits, 0u, 2u);
	if (firstBits == 3u) {
		valid = true;	
	}

	return valid;
}

Load::Load(Computer& c, Word instructionBits) :
	computer(c)
{
	this->memoryLocation = GetBits(instructionBits, 2u, 14u);

	if (!WouldBeValid(instructionBits)) {
		// TODO throw exception
	}
}

}
