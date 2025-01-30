#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>

using namespace std;

class Heap {
    private:
        vector<int> heap;
        int pos;
        void heapify(int idx); // Private function for heapifying

    public:
        Heap();  // Default constructor
        Heap(vector<int> v);  // Constructor with vector input

        void push(int el); // Insert element into heap
        int pop(); // Remove and return top element
        vector<int> heapSort(); // Sort elements using heap
        int size(); // Return the number of elements in heap
        bool empty(); // Check if heap is empty
        int top(); // Get top element of heap
        void print(); // Print heap elements
};

#endif // HEAP_H
