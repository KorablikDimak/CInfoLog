#ifndef FileSenderH
#define FileSenderH

#include <memory>
#include <chrono>
#include <fstream>
#include "ISender.h"

class FileSender : public ISender
{
public:
    template<typename T>
	explicit FileSender(const T& fileName)
    {
        std::stringstream stream;
        stream << fileName;
        _fileName = stream.str();
    }

	~FileSender() override;

protected:
	void Send(const std::string& message) override;

private:
	std::string _fileName;
};



#endif