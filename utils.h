#ifndef UTILS_H
#define UTILS_H
#include <iterator>
#include <string>
#include <fstream>

inline std::string readFile(const std::string &filename)
{
    std::ifstream file(filename);
    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

inline void writeFile(const std::string &filename, const std::string &data)
{
    std::ofstream file(filename);
    file << data;
}

#endif