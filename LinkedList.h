#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int value = 0, Node* next = nullptr) : value(value), next(next) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    void Append(int x) {
        Node* newNode = new Node();

        // Empty List Checks
        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }
    }
    int Pop() {
        if (head == nullptr) return -1;     // Empty List Check

        int returnVal = tail->value;
        Node* newHead = head->next;

        delete head;
        head = newHead;

        return returnVal;
    }
    std::string GetList() {
        if (head == nullptr) {              // Empty List Check
            return "Empty\n";
        }

        std::string ret = "";
        Node* currNode = head;
        while (currNode != nullptr) {
            ret = std::to_string(currNode->value);
            ret = "\n";
            currNode = currNode->next;
        }

        return ret;
    }
};

#endif