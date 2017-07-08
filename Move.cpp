#include "Move.hpp"

#include "Computer.hpp"

namespace vm
{

Move::~Move()
{
	if (mode == Mode::ToRegister) {
		computer.SetRegister(registerId, computer.GetAccumulator());
	} else {
		computer.SetAccumulator(computer.GetRegisters()[registerId]);
	}
}

void Move::Execute()
{
	
}

bool Move::WouldBeValid(Word instructionBits)
{
	bool valid = false;

	Word firstBits = GetBits(instructionBits, 0u, 9u);
	if (firstBits == 0b000000001) {
		valid = true;	
	}

	return valid;
}

Move::Move(Computer& c, Word instructionBits) :
	computer(c)
{
	Word modeBit = GetBits(instructionBits, 9u, 1u);

	if (modeBit == 1u) {
		mode = Mode::ToAccumulator;
	} else {
		mode = Mode::ToRegister;
	}

	registerId = GetBits(instructionBits, 10u, 6u);

	if (!WouldBeValid(instructionBits)) {
		// TODO throw exception
	}
}

}
