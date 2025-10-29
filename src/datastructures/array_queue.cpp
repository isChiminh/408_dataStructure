//
// Created by Benson on 2025/10/29.
//

#include "../../include/datastructures/array_queue.hpp"

namespace datastructures {
    ArrayQueue::ArrayQueue(int maxSize) {
        this->maxSize = maxSize;
        this->currentSize = 0;
        this->front = 0;
        this->rear = 0;
        this->containers = std::make_unique<int[]>(maxSize);
    }

    bool ArrayQueue::enqueue(int val) {
        if (isFull()) {
            return false;
        }
        containers[rear] = val;
        rear = (rear + 1) % maxSize;
        currentSize++;
        return true;
    }

    int ArrayQueue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow: cannot dequeue from empty queue");
        }
        int first = containers[front];
        front = (front + 1) % maxSize;
        currentSize--;
        return first;
    }

    int ArrayQueue::peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow: cannot peek from empty queue");
        }
        return containers[front];
    }

    bool ArrayQueue::isFull() const {
        return front == (rear + 1) % maxSize;
    }

    bool ArrayQueue::isEmpty() const {
        return front == rear;
    }

    int ArrayQueue::size() const {
        return this->currentSize;
    }

    void ArrayQueue::clear() {
        this->front = 0;
        this->rear = 0;
        this->currentSize = 0;
    }
}
