#pragma once

#include "Utils.hpp"

#include <memory>

namespace vm {

// The base class for all instructions in the virtual machine
// Make sure to __not__ have any public constructors on derived classes
// And only make them via the static method here
class Instruction
{
public:
	virtual									~Instruction() = 0;

	// This gives you a proper instruction that it deduces from the provided
	// bits. This isn't guaranteed to work, and could throw a
	// domain_error exception
	// computer isn't const as the instruction that this makes,
	// when executed, could potentially alter the computer
	static std::unique_ptr<Instruction>		MakeInstruction(
			class Computer& computer, 
			Word instructionBits);

	// Executes this instruction in the Computer.
	virtual void							Execute() = 0;
};

}
