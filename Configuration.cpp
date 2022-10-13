#include "Configuration.h"

Configuration::~Configuration() = default;

std::string* Configuration::Value(const std::string& key)
{
	if (_config->find(key) == _config->end()) return nullptr;
	return &(*_config)[key];
}

std::string* Configuration::Value(const char key[])
{
	if (_config->find(key) == _config->end()) return nullptr;
	return &(*_config)[key];
}