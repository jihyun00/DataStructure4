#include <iostream>
#include <stdlib.h>
#include <string>
#include "maxheap.h"

using namespace std;

MaxHeap::MaxHeap(int maxCapacity) {
    capacity = maxCapacity;
    heapSize = 0;
    heap = new int[capacity+1];
}


MaxHeap::~MaxHeap() {
    delete[] heap;
}


bool MaxHeap::isEmpty() {
    return (heapSize == 0);
}


void MaxHeap::push(int item) {
    if(heapSize == capacity) {
        int* heap = new int[capacity];
        capacity *= 2;
    }

    int current = ++heapSize;
    while(current != 1 && heap[current/2] < item) {
        heap[current] = heap[current/2];
        current /= 2;
    }

    heap[current] = item;
    
    cout << "done" << endl; // when success to insert 
}


void MaxHeap::pop() {
    if(isEmpty() == true) {
        cout << "error" << endl;
        return;
    }
    heap[1] = NULL;

    int last = heap[heapSize--];

    int current = 1;
    int child = 2;
    while(child <= heapSize) {
        if(child < heapSize && heap[child] < heap[child+1]) {
            child++;
        }

        if(last >= heap[child]) {
            break;
        }

        heap[current] = heap[child];
        current = child;
        child *= 2;

    }

    heap[current] = last;

    cout << "done" << endl;
}


void MaxHeap::deleteHeap(int order) {
    if(order > heapSize) {
        cout << "error" << endl;
        return;
    }

    heap[order] = NULL;

    int last = heap[heapSize--];
    int current = order;
    int child = order+1;
    while(child <= heapSize) {
        if(child < heapSize && heap[child] < heap[child+1]) {
            child++;
        }

        if(last >= heap[child]) {
            break;
        }

        heap[current] = heap[child];
        current = child;
        child *= 2;

    }

    heap[current] = last;
    
    cout << "done" << endl;
}


void MaxHeap::printTop() {
    if(isEmpty() == true) {
        cout << "error" << endl;
        return;
    }

    cout << heap[1] << endl;
}


void MaxHeap::printOrder(int order) {
    if(order > heapSize) {
        cout << "error" << endl;
        return;
    }

    if(order%2 == 0) {
        if(heap[order] < heap[order+1]) {
            cout << heap[order+1] << endl;

        } else {
            cout << heap[order] << endl; 
        }
    } else {
        if(heap[order] < heap[order-1]) {
            cout << heap[order-1] << endl;

        } else {
            cout << heap[order] << endl; 
        }
    }
}


void MaxHeap::print() {
    if(isEmpty() == true) {
        cout << "error" << endl;
        return;
    }

    for(int i = 1; i < heapSize+1; i++) {
        cout << heap[i] << " ";        
    }

    cout << endl;
}
