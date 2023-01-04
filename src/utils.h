#pragma once

#include <string>

std::size_t count_files(const std::string& folder);

std::size_t count_lines(const std::string& filename);

std::string file_contents(const std::string& filename);