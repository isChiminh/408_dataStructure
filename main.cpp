#include <iostream>

#include "include/algorithms/expression_utils.hpp"
using namespace std;

void testInfixEvaluation() {
    cout << "Testing: 1 + 2\n";
    cout << "Result: " << evaluateInfix("1+2") << " (Expected: 3)\n\n";

    cout << "Testing: 3 - 2\n";
    cout << "Result: " << evaluateInfix("3-2") << " (Expected: 1)\n\n";

    cout << "Testing: 2 * 3\n";
    cout << "Result: " << evaluateInfix("2*3") << " (Expected: 6)\n\n";

    cout << "Testing: 6 / 2\n";
    cout << "Result: " << evaluateInfix("6/2") << " (Expected: 3)\n\n";

    cout << "Testing: 1 + 2 * 3\n";
    cout << "Result: " << evaluateInfix("1+2*3") << " (Expected: 7)\n\n"; // 1 + (2 * 3)

    cout << "Testing: 3 + 4 * 5\n";
    cout << "Result: " << evaluateInfix("3+4*5") << " (Expected: 23)\n\n"; // 3 + (4 * 5)

    cout << "Testing: (1 + 2) * 3\n";
    cout << "Result: " << evaluateInfix("(1+2)*3") << " (Expected: 9)\n\n"; // (1 + 2) * 3

    cout << "Testing: 2 * (3 + 5)\n";
    cout << "Result: " << evaluateInfix("2*(3+5)") << " (Expected: 16)\n\n"; // 2 * (3 + 5)

    cout << "Testing: (1 + 2) * (3 + 4)\n";
    cout << "Result: " << evaluateInfix("(1+2)*(3+4)") << " (Expected: 21)\n\n"; // (1 + 2) * (3 + 4)

    cout << "Testing: (1 + 2) * (3 + 4)\n";
    cout << "Result: " << evaluateInfix("(1+2)*(3+4)") << " (Expected: 21)\n\n"; // (1 + 2) * (3 + 4)
}

int main() {
    testInfixEvaluation(); // 调用测试函数
    return 0;
}
