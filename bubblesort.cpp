#include <iostream>
#include <utility> // For std::swap

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    // Outer loop runs for each pass
    for (int step = 0; step < size - 1; ++step) {
        bool swapped = false; // Track if a swap occurs in this pass
        
        // Inner loop compares adjacent elements
        for (int i = 0; i < size - step - 1; ++i) {
            // Swap if elements are in the wrong order (ascending)
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true; // Mark that a swap took place
            }
        }
        
        // If no two elements were swapped by the inner loop, the array is sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to display array content
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    std::cout << "Original Array:\n";
    printArray(data, size);
    
    bubbleSort(data, size);
    
    std::cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
    
    return 0;
}
