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
