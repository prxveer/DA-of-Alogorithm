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

    void deleteElement(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Element not found in the heap." << endl;
            return;
        }

        heap[index] = heap[size - 1];
        size--;
        heapify(index);
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(50);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(10);
    maxHeap.insert(8);

    cout << "Original Heap: ";
    maxHeap.printHeap();

    int valueToDelete = 20;
    cout << "Deleting " << valueToDelete << " from the heap." << endl;
    maxHeap.deleteElement(valueToDelete);

    cout << "Heap after deletion: ";
    maxHeap.printHeap();

    return 0;
}

