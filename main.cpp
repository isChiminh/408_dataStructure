#include <iostream>
#include"include/datastructures/linked_list.hpp"
using namespace datastructures;


int main() {
    LinkedList list;

    const int N = 10000; // 测试大规模节点

    // 1️⃣ 批量 push_back
    for (int i = 0; i < N; i++) {
        list.push_back(i);
    }
    std::cout << "After push_back 0~" << N - 1 << ", length: " << list.length() << "\n";

    // 2️⃣ 随机删除 200 个节点
    for (int i = 0; i < 200; i++) {
        int index = rand() % list.length();
        list.removeByIndex(index);
    }
    std::cout << "After removing 200 random nodes, length: " << list.length() << "\n";

    // 3️⃣ 批量 push_front
    for (int i = N; i < N + 500; i++) {
        list.push_front(i);
    }
    std::cout << "After push_front 1000~1499, length: " << list.length() << "\n";

    // 4️⃣ 删除所有节点
    while (list.length() > 0) {
        list.removeByIndex(0); // 每次删除头节点
    }
    std::cout << "After removing all nodes, length: " << list.length() << "\n";

    // 5️⃣ 检查空链表操作是否安全
    list.removeByIndex(0); // 空链表删除
    list.removeByValue(123); // 空链表删除值
    Node* node = list.find(0); // 空链表查找
    std::cout << "Find in empty list: " << (node ? "Found" : "Not Found") << "\n";

    std::cout << "Stress test completed successfully!" << std::endl;

    return 0;
}
