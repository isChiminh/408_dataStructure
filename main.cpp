#include <iostream>
#include "include/datastructures/array_stack.hpp"

using namespace datastructures;


int main() {
    try {
        ArrayStack stack(5);

        std::cout << "Test start" << std::endl;
        std::cout << "Is the stack initially empty? " << std::boolalpha << stack.isEmpty() << std::endl;

        // Push elements
        for (int i = 1; i <= 5; ++i) {
            stack.push(i * 10);
            std::cout << "Push: " << i * 10 << " (size = " << stack.size() << ")" << std::endl;
        }

        std::cout << "Current top element: " << stack.peek() << std::endl;

        // Try pushing when full
        try {
            stack.push(60);
        } catch (const std::overflow_error &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

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

        std::cout << "Test end" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
