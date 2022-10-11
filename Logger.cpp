#include "Logger.h"

Logger::Logger(std::shared_ptr<ISender> sender, LogLevel logLevel)
{
	_sender = sender;
	_minLogLevel = logLevel;
}
Logger::~Logger(void) {}

void Logger::VM_Trace(std::string &message)
{
	*_sender << "TRACE " << CreateTimeString().c_str() << " " << message << "\n";
}
void Logger::VM_Debug(std::string &message)
{
	*_sender << "DEBUG " << CreateTimeString().c_str() << " " << message << "\n";
}
void Logger::VM_Info(std::string &message)
{
	*_sender << "INFO " << CreateTimeString().c_str() << " " << message << "\n";
}
void Logger::VM_Warning(std::string &message)
{
	*_sender << "WARNING " << CreateTimeString().c_str() << " " << message << "\n";
}
void Logger::VM_Error(std::string &message)
{
	*_sender << "ERROR " << CreateTimeString().c_str() << " " << message << "\n";
}
void Logger::VM_Critical(std::string &message)
{
	*_sender << "CRITICAL " << CreateTimeString().c_str() << " " << message << "\n";
}

std::string Logger::CreateTimeString(void)
{
	auto currentTime = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(currentTime);
	std::unique_ptr<tm> timeStructure(new tm());
	localtime_s(timeStructure.get(), &time);

	auto hours = std::chrono::time_point_cast<std::chrono::hours>(currentTime);
	auto minutes = std::chrono::time_point_cast<std::chrono::minutes>(currentTime);
	auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - seconds);

	return std::to_string(timeStructure->tm_hour) + ":" + std::to_string(timeStructure->tm_min) + ":" + std::to_string(timeStructure->tm_sec) + ":" + std::to_string(milliseconds.count());
}
bool Logger::ValidateLogLevel(LogLevel logLevel)
{
	return logLevel >= _minLogLevel;
}