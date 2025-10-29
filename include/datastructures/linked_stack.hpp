//
// Created by Benson on 2025/10/29.
//

#ifndef INC_408_DATASTRUCTURE_LINKED_STACK_HPP
#define INC_408_DATASTRUCTURE_LINKED_STACK_HPP
#include <memory>

#include "node.hpp"

namespace datastructures {
    class LinkedStack {
        std::shared_ptr<Node> topNode;
        int currentSize;

    public:
        LinkedStack();

        void push(int);

        int pop();

        int peek() const;

        bool isEmpty() const;

        int size() const;
    };
}

#endif //INC_408_DATASTRUCTURE_LINKED_STACK_HPP
