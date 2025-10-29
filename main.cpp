#include <iostream>
#include "include/datastructures/linked_stack.hpp"

using namespace datastructures;


int main() {
    try {
        LinkedStack stack;

        std::cout << "LinkedStack Test Start" << std::endl;
        std::cout << "Is the stack initially empty? " << std::boolalpha << stack.isEmpty() << std::endl;

        // Push elements
        for (int i = 1; i <= 5; ++i) {
            stack.push(i * 10);
            std::cout << "Push: " << i * 10 << " (size = " << stack.size() << ")" << std::endl;
        }

        std::cout << "Current top element: " << stack.peek() << std::endl;

        // Push another element
        stack.push(60);
        std::cout << "Push: 60 (size = " << stack.size() << ")" << std::endl;
        std::cout << "New top element: " << stack.peek() << std::endl;

        // Pop all elements
        while (!stack.isEmpty()) {
            std::cout << "Pop: " << stack.pop() << " (size = " << stack.size() << ")" << std::endl;
        }

        // Try popping when empty
        try {
            stack.pop();
        } catch (const std::underflow_error &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "LinkedStack Test End" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}