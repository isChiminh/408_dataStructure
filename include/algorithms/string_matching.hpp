//
// Created by Benson on 2025/11/5.
//

#ifndef INC_408_DATASTRUCTURE_STRING_MATCHING_HPP
#define INC_408_DATASTRUCTURE_STRING_MATCHING_HPP
#include <string>
#include <vector>

int bruteForceMatch(std::string, std::string);
int kmpMatch(std::string, std::string);
int kmpMatch(std::string, std::string, std::vector<int>);
std::vector<int> getNext(std::string);
std::vector<int> getNextValue(std::string);
#endif //INC_408_DATASTRUCTURE_STRING_MATCHING_HPP