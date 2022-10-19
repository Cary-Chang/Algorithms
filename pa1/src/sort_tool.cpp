// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include <limits.h>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int j = 1; j < data.size(); j++) {
        int key = data[j];
        int i = j - 1;
        while (data[i] > key && i >= 0) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = key;
        // cout << "1111" << endl;
    }
    // cout << "000000000000000" << endl;
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if (low < high) {
        int middle = Partition(data, low, high);
        QuickSortSubVector(data, low, middle - 1);
        QuickSortSubVector(data, middle + 1, high);
    }
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int key = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j] <= key) {
            i++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    int temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;
    return i + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (low < high) {
        int middle = (low + high) / 2;
        MergeSortSubVector(data, low, middle);
        MergeSortSubVector(data, middle + 1, high);
        Merge(data, low, middle, middle + 1, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> left(middle1 - low + 2);
    vector<int> right(high - middle2 + 2);
    for (int i = 0; i < left.size() - 1; i++) 
        left[i] = data[low + i];
    for (int i = 0; i < right.size() - 1; i++)
        right[i] = data[middle2 + i];
    left[left.size() - 1] = INT_MAX;
    right[right.size() - 1] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k = low; k < high + 1; k++) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        }
        else {
            data[k] = right[j];
            j++;
        }
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int leftIndex = 2 * (root + 1) - 1;
    int rightIndex = 2 * (root + 1);
    int maxIndex;
    if (leftIndex < heapSize && data[leftIndex] > data[root])
        maxIndex = leftIndex;
    else
        maxIndex = root;
    if (rightIndex < heapSize && data[rightIndex] > data[maxIndex])
        maxIndex = rightIndex;
    if (maxIndex != root) {
        int temp = data[maxIndex];
        data[maxIndex] = data[root];
        data[root] = temp;
        MaxHeapify(data, maxIndex);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for (int i = (data.size() / 2) - 1; i >= 0; i--)
        MaxHeapify(data, i);
}
