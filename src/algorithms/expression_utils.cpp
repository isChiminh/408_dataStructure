//
// Created by Benson on 2025/11/2.
//
#include "../../include/datastructures/linked_stack.hpp"
#include "../../include/algorithms/expression_utils.hpp"

int evaluatePrefix(std::string expression) {
    auto num_stack = datastructures::LinkedStack();
    for (int i = expression.size() - 1; i >= 0; i--) {
        char c = expression[i];
        if (c >= '0' and c <= '9') {
            num_stack.push(c - '0');
        }
        else {
            int left = num_stack.pop();
            int right = num_stack.pop();
            switch (c) {
            case '+': num_stack.push(left + right);
                break;
            case '-': num_stack.push(left - right);
                break;
            case '*': num_stack.push(left * right);
                break;
            case '/': num_stack.push(left / right);
                break;
            default: break;
            }
        }
    }
    return num_stack.pop();
}

int evaluateInfix(std::string expression) {
    auto opr_stack = datastructures::LinkedStack();
    auto num_stack = datastructures::LinkedStack();
    for (auto c : expression) {
        //遇到操作数直接加入后缀表达式
        if (c >= '0' and c <= '9') {
            num_stack.push(c - '0');
        }
        //遇到左括号(直接入栈
        else if (c == '(') {
            opr_stack.push(c);
        }
        //遇到右括号)直接入栈,依次弹出运算符并加入后缀表达式,删除左括号(
        else if (c == ')') {
            while (opr_stack.peek() != '(') {
                int right = num_stack.pop();
                int left = num_stack.pop();
                switch (opr_stack.pop()) {
                case '+': num_stack.push(left + right);
                    break;
                case '-': num_stack.push(left - right);
                    break;
                case '*': num_stack.push(left * right);
                    break;
                case '/': num_stack.push(left / right);
                    break;
                default: break;
                }
            }
            if (opr_stack.peek() == '(') {
                opr_stack.pop();
            }
        }
        //遇到运算符
        else {
            //栈空直接入栈
            if (opr_stack.isEmpty() or opr_stack.peek() == '(') {
                opr_stack.push(c);
            }
            else {
                if (c == '*' or c == '/') {
                    while (!opr_stack.isEmpty() and opr_stack.peek() != '(' and opr_stack.peek() != '+' and opr_stack.
                        peek() != '-') {
                        int right = num_stack.pop();
                        int left = num_stack.pop();
                        switch (opr_stack.pop()) {
                        case '+': num_stack.push(left + right);
                            break;
                        case '-': num_stack.push(left - right);
                            break;
                        case '*': num_stack.push(left * right);
                            break;
                        case '/': num_stack.push(left / right);
                            break;
                        default: break;
                        }
                    }
                    opr_stack.push(c);
                }
                else if (c == '+' or c == '-') {
                    while (!opr_stack.isEmpty() and opr_stack.peek() != '(') {
                        int right = num_stack.pop();
                        int left = num_stack.pop();
                        switch (opr_stack.pop()) {
                        case '+': num_stack.push(left + right);
                            break;
                        case '-': num_stack.push(left - right);
                            break;
                        case '*': num_stack.push(left * right);
                            break;
                        case '/': num_stack.push(left / right);
                            break;
                        default: break;
                        }
                    }
                    opr_stack.push(c);
                }
            }
        }
    }
    //扫描结束后弹出栈中运算符
    while (!opr_stack.isEmpty()) {
        int right = num_stack.pop();
        int left = num_stack.pop();
        switch (opr_stack.pop()) {
        case '+': num_stack.push(left + right);
            break;
        case '-': num_stack.push(left - right);
            break;
        case '*': num_stack.push(left * right);
            break;
        case '/': num_stack.push(left / right);
            break;
        default: break;
        }
    }
    return num_stack.pop();
}

int evaluatePostfix(std::string expression) {
    auto num_stack = datastructures::LinkedStack();
    for (auto c : expression) {
        if (c >= '0' and c <= '9') {
            num_stack.push(c - '0');
        }
        else {
            int right = num_stack.pop();
            int left = num_stack.pop();
            switch (c) {
            case '+': num_stack.push(left + right);
                break;
            case '-': num_stack.push(left - right);
                break;
            case '*': num_stack.push(left * right);
                break;
            case '/': num_stack.push(left / right);
                break;
            default: break;
            }
        }
    }
    return num_stack.pop();
}

std::string infixToPostfix(std::string expression) {
    auto stack = datastructures::LinkedStack();
    std::string new_expression;
    for (auto c : expression) {
        //遇到操作数直接加入后缀表达式
        if (c >= '0' and c <= '9') {
            new_expression += c;
        }
        //遇到左括号(直接入栈
        else if (c == '(') {
            stack.push(c);
        }
        //遇到右括号)直接入栈,依次弹出运算符并加入后缀表达式,删除左括号(
        else if (c == ')') {
            while (stack.peek() != '(') {
                new_expression += stack.pop();
            }
            if (stack.peek() == '(') {
                stack.pop();
            }
        }
        //遇到运算符
        else {
            //栈空直接入栈
            if (stack.isEmpty() or stack.peek() == '(') {
                stack.push(c);
            }
            else {
                if (c == '*' or c == '/') {
                    while (!stack.isEmpty() and stack.peek() != '(' and stack.peek() != '+' and stack.peek() != '-') {
                        new_expression += stack.pop();
                    }
                    stack.push(c);
                }
                else if (c == '+' or c == '-') {
                    while (!stack.isEmpty() and stack.peek() != '(') {
                        new_expression += stack.pop();
                    }
                    stack.push(c);
                }
            }
        }
    }
    //扫描结束后弹出栈中运算符
    while (!stack.isEmpty()) {
        new_expression += stack.pop();
    }
    return new_expression;
}
