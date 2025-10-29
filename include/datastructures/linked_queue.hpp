//
// Created by Benson on 2025/10/29.
//

#ifndef INC_408_DATASTRUCTURE_LINKED_QUEUE_HPP
#define INC_408_DATASTRUCTURE_LINKED_QUEUE_HPP
#include <memory>

#include "node.hpp"

namespace datastructures {
    class LinkedQueue {
        std::shared_ptr<Node> front;
        std::shared_ptr<Node> rear;
        int currentSize;

    public:
        LinkedQueue();
        void enqueue(int val);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
        int size() const;
        void clear();
    };
}

#endif //INC_408_DATASTRUCTURE_LINKED_QUEUE_HPP
