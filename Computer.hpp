#pragma once

#include "Utils.hpp"
#include "Instruction.hpp"

#include <vector>
#include <memory>

namespace vm {

class Computer
{
public:
								Computer();
	virtual 					~Computer();

	// Sets the internal memory of the computer to the given memory
	// if newMemory is smaller than memory, then the rest of the bits are 0d out
	// If newMemory is larger than memory, then the extra bits are ignored
	void						SetMemory(const std::vector<Word>& newMemory);

	void						Tick();

	Word						PeakAccumulator() const;
	Word						PeakInstructionPointer() const;
	Word						PeakStatus() const;

	const std::vector<Word>&	PeakRegisters() const;
	const std::vector<Word>&	PeakMemory() const;

	void						SetAccumulator(Word acc);
	void						SetInstructionPointer(Word ip);

	void						SetMemoryAtIndex(Word index, Word val);

private:
	std::vector<Word> 			memory;
	std::vector<Word> 			registers;

	Word 						accumulator;

	Word 						instructionPointer;
	Word 						statusRegister;

	// Returns the bits after the next instruction
	// The instruction is at instructionPointer + 1
	// Does _not_ increment instructionPointer
	Word						getNextInstruction() const;

	// Performance attributes
	// These will be redone as something you can change later
	static constexpr unsigned			memorySize = 16384;
	static constexpr unsigned			numRegisters = 8;
};

}
