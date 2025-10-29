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
        auto newTop = std::make_unique<Node>(val);
        newTop->next = std::move(topNode); // 头插法
        topNode = std::move(newTop);
        currentSize++;
    }

    int LinkedStack::pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot pop from empty stack");
        }
        auto d_node = std::move(topNode);
        topNode = std::move(d_node->next);
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
