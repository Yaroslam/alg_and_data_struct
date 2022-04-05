#include <iostream>
using namespace std;

class Heap {
    int *heap;         // указатель на массив кучи
    int HeapSize; // размер кучи
public:
    Heap(int size) {
        heap = new int[size];
        HeapSize = 0;
    }

    void adelem(int n){
        int i, parent;
        i = HeapSize;
        heap[i] = n;
        parent = (i-1)/2;
        while(parent >= 0 && i > 0)  {
            if(heap[i] > heap[parent]) {
                int temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;
            }
            i = parent;
            parent = (i-1)/2;
        }
        HeapSize++;
    }


    void out(){
        for(int i=0; i< HeapSize; i++) {
            cout << heap[i] << " "; }
        cout << endl;
    }


    void heapify(int size, int i)
    {
        int largest = i;
        int l = 2*i + 1; // левый = 2*i + 1
        int r = 2*i + 2; // правый = 2*i + 2

        if (l < size && heap[l] > heap[largest])
            largest = l;

        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(size,largest);
        }
    }

    int getmax(){
        int x;
        x = heap[0];
        heap[0] = heap[HeapSize - 1];
        HeapSize--;
        heapify(HeapSize, 0);
        return(x);
    }


    void heap_sort(){
        for (int i = HeapSize / 2 - 1; i >= 0; i--){
            heapify(HeapSize,i);
        }
        for (int i=HeapSize-1; i>=0; i--)
        {
            swap(heap[0], heap[i]);
            this->out();
            heapify(i ,0);
        }
    }
};
