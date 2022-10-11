#ifndef ISenderH
#define ISenderH

#include <sstream>

class ISender : private std::streambuf, public std::ostream
{
public:
	ISender(void);
	virtual ~ISender(void);
	
	template<typename T> 
	ISender &operator << (const T &message)
	{ 
		Send(message);
		return *this; 
	}

protected:
	virtual void VM_Send(std::string &message);

private:
	template<typename T> 
	void Send(const T &message)
	{
		try
		{
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Send(stringMessage);
		}
		catch (...) {}
	}
};

#endif