#include <iostream>
#include <string>
#include <string_view>
#include "utils.h"

volatile double ret;

int main()
{
    // int s1{123};
    // int &s_ref_const = s1;
    // s_ref_const += 1234;
    // std::cout << s1 << std::endl;
    // std::string s = R"(dfds\n)";
    // std::cout << s << std::endl;
    std::string s{"1234"};
    std::string_view s_view(s);
    std::cout << s_view << std::endl;
    // auto start = std::chrono::system_clock::now();
    // ret = 2;
    // for (size_t i = 0; i < 1000000; i++)
    // {
    //     ret += i;
    // }
    // auto end = std::chrono::system_clock::now();

    // auto elapsed_time = end - start;
    // std::chrono::duration<double> diff = end - start;
    // std::cout << elapsed_time.count() << std::endl;
    // std::cout << diff.count() << std::endl;
    
    return 0;
}