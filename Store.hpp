#pragma once

#include "Instruction.hpp"

namespace vm
{

class Store : public Instruction
{
public:
								Store(Computer& computer, Word instructionBits);
	virtual						~Store() override;

	virtual void				Execute() override;

	static bool 				WouldBeValid(Word instructionBits);

private:
	Computer&					computer;
	Word						memoryLocation;
};

}
