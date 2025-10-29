//
// Created by Benson on 2025/10/24.
//

#ifndef INC_408_DATASTRUCTURE_NODE_HPP
#define INC_408_DATASTRUCTURE_NODE_HPP
#include <memory>

namespace datastructures {
    class Node {
    public:
        int data = 0;
        std::unique_ptr<Node> next = nullptr;

        Node() = default;

        Node(int data) {
            this->data = data;
        }
    };
} // datastructures

#endif //INC_408_DATASTRUCTURE_NODE_HPP
