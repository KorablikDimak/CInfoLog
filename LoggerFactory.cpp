#include "LoggerFactory.h"

LoggerFactory::LoggerFactory()
{
	_loggers = std::make_unique<LoggerDictionary>();
}

LoggerFactory::~LoggerFactory() = default;

uintptr_t LoggerFactory::CreateLogger(Configuration& configuration)
{
	uintptr_t ptr = 0;

	std::string* logLevelString = configuration.Value("loglevel");
	if (logLevelString == nullptr) return ptr;
	LogLevel logLevel;
	if (*logLevelString == "trace") logLevel = LogLevel::Trace;
	else if (*logLevelString == "debug") logLevel = LogLevel::Debug;
	else if (*logLevelString == "info") logLevel = LogLevel::Info;
	else if (*logLevelString == "warning") logLevel = LogLevel::Warning;
	else if (*logLevelString == "error") logLevel = LogLevel::Error;
	else if (*logLevelString == "critical") logLevel = LogLevel::Critical;
	else return ptr;

	std::string* senderType = configuration.Value("sender");
	if (senderType == nullptr) return ptr;
	std::shared_ptr<ISender> sender;
	if (*senderType == "file")
	{
		std::string* fileName = configuration.Value("filename");
		if (fileName == nullptr) return ptr;
		sender = std::shared_ptr<ISender>(new FileSender(fileName->c_str()));
	}
	else return ptr;

	std::shared_ptr<Logger> logger(new Logger(sender, logLevel));
	ptr = reinterpret_cast<uintptr_t>(logger.get());
	_loggers->insert(std::make_pair(ptr, logger));
	return ptr;
}

uintptr_t LoggerFactory::AddLogger(const std::shared_ptr<Logger>& logger)
{
	uintptr_t ptr = reinterpret_cast<uintptr_t>(logger.get());
	if (_loggers->find(ptr) == _loggers->end()) _loggers->insert(std::make_pair(ptr, logger));
	return ptr;
}

Logger* LoggerFactory::GetLogger(uintptr_t token)
{
	if (_loggers->find(token) == _loggers->end()) return nullptr;
	return _loggers->at(token).get();
}

void LoggerFactory::RemoveLogger(uintptr_t token)
{
	if (_loggers->find(token) != _loggers->end()) _loggers->erase(token);

}