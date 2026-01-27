# include "utils.hpp"

std::string truncate(const std::string& str, size_t max)
{
	if (str.length() <= max)
		return str;
	std::string truncated = str.substr(0, max - 1);
	truncated += '.';
	return truncated;
}
