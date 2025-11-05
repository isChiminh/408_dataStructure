#include <iostream>

#include "include/algorithms/expression_utils.hpp"
using namespace std;

int main() {
    string tests[] = {
        "1+2",
        "1+2*3",
        "(1+2)*3",
        "1+(2*3-4)/5",
        "8*3+6/2-4",
        "7*(9-3)/(2+1)"
    };

    cout << "Infix to Postfix + Evaluation" << endl;
    cout << "--------------------------------" << endl;

    for (auto &expr : tests) {
        string postfix = infixToPostfix(expr);
        int value = evaluatePostfix(postfix);
        cout << "Infix:    " << expr << endl;
        cout << "Postfix:  " << postfix << endl;
        cout << "Value:    " << value << endl;
        cout << "--------------------------------" << endl;
    }

    return 0;
}