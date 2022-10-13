#include "ISender.h"

ISender::ISender() : std::ostream(this) {}

ISender::~ISender() = default;

void ISender::Send(const std::string& message)
{
	throw std::domain_error("No definition of virtual method Send in class ISender");
}