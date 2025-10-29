//
// Created by Benson on 2025/10/29.
//

#include "../../include/datastructures/array_stack.hpp"

#include <memory>

namespace datastructures {
    ArrayStack::ArrayStack(int maxSize) {
        this->maxSize = maxSize;
        this->topPosition = -1;
        this->containers = std::make_unique<int[]>(maxSize);
    }

    bool ArrayStack::push(int val) {
        if (topPosition == maxSize - 1) {
            throw std::overflow_error("Stack overflow: cannot push to full stack");
        }
        topPosition++;
        containers[topPosition] = val;
        return true;
    }

    int ArrayStack::pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot pop from empty stack");
        }
        return containers[topPosition--];
    }

    int ArrayStack::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot peek from empty stack");
        }
        return containers[topPosition];
    }

    bool ArrayStack::isFull() const {
        return topPosition == maxSize - 1;
    }

    bool ArrayStack::isEmpty() const {
        return topPosition == -1;
    }

    int ArrayStack::size() const {
        return topPosition + 1;
    }
}
