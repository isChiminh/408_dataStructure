//
// Created by Benson on 2025/10/29.
//

#include "../../include/datastructures/linked_stack.hpp"

namespace datastructures {
    LinkedStack::LinkedStack() {
        this->topNode = nullptr;
        this->currentSize = 0;
    }

    void LinkedStack::push(int val) {
        auto newTop = std::make_shared<Node>(val);
        newTop->next = topNode; // 头插法
        topNode = newTop;
        currentSize++;
    }

    int LinkedStack::pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot pop from empty stack");
        }
        auto d_node = topNode;
        topNode = topNode->next;
        //d_node->next = nullptr;//没必要，函数调用结束d_node会被释放，d_node所指向的那个share_ptr也会被释放
        currentSize--;
        return d_node->data;
    }

    int LinkedStack::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot peek from empty stack");
        }
        return topNode->data;
    }

    bool LinkedStack::isEmpty() const {
        return topNode == nullptr;
    }

    int LinkedStack::size() const {
        return currentSize;
    }
}
