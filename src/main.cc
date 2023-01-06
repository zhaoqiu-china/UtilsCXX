#include <iostream>
#include <string>
#include "utils.h"

int main()
{
    //std::cout << "files cont: " << count_files("/home/zhaoqiu/Projects/utils") << std::endl;
    //std::cout << get_seq("D:\\Python_study\\primer3_utils\\temp\\ABI\\Rice_reference\\Oryza_sativa.IRGSP-1.0_boruidiRename.fa", "chr2");
    //std::cout << get_seq("D:\\Temp\\a.txt", "chr2");
    // std::string str("a");
    // switch (hash_(str.c_str()))
    // {
    // case "a"_hash:
    //     std::cout << "a" << std::endl;
    //     break;
    
    // default:
    //     break;
    // }
    std::string str("1,2,3,");
    auto v = str_split_to_int(str);
    for (const auto& value: v)
    {
        std::cout << value << std::endl;
    }
    std::cout << "main end" << std::endl;
    return 0;
}