#pragma once
#include <string>
#include <vector>
#include <chrono>

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;


bool ends_with(const std::string& value, const std::string& ends);

std::size_t count_files(const std::string& folder);

std::size_t count_lines(const std::string& filename);

std::string file_contents(const std::string& filename);

std::string get_seq(const std::string& fasta_filename, const std::string& chr_name);

std::vector<int> str_split_to_int(const std::string& str);

hash_t hash_(char const* str);

bool is_big_endian();

constexpr hash_t hash_compile_time(char const *str, hash_t last_value = basis)
{
    return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

// similar usage in std
// constexpr std::chrono::seconds operator ""s(unsigned long long s)
// {
//     return std::chrono::seconds(s);
// }
constexpr std::uint64_t operator ""_hash(char const *p, size_t)
{
    return hash_compile_time(p);
}


