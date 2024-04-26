#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_HEAP_SIZE = 100;

// Min-Max Heap class
class MinMaxHeap {
private:
    int heap[MAX_HEAP_SIZE];
    int size;
    void minMaxHeapify(int i);

public:
    MinMaxHeap();
    void buildHeap();
    int findMin();
    int findMax();
    void insertHeap(int key);
    void deleteMin();
    void deleteMax();
};

//Initializing the heap
MinMaxHeap::MinMaxHeap() {
    size = 0;
}

//Sorting the Min-Max Heap
void MinMaxHeap::minMaxHeapify(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    // Check if left child is larger than root
    if (left <= size && heap[left] > heap[largest]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right <= size && heap[right] > heap[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]);
        minMaxHeapify(largest);
    }
}

//Building Min-Max Heap
void MinMaxHeap::buildHeap() {
    int n;
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
        size++;
    }
    for (int i = size / 2; i >= 1; i--) {
        minMaxHeapify(i);
    }
}

//Returns Minimum element
int MinMaxHeap::findMin() {
    return heap[1];
}

//Returns Maximum element
int MinMaxHeap::findMax() {
    if (size == 1) {
        return heap[1];
    } 
    else if (size == 2) {
        return max(heap[1], heap[2]);
    } 
    else {
        return max(heap[1], max(heap[2], heap[3]));
    }
}

//Inserts a new element into the min-max heap
void MinMaxHeap::insertHeap(int key) {
    if (size == MAX_HEAP_SIZE - 1) {
        cout << "Heap overflow" << endl;
        return;
    }
    size++;
    heap[size] = key;
    int i = size;
    while (i > 1 && heap[i / 2] > heap[i]) {
        swap(heap[i / 2], heap[i]);
        i = i / 2;
    }
}

//Deletes the minimum element
void MinMaxHeap::deleteMin() {
    if (size == 0) {
        cout << "Heap underflow" << endl;
        return;
    }
    heap[1] = heap[size];
    size--;
    minMaxHeapify(1);
}

//Deletes the maximum element
void MinMaxHeap::deleteMax() {
    if (size == 1) {
        delete heap[1];
    } 
    else if (size == 2) {
        delete max(heap[1], heap[2]);
    } 
    else {
        delete max(heap[1], max(heap[2], heap[3]));
    }
}

int main() {
    
    buildHeap();
    cout << "The Minimum Element in the max-min heap is =" << findMin();
    cout << "The Maximum Element in the max-min heap is =" << findMax();
    insertHeap();
    int x;
    cout << "If you want to delete the Minimum Element press 1 and enter." << endl;
    cout << "If you want to delete the Maximum Element press 2 and enter." << endl;
    cout << "If you don't want to delete any Element press anyother number and enter." << endl;
    cin >> x; 
    if (x == 1) {
        deleteMin();
        cout << "The Minimun Element has been deleted." << endl;
    }
    else if (x == 2) {
        deleteMax();
        cout << "The Maximum Element has been deleted." << endl;
    }
    else () {
        cout << "You chose not to delete any element" << endl;
    }

}