//
// Created by Benson on 2025/11/28.
//

#ifndef INC_408_DATASTRUCTURE_TREE_NODE_HPP
#define INC_408_DATASTRUCTURE_TREE_NODE_HPP
#include <memory>

namespace datastructures {
    class TreeNode {
    public:
        int data = 0;
        std::unique_ptr<TreeNode> left = nullptr;
        std::unique_ptr<TreeNode> right = nullptr;
        TreeNode() = default;

        TreeNode(int data) {
            this->data = data;
        }

        TreeNode(int data, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) {
            this->data = data;
            this->left = std::move(left);
            this->right = std::move(right);
        }
    };
} // datastructures
#endif //INC_408_DATASTRUCTURE_TREE_NODE_HPP
