#ifndef FileSenderH
#define FileSenderH

#include <memory>
#include <chrono>
#include <fstream>
#include "ISender.h"

class FileSender : public ISender
{
public:
	FileSender(std::string &fileName);
	FileSender(const char fileName[]);
	virtual ~FileSender(void);

protected:
	virtual void VM_Send(std::string &message);

private:
	std::string _fileName;
};



#endif