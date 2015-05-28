class MaxHeap {
    private:
        int* heap;
        int heapSize;
        int capacity;

    public:
        MaxHeap(int maxCapacity = 10);
        ~MaxHeap();

        bool isEmpty();
        void push(int item);
        void pop();
        void deleteHeap(int order);
        void printTop();
        void printOrder(int order);
        void print();
};
