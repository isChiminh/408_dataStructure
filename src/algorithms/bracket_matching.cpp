//
// Created by Benson on 2025/10/30.
//

#include "../../include/algorithms/bracket_matching.hpp"
#include "../../include/datastructures/linked_stack.hpp"


bool bracketMatching(std::string s) {
    auto stack = datastructures::LinkedStack();
    for (auto c : s) {
        if (c == '(' or c == '{' or c == '[') {
            stack.push(c);
        }
        else if (c == ')' or c == '}' or c == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            auto top = stack.pop();
            if (c == ')' and top != '(' or c == '}' and top != '{' or c == ']' and top != '[') {
                return false;
            }
        }
    }
    return stack.isEmpty();
}
