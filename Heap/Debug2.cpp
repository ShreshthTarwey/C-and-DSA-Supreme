#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Function to heapify the max-heap
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function to insert an element into the max heap
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    int n = heap.size();
    int i = n - 1;
    
    // Reheapify upwards
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

// Function to remove all even numbers from the heap
void removeEvenNumbers(vector<int>& heap) {
    vector<int> temp;
    
    // First extract all elements from the heap and push only odd elements into temp
    while (!heap.empty()) {
        int root = heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        
        if (root % 2 != 0) {
            temp.push_back(root);
        }
    }

    // Insert the remaining odd elements back into the heap
    for (int val : temp) {
        insert(heap, val);
    }
}

// Main function
int main() {
    int n;
    cin >> n;
    
    vector<int> heap;
    
    // Read input and build the heap
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(heap, x);
    }
    
    // Remove all even numbers from the heap
    removeEvenNumbers(heap);
    
    // Print the remaining elements in the heap
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
    
    return 0;
}
