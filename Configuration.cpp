#include "Configuration.h"

Configuration::Configuration(std::string &configFileName)
{
	_config = std::unique_ptr<ConfigDictionary>(new ConfigDictionary);

	std::ifstream fileStream(configFileName);
	std::string line;
	if (fileStream.is_open()) while (getline(fileStream, line, ','))
	{
		unsigned char position = line.find(':');
		if (position == std::string::npos) continue;

		std::string first = line.substr(0, position);
		std::string second = line.substr(position + 1, line.size() - position - 1);
		_config->insert(std::pair<std::string, std::string>(first, second));
	};
	fileStream.close();
}
Configuration::~Configuration(void) {}

std::string *Configuration::Value(std::string &key)
{
	if (_config->find(key) == _config->end()) return nullptr;
	return &(*_config)[key];
}

std::string *Configuration::Value(const char key[])
{
	if (_config->find(key) == _config->end()) return nullptr;
	return &(*_config)[key];
}