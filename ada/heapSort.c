#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the heap property (0-indexed)
void heapify(int A[], int n, int i) {
    int k = i;
    int v = A[i];
    int heap = 0; // false
    
    while (2*k + 1 < n && !heap) {
        int j = 2*k + 1; // left child (0-indexed)
        
        // Compare left and right children
        if (j + 1 < n) {
            if (A[j] < A[j+1]) {
                j = j + 1; // right child if larger
            }
        }
        
        // Check if heap property is satisfied
        if (v >= A[j]) {
            heap = 1; // true
        } else {
            A[k] = A[j];
            k = j;
        }
    }
    A[k] = v;
}

// Heap Sort function (0-indexed)
void heapSort(int A[], int n) {
    // Build heap (rearrange array)
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
    
    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    heapSort(arr, n);
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
