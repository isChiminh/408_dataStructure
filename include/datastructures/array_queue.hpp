//
// Created by Benson on 2025/10/29.
//

#ifndef INC_408_DATASTRUCTURE_ARRAY_QUEUE_HPP
#define INC_408_DATASTRUCTURE_ARRAY_QUEUE_HPP
#include <memory>

namespace datastructures {
    class ArrayQueue {
        int maxSize;
        int currentSize;
        int front; //队头位置
        int rear; //队尾元素的下一个位置(入队位置，不是最后一个元素)
        std::unique_ptr<int[]> containers;

    public:
        ArrayQueue(int);
        bool enqueue(int);
        int dequeue();
        int peek() const;
        bool isFull() const;
        bool isEmpty() const;
        int size() const;
        void clear();
    };
}

#endif //INC_408_DATASTRUCTURE_ARRAY_QUEUE_HPP
