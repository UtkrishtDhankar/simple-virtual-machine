#include "Computer.hpp"

namespace vm {

Computer::Computer()
	: memory(memorySize, 0), registers(numRegisters, 0),
	  accumulator(0), instructionPointer(0), statusRegister(0)
{

}

Computer::~Computer()
{
	// Everything cleans up after itself
}

void Computer::SetMemory(const std::vector<Word>& newMemory)
{
	auto memIt = memory.begin();
	auto newMemIt = newMemory.begin();

	// Copy while we can
	while (memIt < memory.end() && newMemIt < newMemory.end()) {
		*memIt++ = *newMemIt++;	
	}

	// Zero out until we run out of memory
	while (memIt < memory.end()) {
		*memIt++ = 0;
	}
}

void Computer::Tick()
{
	// Get the next instruction from memory
	Word instructionBits = memory[instructionPointer];
	std::unique_ptr<Instruction> instruction
		= Instruction::MakeInstruction(*this, instructionBits);

	instruction->Execute();

	instructionPointer++;
}

Word Computer::PeakAccumulator() const
{
	return accumulator;
}

Word Computer::PeakInstructionPointer() const
{
	return instructionPointer;
}

Word Computer::PeakStatus() const
{
	return statusRegister;
}

const std::vector<Word>& Computer::PeakRegisters() const
{
	return registers;
}

const std::vector<Word>& Computer::PeakMemory() const
{
	return memory;
}

void Computer::SetAccumulator(Word acc) 
{
	accumulator = acc;
}

void Computer::SetInstructionPointer(Word ip) 
{
	instructionPointer = ip;
}

void Computer::SetMemoryAtIndex(Word index, Word val)
{
	memory[index] = val;
}

void Computer::SetRegister(Word id, Word val)
{
	registers[id] = val;
}

Word Computer::getNextInstruction() const
{
	return memory[instructionPointer + 1];
}

} // end namespace
