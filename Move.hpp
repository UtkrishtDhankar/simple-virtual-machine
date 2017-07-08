#pragma once

#include "Instruction.hpp"

namespace vm
{

// Either moves the contents of a register to the accumulator
// Or moves the accumulator to a register. No moving between registers allowed
class Move : public Instruction
{
public:
								Move(Computer& computer, Word instructionBits);
	virtual						~Move() override;

	virtual void				Execute() override;

	static bool 				WouldBeValid(Word instructionBits);

private:
	enum class Mode {
		ToAccumulator,
		ToRegister
	};

	// Are we moving to the accumulator or to a register?
	Mode mode;

	// The register to move to or from
	Word registerId;

	Computer&					computer;

};

}
