#ifndef LoggerH
#define LoggerH

#include <chrono>
#include <memory>
#include "ISender.h"
#include "LogLevel.h"

class Logger
{
public:
	Logger(std::shared_ptr<ISender> sender, LogLevel logLevel);
	virtual ~Logger(void);
	
	template<typename T> 
	void Trace(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Trace)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Trace(stringMessage);
		}
		catch (...) {}
	}

	template<typename T> 
	void Debug(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Debug)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Debug(stringMessage);
		}
		catch (...) {}
	}
	
	template<typename T> 
	void Info(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Info)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Info(stringMessage);
		}
		catch (...) {}
	}

	template<typename T> 
	void Warning(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Warning)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Warning(stringMessage);
		}
		catch (...) {}
	}

	template<typename T> 
	void Error(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Error)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Error(stringMessage);
		}
		catch (...) {}
	}
	
	template<typename T> 
	void Critical(const T &message)
	{
		try
		{
			if (!ValidateLogLevel(LogLevel::Critical)) return;
			std::stringstream stream;
			stream << message;
			std::string stringMessage = stream.str();
			VM_Critical(stringMessage);
		}
		catch (...) {}
	}

protected:
	virtual void VM_Trace(std::string &message);
	virtual void VM_Debug(std::string &message);
	virtual void VM_Info(std::string &message);
	virtual void VM_Warning(std::string &message);
	virtual void VM_Error(std::string &message);
	virtual void VM_Critical(std::string &message);

	virtual std::string CreateTimeString(void);
	virtual bool ValidateLogLevel(LogLevel logLevel);

private:
	std::shared_ptr<ISender> _sender;
	LogLevel _minLogLevel;
};

#endif