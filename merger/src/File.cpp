#include "File.h"
#include <iostream>
#include <iterator>
#include <optional>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

File::File(std::string filePath) : filePath(filePath) {
	content = "";
	std::ifstream file(filePath);
	if (!file.is_open()) {
		throw new std::runtime_error("Can't open file " + filePath);
	}
	std::string line;
	while(std::getline(file, line)) {
		content += line + '\n';
		lines.push_back(line);
	}
	file.close();
}

std::string File::getContent() {
	return content;
}

std::string File::getName() const {
	auto lastSlashIndex = filePath.rfind('/');
	if (lastSlashIndex == std::string::npos) {
		return filePath;
	}
	return filePath.substr(lastSlashIndex + 1);
}

const std::vector<std::string>& File::getLines() const {
	return lines;
}

std::string File::getDirectoryPath() const {
	auto lastSlashIndex = filePath.rfind('/');
	if (lastSlashIndex == std::string::npos) {
		return ".";
	}
	return filePath.substr(0, lastSlashIndex);
}
