#ifndef LoggerH
#define LoggerH

#include <chrono>
#include <memory>
#include "ISender.h"
#include "LogLevel.h"

class Logger
{
public:
	Logger(const std::shared_ptr<ISender>& sender, LogLevel logLevel);
	~Logger();
	
	template<typename T> 
	void Trace(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Trace)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "TRACE " << CreateTimeString().c_str() << " " << message << "\n";
	}

	template<typename T> 
	void Debug(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Debug)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "DEBUG " << CreateTimeString().c_str() << " " << message << "\n";
	}
	
	template<typename T> 
	void Info(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Info)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "INFO " << CreateTimeString().c_str() << " " << message << "\n";
	}

	template<typename T> 
	void Warning(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Warning)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "WARNING " << CreateTimeString().c_str() << " " << message << "\n";
	}

	template<typename T> 
	void Error(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Error)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "ERROR " << CreateTimeString().c_str() << " " << message << "\n";
	}
	
	template<typename T> 
	void Critical(const T& message)
	{
        if (!ValidateLogLevel(LogLevel::Critical)) return;
        std::stringstream stream;
        stream << message;
        std::string stringMessage = stream.str();
        *_sender << "CRITICAL " << CreateTimeString().c_str() << " " << message << "\n";
	}

private:
    std::shared_ptr<ISender> _sender;
    LogLevel _logLevel;

    std::string CreateTimeString();
    bool ValidateLogLevel(LogLevel logLevel);
};

#endif