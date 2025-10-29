//
// Created by Benson on 2025/10/24.
//

#include "../../include/datastructures/linked_list.hpp"

#include <climits>
#include <iostream>

namespace datastructures {
    LinkedList::LinkedList() {
        head = std::make_unique<Node>(INT_MIN);
    }

    LinkedList::LinkedList(int val) {
        head = std::make_unique<Node>(INT_MIN);
        push_back(val);
    }

    int LinkedList::length() {
        int length = 0;
        Node* temp_ptr = head.get(); //获取裸指针
        while (temp_ptr->next) {
            length++;
            temp_ptr = temp_ptr->next.get();
        }
        return length;
    }

    void LinkedList::push_front(int val) {
        auto new_first = std::make_unique<Node>(val);
        new_first->next = std::move(head->next);
        head->next = std::move(new_first);
    }

    void LinkedList::push_back(int val) {
        auto new_last = std::make_unique<Node>(val);
        Node* temp_ptr = head.get(); //获取裸指针
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next.get();
        }
        temp_ptr->next = std::move(new_last);
    }

    bool LinkedList::removeByValue(int value) {
        Node* temp_ptr = head.get();
        while (temp_ptr->next) {
            if (temp_ptr->next->data == value) {
                auto d_node = std::move(temp_ptr->next);
                temp_ptr->next = std::move(d_node->next);
                //智能指针自动管理内存，不需要手动释放
                return true;
            }
            temp_ptr = temp_ptr->next.get();
        }
        return false;
    }

    bool LinkedList::removeByIndex(int index) {
        int size = length();
        if (index < 0 || index >= size) {
            return false;
        }
        if (index == 0) {
            head->next = std::move(head->next->next);
            return true;
        }

        Node* temp_ptr = head.get();
        for (int i = 0; i < index; i++) {
            temp_ptr = temp_ptr->next.get();
        }
        temp_ptr->next = std::move(temp_ptr->next->next);
        return true;
    }

    bool LinkedList::contains(int val) {
        Node* temp_ptr = head.get();
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next.get();
            if (temp_ptr->data == val) {
                return true;
            }
        }
        return false;
    }

    Node* LinkedList::find(int val) {
        Node* temp_ptr = head.get();
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next.get();
            if (temp_ptr->data == val) {
                return temp_ptr;
            }
        }
        return nullptr;
    }

    Node* LinkedList::locate(int index) {
        Node* temp_ptr = head->next.get();
        for (int i = 0; i < index; i++) {
            temp_ptr = temp_ptr->next.get();
        }
        return temp_ptr;
    }

    void LinkedList::print() {
        Node* temp_ptr = head.get();
        while (temp_ptr->next) {
            temp_ptr = temp_ptr->next.get();
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
