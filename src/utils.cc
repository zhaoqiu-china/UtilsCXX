#include <string>
#include <fstream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#else

#include <dirent.h>
#endif

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