//
// Created by Benson on 2025/10/29.
//

#ifndef INC_408_DATASTRUCTURE_ARRAY_STACK_HPP
#define INC_408_DATASTRUCTURE_ARRAY_STACK_HPP
#include <memory>

namespace datastructures {
    class ArrayStack {
        int maxSize;
        int topPosition;
        std::unique_ptr<int[]> containers;

    public:
        ArrayStack(int);

        bool push(int);

        int pop();

        int peek() const;
        bool isFull() const;
        bool isEmpty() const;

        int size() const;
    };
}

#endif //INC_408_DATASTRUCTURE_ARRAY_STACK_HPP
