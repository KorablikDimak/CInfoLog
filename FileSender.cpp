#include "FileSender.h"

FileSender::~FileSender() = default;

void FileSender::Send(const std::string& message)
{
	auto currentTime = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(currentTime);
	std::unique_ptr<tm> timeStructure(new tm());
	localtime_s(timeStructure.get(), &time);

	std::ofstream fileStream(_fileName + std::to_string(timeStructure->tm_mday)
    + "_" + std::to_string(timeStructure->tm_mon + 1)
    + "_" + std::to_string(timeStructure->tm_year - 100) + ".txt", std::ios::app);

	if (fileStream.is_open()) fileStream << message;
	fileStream.close();
}