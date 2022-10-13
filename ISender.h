#ifndef ISenderH
#define ISenderH

#include <sstream>

class ISender : private std::streambuf, public std::ostream
{
public:
	ISender();
	~ISender() override;
	
	template<typename T> 
	ISender& operator << (const T& message)
	{
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        Send(stringMessage);
		return *this; 
	}

protected:
	virtual void Send(const std::string& message);
};

#endif