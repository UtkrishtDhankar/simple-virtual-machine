#include "Instruction.hpp"

#include "Load.hpp"
#include "Store.hpp"

#include <stdexcept>

namespace vm 
{

Instruction::~Instruction()
{

}

std::unique_ptr<Instruction> Instruction::MakeInstruction(Computer& computer, Word instructionBits)
{
	if (Load::WouldBeValid(instructionBits)) {
		return std::make_unique<Load> (computer, instructionBits);
	} else if (Store::WouldBeValid(instructionBits)) {
		return std::make_unique<Store> (computer, instructionBits);
	} 

	throw std::domain_error("The given instruction bits don't match any instruction pattern.");
}

}
