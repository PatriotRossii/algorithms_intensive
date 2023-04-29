#include <string_view>
#include <filesystem>
#include <iostream>

int main() {
	std::string path; std::cin >> path;
	std::string canonicalPath = std::filesystem::weakly_canonical(std::filesystem::path{path});
	auto length = canonicalPath.size();

	if (canonicalPath.ends_with('/') && length > 1) {
		std::cout << std::string_view{canonicalPath.c_str(), length - 1} << '\n';
	} else {
		std::cout << canonicalPath << '\n';
	}
}
