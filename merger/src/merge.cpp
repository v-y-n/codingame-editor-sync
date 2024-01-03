#include "codingame-sync.h"
#include "File.h"
#include <regex>

void copyFileTo(std::string* to, const File& file, std::map<std::string, bool>* includedFiles) {
	(*to) += "/** cg-sync -> " + file.getName() + " **/\n\n";
	for (auto& line : file.getLines()) {
		auto includeFilePath = extractFilePathFromInclude(line);
		if (includeFilePath.has_value()) {
			if ((*includedFiles).find(includeFilePath.value()) != (*includedFiles).end())
				continue;
			(*includedFiles)[includeFilePath.value()] = true;
			std::string relativeIncludedFilePath = file.getDirectoryPath();
			File includedFile(relativeIncludedFilePath + "/" + includeFilePath.value());
			copyFileTo(to, includedFile, includedFiles);
		} else {
			(*to) += line + "\n";
		}
	}
}

std::string merge(const std::string& entryFilePath) {
	std::string mergedFileContent = "";
	std::map<std::string, bool> includedFiles;

	std::string currentFilePath = entryFilePath;
	File file(currentFilePath);
	std::string currentFileContent = file.getContent();

	copyFileTo(&mergedFileContent, file, &includedFiles);

	std::ofstream newFile("merge.cpp");
	if (!newFile.is_open()) {
		newFile << mergedFileContent;
	}
	newFile.close();
	return mergedFileContent;
}

// Returns a string_view from the line provided as argument
std::optional<std::string> extractFilePathFromInclude(const std::string& line) {
	std::smatch res;
	std::regex re("#include \"(.+)\"");
	std::regex_match(line, res, re);

	if (res.size() == 2) {
		return std::make_optional(res.str(1));
	}
	return std::nullopt;
}
