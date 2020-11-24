#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class PriorityQueue {
    private:
        size_t size;
        struct Node { T data; int priority; Node *right; Node *left; Node *parent; };

        Node *insert(Node *node, T data, int priority) {
            if (node == nullptr) {
                node = new Node();
                node->data = data;
                node->priority = priority;
                node->right = nullptr;
                node->left = nullptr;
                node->parent = nullptr;
            } else if (node->priority >= priority) {
                node->right = insert(node->right, data, priority);
                node->right->parent = node;
            } else {
                node->left = insert(node->left, data, priority);
                node->left->parent = node;
            }

            return node;
        }
    
    public:
        Node *root;

        PriorityQueue() {
            this->size = 0;
            this->root = nullptr;
        }

        size_t getSize() {
            return this->size;
        }

        void insert(T data,  int priority) {
            this->root = insert(this->root, data, priority);
            this->size++;
        }
};

#endif
