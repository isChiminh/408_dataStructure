//
// Created by Benson on 2025/10/24.
//

#ifndef INC_408_DATASTRUCTURE_LINKED_LIST_HPP
#define INC_408_DATASTRUCTURE_LINKED_LIST_HPP

#include "node.hpp"

namespace datastructures {
    class LinkedList {
    public:
        std::unique_ptr<Node> head = nullptr;

        LinkedList();

        LinkedList(int);

        int length();

        void push_front(int);

        void push_back(int);

        bool removeByValue(int);

        bool removeByIndex(int);

        bool contains(int);

        Node* find(int);

        Node* locate(int);

        void print();
    };
} // datastructures

#endif //INC_408_DATASTRUCTURE_LINKED_LIST_HPP
