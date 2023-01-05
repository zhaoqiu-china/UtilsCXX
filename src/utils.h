#pragma once

#include <string>

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

std::size_t count_files(const std::string& folder);

std::size_t count_lines(const std::string& filename);

std::string file_contents(const std::string& filename);

std::string get_seq(const std::string& fasta_filename, const std::string& chr_name);

hash_t hash_(char const* str);

constexpr hash_t hash_compile_time(char const *str, hash_t last_value = basis)
{
    return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

constexpr std::uint64_t operator""_hash(char const *p, size_t)
{
    return hash_compile_time(p);
}