#include "header.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <numeric>
#include <iterator>

// SortByUppercase implementation
void SortByUppercase(std::vector<std::string>& words) {
    auto get_uppercase = [](const std::string& s) {
        std::string uppercase_letters;
        std::copy_if(s.begin(), s.end(), std::back_inserter(uppercase_letters), [](char c) {
            return std::isupper(static_cast<unsigned char>(c));
            });
        return uppercase_letters;
    };

    std::stable_sort(words.begin(), words.end(), [&](const std::string& a, const std::string& b) {
        return get_uppercase(a) < get_uppercase(b);
        });
}

// DoubleToPercentString implementation
std::string DoubleToPercentString(const std::vector<double>& doubles) {
    return std::accumulate(doubles.begin(), doubles.end(), std::string(), [](const std::string& acc, double d) {
        int percentage = static_cast<int>(d * 100);
        return acc + std::to_string(percentage) + "% ";
        });
}

// Main function
int main() {
    // Test SortByUppercase
    std::vector<std::string> words = { "wolf", "BanAna", "caRRot", "AprIcots", "BEets", "chiCkPeas", "orAngEs", "apple", "CAT", "dOG" };
    std::vector<std::string> expected = { "wolf", "apple", "orAngEs", "AprIcots", "BanAna", "BEets", "CAT", "chiCkPeas", "dOG", "caRRot" };
    SortByUppercase(words);
    if (words == expected) {
        std::cout << "SortByUppercase test passed." << std::endl;
    }
    else {
        std::cout << "SortByUppercase test failed." << std::endl;
        std::cout << "Expected: ";
        std::copy(expected.begin(), expected.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << "\nGot: ";
        std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }

    // Test with empty vectors
    words = {};
    expected = {};
    SortByUppercase(words);
    if (words == expected) {
        std::cout << "SortByUppercase empty test passed." << std::endl;
    }
    else {
        std::cout << "SortByUppercase empty test failed." << std::endl;
    }

    words = { "", "", "" };
    expected = { "", "", "" };
    SortByUppercase(words);
    if (words == expected) {
        std::cout << "SortByUppercase empty strings test passed." << std::endl;
    }
    else {
        std::cout << "SortByUppercase empty strings test failed." << std::endl;
    }

    // Test DoubleToPercentString
    std::vector<double> const doubles = { 1, 2, 100, 200, 12.3456, 4787, 0.123 };
    std::string expected_string = "100% 200% 10000% 20000% 1234% 478700% 12% ";
    std::string result = DoubleToPercentString(doubles);
    if (result == expected_string) {
        std::cout << "DoubleToPercentString test passed." << std::endl;
    }
    else {
        std::cout << "DoubleToPercentString test failed." << std::endl;
        std::cout << "Expected: " << expected_string << std::endl;
        std::cout << "Got: " << result << std::endl;
    }

    return 0;
}
