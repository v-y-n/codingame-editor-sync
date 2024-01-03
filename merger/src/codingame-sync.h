#include <optional>
#include <string>

std::string merge(const std::string& entryFilePath);
std::optional<std::string> extractFilePathFromInclude(const std::string& line);
