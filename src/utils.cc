#include <string>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
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
std::size_t 

#endif