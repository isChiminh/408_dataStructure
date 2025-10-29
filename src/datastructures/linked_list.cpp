//
// Created by Benson on 2025/10/24.
//

#include "../../include/datastructures/linked_list.hpp"

#include <climits>
#include <iostream>

namespace datastructures {
    LinkedList::LinkedList() {
        head = std::make_shared<Node>(INT_MIN);
    }

    LinkedList::LinkedList(int val) {
        head = std::make_shared<Node>(INT_MIN);
        push_back(val);
    }

    int LinkedList::length() {
        int length = 0;
        auto temp_ptr = head; //获取裸指针
        while (temp_ptr->next) {
            length++;
            temp_ptr = temp_ptr->next;
        }
        return length;
    }

    void LinkedList::push_front(int val) {
        auto new_first = std::make_shared<Node>(val);
        new_first->next = head->next;
        head->next = new_first;
    }

    void LinkedList::push_back(int val) {
        auto new_last = std::make_shared<Node>(val);
        auto temp_ptr = head; //获取裸指针
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next;
        }
        temp_ptr->next = new_last;
    }

    bool LinkedList::removeByValue(int value) {
        auto temp_ptr = head;
        while (temp_ptr->next) {
            if (temp_ptr->next->data == value) {
                auto d_node = temp_ptr->next;
                temp_ptr->next = d_node->next;
                //没有对象指向d_node，share_ptr引用值为0，会自动释放内存
                return true;
            }
            temp_ptr = temp_ptr->next;
        }
        return false;
    }

    bool LinkedList::removeByIndex(int index) {
        int size = length();
        if (index < 0 || index >= size) {
            return false;
        }
        if (index == 0) {
            head->next = head->next->next;
            return true;
        }

        auto temp_ptr = head;
        for (int i = 0; i < index; i++) {
            temp_ptr = temp_ptr->next;
        }
        temp_ptr->next = temp_ptr->next->next;
        return true;
    }

    bool LinkedList::contains(int val) {
        auto temp_ptr = head;
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next;
            if (temp_ptr->data == val) {
                return true;
            }
        }
        return false;
    }

    std::shared_ptr<Node> LinkedList::find(int val) {
        auto temp_ptr = head;
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next;
            if (temp_ptr->data == val) {
                return temp_ptr;
            }
        }
        return nullptr;
    }

    std::shared_ptr<Node> LinkedList::locate(int index) {
        auto temp_ptr = head->next;
        if (!temp_ptr) return nullptr;
        for (int i = 0; i < index; i++) {
            if (!temp_ptr) return nullptr;
            temp_ptr = temp_ptr->next;
        }
        return temp_ptr;
    }

    void LinkedList::print() {
        auto temp_ptr = head;
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next;
            std::cout << temp_ptr->data << '\t';
        }
        std::cout << std::endl;
    }

    bool LinkedList::isEmpty() {
        if (head->next == nullptr)
            return true;
        return false;
    }
} // datastructures
