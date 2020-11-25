#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class PriorityQueue {
    private:
        struct Node {
            T data;
            int priority;
            Node *next;
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
            this->root = node;
        }

        void display() {
            for (Node *node = this->root; node != nullptr; node = node->next)
                cout << "{ " << node << " " << node->data << " }\t";
            cout << endl;
        }

        T pop() {
            Node *max = this->root;
            Node *node;

            for (node = this->root; node != nullptr; node = node->next)
                if (max->priority < node->priority)
                    max = node;

            for (node = this->root; node->next != max; node = node->next);

            node->next = max->next;

            return max->data;
        }
};

#endif
