#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>      // std::length_error

using namespace std;

template <class T>
class PriorityQueue {
    private:
        struct Node {
            T data;
            int priority;
            Node *next;
            Node *last;
        };
        size_t size;
        Node *root;

    public:
        PriorityQueue() {
            this->size = 0;
            this->root = nullptr;
        }

        void insert(T data, int priority) {
            Node *node = new Node;
            node->data = data;
            node->priority = priority;
            node->next = this->root;
            node->last = nullptr;
            this->root = node;

            if (this->root->next != nullptr)
                this->root->next->last = this->root;

            this->size++;
        }

        void display() {
            for (Node *node = this->root; node != nullptr; node = node->next)
                cout << "{ " << node->last << " " << node << " " << node->next  << " }\t";
            cout << endl;
        }

        T pop() { // TODO: Take into account if the queue is empty.
            if (this->size == 0)
                throw length_error("Error: Queue cannot be empty.");

            this->size--;

            Node *max = this->root;
            Node *node;

            for (node = this->root; node != nullptr; node = node->next)
                if (max->priority < node->priority)
                    max = node;

            if (max == this->root) {
                this->root = this->root->next;
                if (this->root != nullptr) {
                    this->root->last = nullptr;
                }
            } else {
                max->last->next = max->next;
                max->next->last = max->last;
            }

            return max->data;
        }
};

#endif
