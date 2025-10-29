//
// Created by Benson on 2025/10/29.
//

#include "../../include/datastructures/linked_queue.hpp"

namespace datastructures {
    LinkedQueue::LinkedQueue() {
        currentSize = 0;
        this->front = nullptr;
        this->rear = nullptr;
    }

    void LinkedQueue::enqueue(int val) {
        if (isEmpty()) {
            auto first = std::make_shared<Node>(val);
            this->front = first;
            this->rear = first;
        }
        else {
            auto newNode = std::make_shared<Node>(val);
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    int LinkedQueue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow: cannot dequeue from empty queue");
        }
        auto d_node = front;
        front = d_node->next;
        //d_node->next = nullptr;
        currentSize--;
        //特别注意最后一个元素出队时要把rear指针也指向空
        if (front == nullptr) {
            rear = nullptr;
        }
        return d_node->data;
    }

    int LinkedQueue::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow: cannot peek from empty queue");
        }
        return front->data;
    }

    bool LinkedQueue::isEmpty() const {
        return front == nullptr and rear == nullptr;
    }

    int LinkedQueue::size() const {
        return currentSize;
    }

    void LinkedQueue::clear() {
        this->front = nullptr;
        this->rear = nullptr;
        this->currentSize = 0;
    }
}
