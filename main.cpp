#include <iostream>

#include "include/datastructures/array_queue.hpp"

using namespace datastructures;


int main() {
    try {
        const int capacity = 10;
        ArrayQueue queue(capacity);

        std::cout << "ArrayQueue Extended Test Start" << std::endl;
        std::cout << "Is the queue initially empty? " << std::boolalpha << queue.isEmpty() << std::endl;

        // Enqueue more than capacity to test full condition
        for (int i = 1; i <= capacity + 2; ++i) {
            if (queue.enqueue(i * 10)) {
                std::cout << "Enqueue: " << i * 10 << " (size = " << queue.size() << ")" << std::endl;
            }
            else {
                std::cout << "Failed to enqueue: " << i * 10 << " (queue is full)" << std::endl;
            }
        }

        // Peek multiple times
        for (int i = 0; i < 3; ++i) {
            if (!queue.isEmpty()) {
                std::cout << "Peek: " << queue.peek() << " (size = " << queue.size() << ")" << std::endl;
            }
        }

        // Dequeue half of elements
        for (int i = 0; i < 5; ++i) {
            std::cout << "Dequeue: " << queue.dequeue() << " (size = " << queue.size() << ")" << std::endl;
        }

        // Enqueue again to test wrap-around
        for (int i = 11; i <= 15; ++i) {
            if (queue.enqueue(i * 10)) {
                std::cout << "Enqueue: " << i * 10 << " (size = " << queue.size() << ")" << std::endl;
            }
            else {
                std::cout << "Failed to enqueue: " << i * 10 << " (queue is full)" << std::endl;
            }
        }

        // Dequeue all remaining elements
        while (!queue.isEmpty()) {
            std::cout << "Dequeue: " << queue.dequeue() << " (size = " << queue.size() << ")" << std::endl;
        }

        // Attempt dequeue on empty queue
        try {
            queue.dequeue();
        }
        catch (const std::underflow_error& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "ArrayQueue Extended Test End" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
