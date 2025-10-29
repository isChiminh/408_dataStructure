#include <iostream>
#include "include/datastructures/linked_queue.hpp"
using namespace datastructures;

int main() {
    std::cout << "=== LinkedQueue Test Cases ===\n";

    LinkedQueue queue;

    // 1. Check empty queue
    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    // 2. Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Current queue size after enqueue 10, 20, 30: " << queue.size() << "\n";

    // 3. Peek front element
    try {
        std::cout << "Front element: " << queue.peek() << "\n"; // 10
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    // 4. Dequeue elements
    try {
        std::cout << "Dequeue: " << queue.dequeue() << "\n"; // 10
        std::cout << "Dequeue: " << queue.dequeue() << "\n"; // 20
        std::cout << "Dequeue: " << queue.dequeue() << "\n"; // 30
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    // 5. Dequeue from empty queue
    try {
        queue.dequeue();
    } catch (const std::exception& e) {
        std::cout << "Dequeue from empty queue: " << e.what() << "\n";
    }

    // 6. Peek on empty queue
    try {
        queue.peek();
    } catch (const std::exception& e) {
        std::cout << "Peek on empty queue: " << e.what() << "\n";
    }

    // 7. Check empty after dequeues
    std::cout << "Is the queue empty after dequeues? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    // 8. Enqueue more elements
    queue.enqueue(100);
    queue.enqueue(200);

    std::cout << "Current queue size after enqueue 100, 200: " << queue.size() << "\n";
    try {
        std::cout << "Front element now: " << queue.peek() << "\n"; // 100
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    // 9. Clear the queue
    queue.clear();
    std::cout << "Queue cleared. Is empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
