#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heap[size] = value;
        size++;
        int index = size - 1;
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void deleteMax() {
        if (size == 0) return;
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void heapSort() {
        buildMaxHeap();
        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            size--;
            heapify(0);
        }
    }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxHeap maxHeap(n);

    for (int i = 0; i < n; i++) {
        maxHeap.insert(arr[i]);
    }

    cout << "Heap Sort Result: ";
    maxHeap.heapSort();
    maxHeap.printHeap();

    return 0;
}

