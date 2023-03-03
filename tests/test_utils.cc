#include <gtest/gtest.h>
#include "../src/utils.h"

TEST(UtilsTest, BasicAssertions) {
    std::vector<int> v{1, 2};
    EXPECT_EQ(str_split_to_int("1,2"), v);
    EXPECT_EQ(str_split_to_int("1,2,"), v);
    std::string sourced_dir{RESOURCES_DIR};
    std::string test_fasta_path = RESOURCES_DIR "/test_fasta.txt";
    std::string seq{"CCCTAAACCCTAAACCCTAAACCCTAAACCCTAAACAGCTGACAGTACGATAGATCCACGCGAGAGGAACCGGAGAGACAACGGGATCCAGGCGCCAGCGACGGATCCGGGCGAGAGGGGAG"};
    EXPECT_EQ(seq, get_seq(test_fasta_path, "chr1"));
    EXPECT_EQ(1, count_files(sourced_dir));
    EXPECT_EQ(6, count_lines(test_fasta_path));
    std::string value{"abcde"};
    std::string ends1{"123"};
    std::string ends2{"cde"};
    std::string ends3{"abcdef"};
    EXPECT_FALSE(ends_with(value, ends1));
    EXPECT_TRUE(ends_with(value, ends2));
    EXPECT_FALSE(ends_with(value, ends3));

    // use string as case in switch
    switch (hash_compile_time("case1"))
    {
    case "case1"_hash:
        std::cout << "case1" << std::endl;
        EXPECT_EQ(1, 1);
        break;
    case "case2"_hash:
        std::cout << "case2" << std::endl;
        EXPECT_EQ(1, 2);
        break;
    default:
        break;
    }
}