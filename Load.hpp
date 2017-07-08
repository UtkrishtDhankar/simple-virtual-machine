#pragma once

#include "Instruction.hpp"

namespace vm
{

class Load : public Instruction
{
public:
								Load(Computer& computer, Word instructionBits);
	virtual						~Load() override;

	virtual void				Execute() override;

	static bool 				WouldBeValid(Word instructionBits);

private:
	Computer&					computer;
	Word						memoryLocation;
};

}
