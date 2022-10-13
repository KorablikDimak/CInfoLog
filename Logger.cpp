#include "Logger.h"

Logger::Logger(const std::shared_ptr<ISender>& sender, LogLevel logLevel)
{
	_sender = sender;
	_logLevel = logLevel;
}

Logger::~Logger() = default;

std::string Logger::CreateTimeString()
{
	auto currentTime = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(currentTime);
	std::unique_ptr<tm> timeStructure(new tm());
	localtime_s(timeStructure.get(), &time);

	auto hours = std::chrono::time_point_cast<std::chrono::hours>(currentTime);
	auto minutes = std::chrono::time_point_cast<std::chrono::minutes>(currentTime);
	auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(currentTime);
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - seconds);

	return std::to_string(timeStructure->tm_hour) + ":" + std::to_string(timeStructure->tm_min)
    + ":" + std::to_string(timeStructure->tm_sec) + ":" + std::to_string(milliseconds.count());
}

bool Logger::ValidateLogLevel(LogLevel logLevel)
{
	return logLevel >= _logLevel;
}