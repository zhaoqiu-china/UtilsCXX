#include <gtest/gtest.h>
#include "../src/utils.h"

TEST(UtilsTest, BasicAssertions) {
    std::vector<int> v{1, 2};
    EXPECT_EQ(str_split_to_int("1,2"), v);
    EXPECT_EQ(str_split_to_int("1,2,"), v);
    std::string sourced_dir{RESOURCES_DIR};
    std::string test_fasta_path = sourced_dir + "/test_fasta.txt";
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
}