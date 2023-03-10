#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <regex>
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif
#include "utils.h"

bool ends_with(const std::string& value, const std::string& ends)
{
    if (ends.size() > value.size()) return false;
    return std::equal(ends.rbegin(), ends.rend(), value.rbegin());
}

#ifdef _WIN32
std::size_t count_files(const std::string &folder)
{
    size_t counter = 0;
    WIN32_FIND_DATAA ffd;

    // Start iterating over the files in the folder directory.
    HANDLE hFind = ::FindFirstFileA((folder + "\\*").c_str(), &ffd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (ffd.cFileName[0] != '.')
                counter++;
            
        } while (::FindNextFileA(hFind, &ffd) != 0);
        ::FindClose(hFind);
    }
    else
    {
        throw std::runtime_error("Failed open folder " + folder);
    }

    return counter;
    
}
#else
std::size_t count_files(const std::string &folder)
{
    size_t counter = 0;
    DIR *dp = opendir(folder.c_str());
    if (dp == nullptr)
    {
        throw std::runtime_error("Failed open folder " + folder);
    }

    struct dirent *ep = nullptr;
    while ((ep = readdir(dp)) != nullptr)
    {
        if (ep->d_name[0] != '.')
            counter++;
    }
    (void)closedir(dp);
    return counter;
    
    
}

#endif

std::size_t count_lines(const std::string& filename)
{
    std::ifstream ifs(filename);
    if (!ifs)
    {
        throw std::runtime_error("Failed open file ");
    }

    std::string line;
    size_t counter = 0;
    while (std::getline(ifs, line))
        counter++;
    return counter;
}

std::string file_contents(const std::string& filename)
{
    std::ifstream ifs(filename, std::ios_base::binary);
    if (!ifs)
    {
        throw std::runtime_error("Failed open file ");
    }
    return std::string{(std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())};
}

std::string get_seq(const std::string& fasta_filename, const std::string& chr_name)
{
    std::ifstream ifs(fasta_filename);
    if (!ifs)
    {
        throw std::runtime_error("Failed open file ");
    }

    std::string line;
    std::vector<std::string> lines;
    
    while (std::getline(ifs, line) && line != (">" + chr_name))
    {
        
    }
    if (!ifs)
    {
        throw std::runtime_error("Fasta has no this chr");
    }
    while (std::getline(ifs, line) && line.substr(0, 1) != ">")
    {
        lines.push_back(line);
    }
    if (lines.size() == 0)
    {
        throw std::runtime_error("Fasta file error");
    }
    std::string cat_line;
    for (const auto &s : lines) cat_line += s;

    
    return cat_line;
}
// example: 1,2 to [1,2]
// TODO: 1,2;4-9
std::vector<int> str_split_to_int(const std::string &str)
{
    std::regex re{"[,]"};
    std::vector<std::string> v(std::sregex_token_iterator(str.begin(), str.end(), re, -1), std::sregex_token_iterator());
    std::vector<int> v_int;
    for (const auto& s: v)
    {
        v_int.push_back(std::stoi(s));
    }
    return v_int;
}

hash_t hash_(char const *str)
{
    hash_t ret{basis};

    while (*str)
    {
        ret ^= *str;
        ret *= prime;
        str++;
    }
    
    return ret;
}

bool is_big_endian()
{
	int v=0x0D0C0B0A;
	char c = *(char*)&v;

	if (c == 0x0A)	return false;
	return true;
}