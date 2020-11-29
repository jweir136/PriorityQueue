# PriorityQueue

## About

According to [Wikipedia](https://en.wikipedia.org/wiki/Priority_queue),

> In computer science, a priority queue is an abstract data type similar to a regular queue or stack data structure in which each element additionally has a "priority"
> associated with it. In a priority queue, an element with high priority is served before an element with low priority. In some implementations, if two elements have the
> same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is
> undefined.

This particular implementation makes use of a *doubly-linked list* in order to store all the elements. The elements are not stored in any particular order, however when
the elements are returned the one with the highest priority is given. Elements with the same priority score are not garenteed to be returned in any particular order.

## Usage

In order to add the *priority queue* class to your project, instruct the linker to add the ```PriorityQueue.h``` source files.

    #include "PriorityQueue.h"

To create an instance of the object, simply initialize it as you would any generic class in c++17. The constructor does not take any arguments.

    PriorityQueue<int> queue; // NOTE: 'datatype' is to be replaced with the type of the Queue's elements.
    
A *PriorityQueue* has only 3 methods: *insert*, *pop*, and *getSize*.

### *insert* method

    void insert(T item, int priority);

The *insert* method is used to add an element to the queue object. Since the *PriorityQueue* has a generic implementation, it is assumed that the type of the
given element matches the type passed to the class' constructor. Failure to follow the standard rules regarding the usage of generic objects will result in a compile-time
error. 

The method requires 2 arguments to be passed: the item and the priority of the item. The item is the actual data to be added to the queue, while the priority is an integer
used to represent the "urgency" by which the element is given. The higher the priority, the more urgent an element is considered. More urgent items are returned before
less urgent ones. Please note that elements are not stored in any particular order, however the are returned by their priority.

    queue.insert(1, 1);
    queue.insert(2, 0);
    queue.insert(3, -1); // negative priority scores are allowed
    
## *pop* method

    T pop();
    
The *pop* method is used to return the next element in the priority queue. The next element is the element with the highest priority score in the queue.
In the likely event that the there is a tie in the highest priority score, the next element is not always the most recently added element. A ```length_error``` is raised
when *pop* is called and the queue is empty (this is considered a runtime error, not a compile-time error).

    cout << queue.pop() << endl;

## *getSize* method

    size_t getSize();
    
The *getSize* method simply just returns the number of elements in the queue. This method is useful for avoiding the above-mentioned ```length_error```.

    cout << "There are " << queue.getSize() << " elements in the queue." << endl;
   
