#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to find the pivot and partition the array
int partition(int arr[], int low, int high, int pivotIndex) {
    // Move the pivot to the end
    int pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]); // Move pivot to end
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap the elements
        }
    }
    swap(&arr[i + 1], &arr[high]); // Swap the pivot element with the element at i + 1
    return (i + 1); // Return the partitioning index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Choose a pivot index (for simplicity, we can choose the last element)
        int pivotIndex = high; // Default pivot index is the last element
        int pi = partition(arr, low, high, pivotIndex); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array with user-defined size

    // Input the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input the pivot index
    int pivotIndex;
    printf("Enter the pivot index (0 to %d): ", n - 1);
    scanf("%d", &pivotIndex);

    // Validate pivot index
    if (pivotIndex < 0 || pivotIndex >= n) {
        printf("Invalid pivot index. Exiting.\n");
        return 1; // Exit with error
    }

    printf("Original array: \n");
    printArray(arr, n);

    // Perform Quick Sort using the user-defined pivot index
    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
