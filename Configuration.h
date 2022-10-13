#ifndef ConfigurationH
#define ConfigurationH

#include <map>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>

class Configuration
{
public:
	typedef std::map<std::string, std::string> ConfigDictionary;

    template<typename T>
	explicit Configuration(const T& fileName)
    {
        _config = std::make_unique<ConfigDictionary>();

        std::stringstream stream;
        stream << fileName;
        std::ifstream fileStream(stream.str());
        std::string line;

        if (fileStream.is_open()) while (getline(fileStream, line, ','))
            {
                std::size_t position = line.find(':');
                if (position == std::string::npos) continue;
                std::string first = line.substr(0, position);
                std::string second = line.substr(position + 1, line.size() - position - 1);
                _config->insert(std::pair<std::string, std::string>(first, second));
            };
        fileStream.close();
    }

	~Configuration();

	std::string* Value(const std::string& key);
	std::string* Value(const char key[]);

private:
	std::unique_ptr<ConfigDictionary> _config;
};

#endif