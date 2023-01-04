#include <iostream>
#include "utils.h"

int main()
{
    //std::cout << "files cont: " << count_files("/home/zhaoqiu/Projects/utils") << std::endl;
    std::cout << get_seq("D:\\Python_study\\primer3_utils\\temp\\ABI\\Rice_reference\\Oryza_sativa.IRGSP-1.0_boruidiRename.fa", "chr2");
    //std::cout << get_seq("D:\\Temp\\a.txt", "chr2");
    return 0;
}