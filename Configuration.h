#ifndef ConfigurationH
#define ConfigurationH

#include <map>
#include <memory>
#include <string>
#include <fstream>
#include <vector>

class Configuration
{
public:
	typedef std::map<std::string, std::string> ConfigDictionary;

	Configuration(std::string &configFileName);
	~Configuration(void);

	std::string *Value(std::string &key);
	std::string *Value(const char key[]);

private:
	std::unique_ptr<ConfigDictionary> _config;
};

#endif