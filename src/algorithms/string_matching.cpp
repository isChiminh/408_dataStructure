//
// Created by Benson on 2025/11/5.
//

#include "../../include/algorithms/string_matching.hpp"

#include <vector>


int bruteForceMatch(std::string main, std::string sub) {
    for (int i = 0; i < main.length(); i++) {
        if (main[i] == sub[0]) {
            bool flag = true;
            for (int j = 0; j < sub.length(); j++) {
                if (main[i + j] != sub[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
    }
    return -1;
}

int kmpMatch(std::string main, std::string sub) {
    if (sub.size() == 0) {
        return -1;
    }
    return kmpMatch(main, sub, getNext(sub));
}

int kmpMatch(std::string main, std::string sub, std::vector<int> next) {
    // KMP 匹配过程
    int j = 0; // 模式串指针
    for (int i = 0; i < main.size(); i++) { // 遍历文本
        while (j > 0 && main[i] != sub[j]) {
            j = next[j - 1];
        }
        if (main[i] == sub[j]) {
            j++;
        }
        if (j == sub.size()) { // 匹配成功
            return i - sub.size() + 1; // 返回匹配的起始位置
        }
    }
    return -1; // 未匹配
}

std::vector<int> getNext(std::string sub) {
    std::vector<int> next;
    next.push_back(0);
    for (int i = 1, j = 0; i < sub.length(); i++) {
        while (j > 0 and sub[i] != sub[j]) {
            j = next[j - 1];
        }
        if (sub[i] == sub[j]) {
            j++;
        }
        next.push_back(j);
    }
    return next;
}

std::vector<int> getNextValue(std::string sub) {

}