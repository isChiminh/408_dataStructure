#include <iostream>
#include "include/datastructures/tree_node.hpp"
#include "include/algorithms/binary_tree_traversal.hpp"

int main() {
    using datastructures::TreeNode;
    using std::make_unique;

    // 构建测试树
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    auto root = make_unique<TreeNode>(1);
    root->left = make_unique<TreeNode>(2);
    root->right = make_unique<TreeNode>(3);
    root->left->left = make_unique<TreeNode>(4);
    root->left->right = make_unique<TreeNode>(5);
    root->right->right = make_unique<TreeNode>(6);

    // 测试递归遍历
    std::cout << "Pre-order recursive: ";
    preOrder(root.get());
    std::cout << "\n";

    std::cout << "In-order recursive: ";
    inOrder(root.get());
    std::cout << "\n";

    std::cout << "Post-order recursive: ";
    postOrder(root.get());
    std::cout << "\n";

    // 测试层序遍历
    std::cout << "Level-order: ";
    levelOrder(root.get());
    std::cout << "\n";

    return 0;
}
