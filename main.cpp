#include "Computer.hpp"

#include <iostream>
#include <vector>

using namespace vm;

void PrintRegisters(const Computer& computer)
{
	for (auto reg : computer.GetRegisters()) {
		std::cout << "gpr: " << reg << ", ";
	}

	std::cout << "\nacc: " << computer.GetAccumulator();
	std::cout << "\nip : " << computer.GetInstructionPointer() << std::endl;
}

int main()
{
	Computer c;

	PrintRegisters(c);
	
	// Store location 0 in the accumulator
	std::vector<Word> mem = {0b1100000000000000};
	c.SetMemory(mem);
	c.Tick();

	PrintRegisters(c);
	
	return 0;
}
