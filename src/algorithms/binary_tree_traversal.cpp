//
// Created by Benson on 2025/11/28.
//

#include "../../include/algorithms/binary_tree_traversal.hpp"
#include <iostream>
#include <queue>

void preOrder(datastructures::TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preOrder(root->left.get());
        preOrder(root->right.get());
    }
}

void inOrder(datastructures::TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left.get());
        std::cout << root->data << " ";
        inOrder(root->right.get());
    }
}

void postOrder(datastructures::TreeNode* root) {
    if (root != nullptr) {
        postOrder(root->left.get());
        postOrder(root->right.get());
        std::cout << root->data << " ";
    }
}

void levelOrder(datastructures::TreeNode* root) {
    if (root == nullptr) return;

    auto queue = std::queue<datastructures::TreeNode*>();
    queue.push(root);
    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();
        std::cout << node->data << " ";
        if (node->left != nullptr) {
            queue.push(node->left.get());
        }
        if (node->right != nullptr) {
            queue.push(node->right.get());
        }
    }
}

void preOrder_(datastructures::TreeNode* root) {}
void inOrder_(datastructures::TreeNode* root) {}
void postOrder_(datastructures::TreeNode* root) {}
