#pragma once
#include <cstddef>
#include <exception>
#include <fstream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

class File {

	public:

	File(std::string filePath);

	std::string getName() const;
	std::string getContent();
	const std::vector<std::string>& getLines() const;
	std::string getDirectoryPath() const;

	private:

	bool contentAlreadyRead = false;
	std::string filePath;
	std::string content;
	std::vector<std::string> lines;
};
