#ifndef LoggerFactoryH
#define LoggerFactoryH

#include "Logger.h"
#include "FileSender.h"
#include "Configuration.h"

class LoggerFactory
{
public:
	typedef std::map<uintptr_t, std::shared_ptr<Logger>> LoggerDictionary;

	LoggerFactory();
	~LoggerFactory();

	uintptr_t CreateLogger(Configuration& configuration);
	uintptr_t AddLogger(const std::shared_ptr<Logger>& logger);
	Logger* GetLogger(uintptr_t token);
	void RemoveLogger(uintptr_t token);

private:
	std::unique_ptr<LoggerDictionary> _loggers;
};

#endif