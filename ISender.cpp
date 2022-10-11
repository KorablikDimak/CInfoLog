#include "ISender.h"

ISender::ISender(void) : std::ostream(this) {}
ISender::~ISender(void) {}

void ISender::VM_Send(std::string &message)
{
	throw std::domain_error("No defenition of virtual method VM_Send in class ISender");
}