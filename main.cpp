#include <iostream>
#include <string>
#include "include/algorithms/bracket_matching.hpp"

int main() {
    std::cout << std::boolalpha;  // 打印 true/false

    // 空串
    std::cout << bracketMatching("") << "\n";              // true

    // 单一对括号
    std::cout << bracketMatching("()") << "\n";            // true
    std::cout << bracketMatching("[]") << "\n";            // true
    std::cout << bracketMatching("{}") << "\n";            // true

    // 嵌套括号
    std::cout << bracketMatching("({[]})") << "\n";        // true
    std::cout << bracketMatching("[({})]") << "\n";        // true

    // 错误顺序
    std::cout << bracketMatching("(]") << "\n";            // false
    std::cout << bracketMatching("([)]") << "\n";          // false

    // 多余括号
    std::cout << bracketMatching("(") << "\n";             // false
    std::cout << bracketMatching(")") << "\n";             // false
    std::cout << bracketMatching("((()))(") << "\n";       // false

    // 长串测试
    std::cout << bracketMatching("({[]}){}[()({})]") << "\n"; // true

    return 0;
}
