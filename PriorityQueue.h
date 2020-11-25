#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>

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
	/*********************************************************************
	*  Create a new instance of the PriorityQueue class by settings	     *
	*  the intialial size of the queue to 0 and setting the root node    *
	*  to empty.							     *
        *********************************************************************/
        PriorityQueue() {
            this->size = 0;
            this->root = nullptr;
        }

	/********************************************************************
	*  Insert a new data into the queue by simply setting it equal to   *
	*  the root. The data is NOT ordered by its priority score, however *
	*  the data will always be extracted according to their priority    *
	*  score.							    *
	*******************************************************************/
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

	/*******************************************************************
	*  Output a limited view of the queue to the screen. This method   *
	*  is for debugging purposes only.				   *
	*******************************************************************/
        void display() {
            for (Node *node = this->root; node != nullptr; node = node->next)
                cout << "{ " << node->last << " " << node << " " << node->next  << " }\t";
            cout << endl;
        }

	/********************************************************************
	*  Return and remove the element in the queue with the highest      *
	*  priority score. 						    *
	*								    *
	*  Items with the same priority score may not be extracted in any   *
	*  particular order.						    *
	*								    *
	*  Attempting to pop an item from an empty queue will result in a   *
	*  length_error being thrown.					    *
	********************************************************************/
        T pop() {
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
